#include <HardwareSerial.h>
#include <WiFi.h>
#include <PubSubClient.h> // Biblioteca MQTT

const char* ssid = "Weneamechioinasuma";
const char* password = "244466666";
const char* mqtt_server = "193.137.172.20"; // Endereço do servidor MQTT
const int mqtt_port = 85;
const char* mqtt_topic = "qr_codes";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Conexão WiFi estabelecida");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  // Lida com mensagens recebidas (se necessário)
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando se reconectar ao servidor MQTT...");
    if (client.connect("ESP8266Client")) {
      Serial.println("Conectado");
    } else {
      Serial.print("Falhou, rc=");
      Serial.print(client.state());
      Serial.println("Tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(9600);  // Inicializa a comunicação serial
  Serial2.begin(9600, SERIAL_8N1, 16, 17); // Inicializa a comunicação serial 2 (Pistola QR)

  setup_wifi(); // Configura a conexão WiFi

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Lê dados da pistola QR
  if (Serial2.available() > 0) {
    String qrData = Serial2.readStringUntil('\n'); // Lê os dados da pistola QR
    Serial.println("Código QR lido: " + qrData);
    
    // Envia o código QR lido para o servidor MQTT
    if (client.publish(mqtt_topic, qrData.c_str())) {
      Serial.println("Código QR enviado para o servidor MQTT");
    } else {
      Serial.println("Falha ao enviar código QR para o servidor MQTT");
    }
  }

  delay(1000);
}