#include <WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>

// Configurações de rede
const char* ssid     = "Weneamechioinasuma";
const char* password = "244466666";

// Configurações do servidor RFID
const char* rfidIp = "193.137.172.20";
const int rfidPort = 88; // Porta de comunicação do RFID

// Configurações do servidor MQTT
const char* mqtt_server = "193.137.172.20"; // Endereço do servidor MQTT
const int mqtt_port = 85; // Porta do servidor MQTT
const char* mqtt_topic = "rfid"; // Tópico MQTT para enviar a resposta do RFID

// Código hexadecimal a ser enviado
unsigned char hexCode[] = {0x01, 0x46, 0x46, 0x05, 0x05, 0x0D};

// Inicializa objetos WiFiClient e PubSubClient
WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando ao WiFi...");
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Conectado ao WiFi com sucesso!");
}

void callback(char* topic, byte* payload, unsigned int length) {
  // Lida com mensagens recebidas (se necessário)
}

void reconnect() {
  // Loop até que esteja conectado ao servidor MQTT
  while (!client.connected()) {
    Serial.print("Conectando ao servidor MQTT...");
    // Tenta se conectar ao servidor MQTT
    if (client.connect("ESP8266Client")) {
      Serial.println("Conectado ao servidor MQTT!");
    } else {
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos...");
      // Aguarda 5 segundos antes de tentar novamente
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port); // Configura o servidor MQTT e a porta
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  static unsigned long lastAttemptTime = 0;
  unsigned long now = millis();
  
  if (now - lastAttemptTime > 5000) { // Tenta conectar ao RFID a cada 5 segundos
    lastAttemptTime = now;
    
    WiFiClient rfidClient;
    if (!rfidClient.connected()) {
      Serial.println("Conectando ao RFID...");
      if (rfidClient.connect(rfidIp, rfidPort)) {
        Serial.println("Conectado ao RFID!");
        // Envio do código hexadecimal
        rfidClient.write(hexCode, 6);
        Serial.println("Código enviado ao RFID.");
        delay(10000); // Espera para o RFID processar o código 
        String response = "";
        while (rfidClient.available()) {
          // Leitura da resposta do RFID
          char c = rfidClient.read();
          response += c;
        }
        if (response.length() > 0) {
          Serial.println("Resposta do RFID:");
          Serial.println(response);
          // Publica a resposta do RFID no servidor MQTT
          if (client.publish(mqtt_topic, response.c_str())) {
            Serial.println("Resposta enviada ao servidor MQTT.");
          } else {
            Serial.println("Falha ao enviar a resposta ao servidor MQTT.");
          }
        } else {
          Serial.println("Nenhuma resposta do RFID recebida.");
        }
        rfidClient.stop(); // Encerra a conexão com o RFID
      } else {
        Serial.println("Falha ao conectar ao RFID!");
      }
    }
  }
}
