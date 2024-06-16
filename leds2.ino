#include <WiFi.h>
#include <PubSubClient.h>

// Replace the next variables with your SSID/Password combination
const char* ssid = "EletroWIFI";
const char* password = "12345678";

// Add your MQTT Broker IP address, example:
const char* mqtt_server = "193.137.172.20";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;
String state = "";



// LED Pin
const int ledPin = 15;
const int ledPin1 = 2;
const int ledPin2 = 0;
const int ledPin3 = 4;
const int ledPin4 = 16;
const int ledPin5 = 17;
const int ledPin6 = 5;
const int ledPin7 = 18;
const int ledPin8 = 19;
const int ledPin9 = 21;
const int ledPin10 = 22;
// not sure if needed
const int ledPin11 = 23;
const int ledPin12 = 34;

const int ledPin13 = 12;
const int ledPin14 = 14;
const int ledPin15 = 27;
const int ledPin16 = 26;
const int ledPin17 = 25;
const int ledPin18 = 33;
const int ledPin19 = 32;
// not sure if needed
const int ledPin20 = 13;

//1 posto
const char* Start1 = "Start1";
const char* SuporteMatricula = "SuporteMatricula";
const char* CalipersR = "CalipersR";
const char* RodaR = "RodaR";
const char* Escora = "Escora";
const char* Postoassento = "Postoassento";
const char* CalipersF = "CalipersF";
const char* RodaF = "RodaF";
const char* Forquilha = "Forquilha";
const char* ApoioGuiador = "ApoioGuiador";
const char* ManeteTravao = "ManeteTravao";
const char* Acelerador = "Acelerador";
const char* Guiador = "Guiador";
// 2 posto
const char* Start2 = "Start2";
const char* Selim = "Selim";
const char* FarolR = "FarolR";
const char* Controlador = "Controlador";
const char* Bateria = "Bateria";
const char* Interruptor = "Interruptor";
const char* Display = "Display";
const char* Mirrors = "Mirrors";
const char* FarolF = "FarolF";

void setup() {
  Serial.begin(115200);
 
  setup_wifi();
  client.setServer(mqtt_server, 85);
  client.setCallback(callback);

  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin10, OUTPUT);
  pinMode(ledPin11, OUTPUT);
  pinMode(ledPin12, INPUT);
  pinMode(ledPin13, OUTPUT);
  pinMode(ledPin14, OUTPUT);
  pinMode(ledPin15, OUTPUT);
  pinMode(ledPin16, OUTPUT);
  pinMode(ledPin17, OUTPUT);
  pinMode(ledPin18, OUTPUT);
  pinMode(ledPin19, OUTPUT);
  pinMode(ledPin20, OUTPUT);
  //digitalWrite(4,HIGH);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  
  // If a message is received on the topic esp32_103268/leds, you check if the message is either "on" or "off". 
  // Changes the output state according to the message
  if (String(topic) == "esp32_103268/leds") {
    Serial.print("Changing output to ");
    if (messageTemp == Start1) {
        digitalWrite(ledPin,HIGH);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        digitalWrite(ledPin11,LOW);
        digitalWrite(ledPin12,LOW);
        // digitalWrite(ledPin13,LOW);
        // digitalWrite(ledPin14,LOW);
        // digitalWrite(ledPin15,LOW);
        // digitalWrite(ledPin16,LOW);
        // digitalWrite(ledPin17,LOW);
        // digitalWrite(ledPin18,LOW);
        // digitalWrite(ledPin19,LOW);
        // digitalWrite(ledPin20,LOW);
        state = "Suporte da matricula";
        }
    else if (messageTemp == SuporteMatricula) {
        digitalWrite(ledPin,LOW);
        digitalWrite(ledPin1,HIGH);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        digitalWrite(ledPin11,LOW);
        digitalWrite(ledPin12,LOW);
        // digitalWrite(ledPin13,LOW);
        // digitalWrite(ledPin14,LOW);
        // digitalWrite(ledPin15,LOW);
        // digitalWrite(ledPin16,LOW);
        // digitalWrite(ledPin17,LOW);
        // digitalWrite(ledPin18,LOW);
        // digitalWrite(ledPin19,LOW);
        // digitalWrite(ledPin20,LOW);
        state = "Calipers traseiros a ser instalado ";
        }
    else if (messageTemp == CalipersR) {
        digitalWrite(ledPin,LOW);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,HIGH);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        digitalWrite(ledPin11,LOW);
        digitalWrite(ledPin12,LOW);
        // digitalWrite(ledPin13,LOW);
        // digitalWrite(ledPin14,LOW);
        // digitalWrite(ledPin15,LOW);
        // digitalWrite(ledPin16,LOW);
        // digitalWrite(ledPin17,LOW);
        // digitalWrite(ledPin18,LOW);
        // digitalWrite(ledPin19,LOW);
        // digitalWrite(ledPin20,LOW);
        state = "Roda traseira a ser instalados";
        }
    else if (messageTemp == RodaR){
        digitalWrite(ledPin,LOW);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,HIGH);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        digitalWrite(ledPin11,LOW);
        digitalWrite(ledPin12,LOW);
        // digitalWrite(ledPin13,LOW);
        // digitalWrite(ledPin14,LOW);
        // digitalWrite(ledPin15,LOW);
        // digitalWrite(ledPin16,LOW);
        // digitalWrite(ledPin17,LOW);
        // digitalWrite(ledPin18,LOW);
        // digitalWrite(ledPin19,LOW);
        // digitalWrite(ledPin20,LOW);

        state = "EScora a ser instalado";
        }
    else if (messageTemp == Escora){
        digitalWrite(ledPin,LOW);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,HIGH);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        digitalWrite(ledPin11,LOW);
        digitalWrite(ledPin12,LOW);
        // digitalWrite(ledPin13,LOW);
        // digitalWrite(ledPin14,LOW);
        // digitalWrite(ledPin15,LOW);
        // digitalWrite(ledPin16,LOW);
        // digitalWrite(ledPin17,LOW);
        // digitalWrite(ledPin18,LOW);
        // digitalWrite(ledPin19,LOW);
        // digitalWrite(ledPin20,LOW);
        state = "pau do assento a ser instalado";
        }
    else if (messageTemp == Postoassento){
        digitalWrite(ledPin,LOW);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,HIGH);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        digitalWrite(ledPin11,LOW);
        digitalWrite(ledPin12,LOW);
        // digitalWrite(ledPin13,LOW);
        // digitalWrite(ledPin14,LOW);
        // digitalWrite(ledPin15,LOW);
        // digitalWrite(ledPin16,LOW);
        // digitalWrite(ledPin17,LOW);
        // digitalWrite(ledPin18,LOW);
        // digitalWrite(ledPin19,LOW);
        // digitalWrite(ledPin20,LOW);
        state = "Calipers da frente a ser instalado";
        }
    else if (messageTemp == CalipersF){
        digitalWrite(ledPin,LOW);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,HIGH);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        digitalWrite(ledPin11,LOW);
        digitalWrite(ledPin12,LOW);
        // digitalWrite(ledPin13,LOW);
        // digitalWrite(ledPin14,LOW);
        // digitalWrite(ledPin15,LOW);
        // digitalWrite(ledPin16,LOW);
        // digitalWrite(ledPin17,LOW);
        // digitalWrite(ledPin18,LOW);
        // digitalWrite(ledPin19,LOW);
        // digitalWrite(ledPin20,LOW);
        state = "Roda traseira a ser instalado";
        }
    else if (messageTemp == RodaF){
        digitalWrite(ledPin,LOW);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,HIGH);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        digitalWrite(ledPin11,LOW);
        digitalWrite(ledPin12,LOW);
        // digitalWrite(ledPin13,LOW);
        // digitalWrite(ledPin14,LOW);
        // digitalWrite(ledPin15,LOW);
        // digitalWrite(ledPin16,LOW);
        // digitalWrite(ledPin17,LOW);
        // digitalWrite(ledPin18,LOW);
        // digitalWrite(ledPin19,LOW);
        // digitalWrite(ledPin20,LOW);
        state = "forquilha a ser instalado";
        }
    else if (messageTemp == Forquilha){
        digitalWrite(ledPin,LOW);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,HIGH);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        digitalWrite(ledPin11,LOW);
        digitalWrite(ledPin12,LOW);
        // digitalWrite(ledPin13,LOW);
        // digitalWrite(ledPin14,LOW);
        // digitalWrite(ledPin15,LOW);
        // digitalWrite(ledPin16,LOW);
        // digitalWrite(ledPin17,LOW);
        // digitalWrite(ledPin18,LOW);
        // digitalWrite(ledPin19,LOW);
        // digitalWrite(ledPin20,LOW);
        state = "apoio do guiador a ser instalado";
        }
    else if (messageTemp == ApoioGuiador){
        digitalWrite(ledPin,LOW);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,HIGH);
        digitalWrite(ledPin10,LOW);
        digitalWrite(ledPin11,LOW);
        digitalWrite(ledPin12,LOW);
        // digitalWrite(ledPin13,LOW);
        // digitalWrite(ledPin14,LOW);
        // digitalWrite(ledPin15,LOW);
        // digitalWrite(ledPin16,LOW);
        // digitalWrite(ledPin17,LOW);
        // digitalWrite(ledPin18,LOW);
        // digitalWrite(ledPin19,LOW);
        // digitalWrite(ledPin20,LOW);
        state = "Manete do travao a ser instalado";
        }
    else if (messageTemp == ManeteTravao){
        digitalWrite(ledPin,LOW);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,HIGH);
        digitalWrite(ledPin11,LOW);
        digitalWrite(ledPin12,LOW);
        // digitalWrite(ledPin13,LOW);
        // digitalWrite(ledPin14,LOW);
        // digitalWrite(ledPin15,LOW);
        // digitalWrite(ledPin16,LOW);
        // digitalWrite(ledPin17,LOW);
        // digitalWrite(ledPin18,LOW);
        // digitalWrite(ledPin19,LOW);
        // digitalWrite(ledPin20,LOW);
        state = "Acelerador a ser instalado";
        }
    else if (messageTemp == Acelerador){
        digitalWrite(ledPin,LOW);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        digitalWrite(ledPin11,HIGH);
        digitalWrite(ledPin12,LOW);
        // digitalWrite(ledPin13,LOW);
        // digitalWrite(ledPin14,LOW);
        // digitalWrite(ledPin15,LOW);
        // digitalWrite(ledPin16,LOW);
        // digitalWrite(ledPin17,LOW);
        // digitalWrite(ledPin18,LOW);
        // digitalWrite(ledPin19,LOW);
        // digitalWrite(ledPin20,LOW);
        state = "Guiador a ser instalado";
        }
    else if (messageTemp == Guiador){
        digitalWrite(ledPin,LOW);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        digitalWrite(ledPin11,LOW);
        digitalWrite(ledPin12,LOW);
        // digitalWrite(ledPin13,LOW);
        // digitalWrite(ledPin14,LOW);
        // digitalWrite(ledPin15,LOW);
        // digitalWrite(ledPin16,LOW);
        // digitalWrite(ledPin17,LOW);
        // digitalWrite(ledPin18,LOW);
        // digitalWrite(ledPin19,LOW);
        // digitalWrite(ledPin20,LOW);
        state = "Transição de posto";
      }
    else if (messageTemp == Start2){
        // digitalWrite(ledPin,LOW);
        // digitalWrite(ledPin1,LOW);
        // digitalWrite(ledPin2,LOW);
        // digitalWrite(ledPin3,LOW);
        // digitalWrite(ledPin4,LOW);
        // digitalWrite(ledPin5,LOW);
        // digitalWrite(ledPin6,LOW);
        // digitalWrite(ledPin7,LOW);
        // digitalWrite(ledPin8,LOW);
        // digitalWrite(ledPin9,LOW);
        // digitalWrite(ledPin10,LOW);
        // digitalWrite(ledPin11,LOW);
        // digitalWrite(ledPin12,LOW);
        digitalWrite(ledPin13,HIGH);
        digitalWrite(ledPin14,LOW);
        digitalWrite(ledPin15,LOW);
        digitalWrite(ledPin16,LOW);
        digitalWrite(ledPin17,LOW);
        digitalWrite(ledPin18,LOW);
        digitalWrite(ledPin19,LOW);
        digitalWrite(ledPin20,LOW);
        state = "Selim a ser instalado";
        }
    else if (messageTemp == Selim){
        // digitalWrite(ledPin,LOW);
        // digitalWrite(ledPin1,LOW);
        // digitalWrite(ledPin2,LOW);
        // digitalWrite(ledPin3,LOW);
        // digitalWrite(ledPin4,LOW);
        // digitalWrite(ledPin5,LOW);
        // digitalWrite(ledPin6,LOW);
        // digitalWrite(ledPin7,LOW);
        // digitalWrite(ledPin8,LOW);
        // digitalWrite(ledPin9,LOW);
        // digitalWrite(ledPin10,LOW);
        // digitalWrite(ledPin11,LOW);
        // digitalWrite(ledPin12,LOW);
        digitalWrite(ledPin13,LOW);
        digitalWrite(ledPin14,HIGH);
        digitalWrite(ledPin15,LOW);
        digitalWrite(ledPin16,LOW);
        digitalWrite(ledPin17,LOW);
        digitalWrite(ledPin18,LOW);
        digitalWrite(ledPin19,LOW);
        digitalWrite(ledPin20,LOW);
        state = "Farol traseiro a ser instalado";
        }
    else if (messageTemp == FarolR){
        // digitalWrite(ledPin,LOW);
        // digitalWrite(ledPin1,LOW);
        // digitalWrite(ledPin2,LOW);
        // digitalWrite(ledPin3,LOW);
        // digitalWrite(ledPin4,LOW);
        // digitalWrite(ledPin5,LOW);
        // digitalWrite(ledPin6,LOW);
        // digitalWrite(ledPin7,LOW);
        // digitalWrite(ledPin8,LOW);
        // digitalWrite(ledPin9,LOW);
        // digitalWrite(ledPin10,LOW);
        // digitalWrite(ledPin11,LOW);
        // digitalWrite(ledPin12,LOW);
        digitalWrite(ledPin13,LOW);
        digitalWrite(ledPin14,LOW);
        digitalWrite(ledPin15,HIGH);
        digitalWrite(ledPin16,LOW);
        digitalWrite(ledPin17,LOW);
        digitalWrite(ledPin18,LOW);
        digitalWrite(ledPin19,LOW);
        digitalWrite(ledPin20,LOW);
        state = "Controlador a ser instalado";
        }
    else if (messageTemp == Controlador){
        // digitalWrite(ledPin,LOW);
        // digitalWrite(ledPin1,LOW);
        // digitalWrite(ledPin2,LOW);
        // digitalWrite(ledPin3,LOW);
        // digitalWrite(ledPin4,LOW);
        // digitalWrite(ledPin5,LOW);
        // digitalWrite(ledPin6,LOW);
        // digitalWrite(ledPin7,LOW);
        // digitalWrite(ledPin8,LOW);
        // digitalWrite(ledPin9,LOW);
        // digitalWrite(ledPin10,LOW);
        // digitalWrite(ledPin11,LOW);
        // digitalWrite(ledPin12,LOW);
        digitalWrite(ledPin13,LOW);
        digitalWrite(ledPin14,LOW);
        digitalWrite(ledPin15,LOW);
        digitalWrite(ledPin16,HIGH);
        digitalWrite(ledPin17,LOW);
        digitalWrite(ledPin18,LOW);
        digitalWrite(ledPin19,LOW);
        digitalWrite(ledPin20,LOW);
        state = "Bateria a ser instalado";
        }
    else if (messageTemp == Bateria){
        // digitalWrite(ledPin,LOW);
        // digitalWrite(ledPin1,LOW);
        // digitalWrite(ledPin2,LOW);
        // digitalWrite(ledPin3,LOW);
        // digitalWrite(ledPin4,LOW);
        // digitalWrite(ledPin5,LOW);
        // digitalWrite(ledPin6,LOW);
        // digitalWrite(ledPin7,LOW);
        // digitalWrite(ledPin8,LOW);
        // digitalWrite(ledPin9,LOW);
        // digitalWrite(ledPin10,LOW);
        // digitalWrite(ledPin11,LOW);
        // digitalWrite(ledPin12,LOW);
        digitalWrite(ledPin13,LOW);
        digitalWrite(ledPin14,LOW);
        digitalWrite(ledPin15,LOW);
        digitalWrite(ledPin16,LOW);
        digitalWrite(ledPin17,HIGH);
        digitalWrite(ledPin18,LOW);
        digitalWrite(ledPin19,LOW);
        digitalWrite(ledPin20,LOW);
        state = "Interruptor a ser instalado";
        }
    else if (messageTemp == Interruptor){
        // digitalWrite(ledPin,LOW);
        // digitalWrite(ledPin1,LOW);
        // digitalWrite(ledPin2,LOW);
        // digitalWrite(ledPin3,LOW);
        // digitalWrite(ledPin4,LOW);
        // digitalWrite(ledPin5,LOW);
        // digitalWrite(ledPin6,LOW);
        // digitalWrite(ledPin7,LOW);
        // digitalWrite(ledPin8,LOW);
        // digitalWrite(ledPin9,LOW);
        // digitalWrite(ledPin10,LOW);
        // digitalWrite(ledPin11,LOW);
        // digitalWrite(ledPin12,LOW);
        digitalWrite(ledPin13,LOW);
        digitalWrite(ledPin14,LOW);
        digitalWrite(ledPin15,LOW);
        digitalWrite(ledPin16,LOW);
        digitalWrite(ledPin17,LOW);
        digitalWrite(ledPin18,HIGH);
        digitalWrite(ledPin19,LOW);
        digitalWrite(ledPin20,LOW);
        state = "Display a ser instalado";
        }
    else if (messageTemp == Display){
        // digitalWrite(ledPin,LOW);
        // digitalWrite(ledPin1,LOW);
        // digitalWrite(ledPin2,LOW);
        // digitalWrite(ledPin3,LOW);
        // digitalWrite(ledPin4,LOW);
        // digitalWrite(ledPin5,LOW);
        // digitalWrite(ledPin6,LOW);
        // digitalWrite(ledPin7,LOW);
        // digitalWrite(ledPin8,LOW);
        // digitalWrite(ledPin9,LOW);
        // digitalWrite(ledPin10,LOW);
        // digitalWrite(ledPin11,LOW);
        // digitalWrite(ledPin12,LOW);
        digitalWrite(ledPin13,LOW);
        digitalWrite(ledPin14,LOW);
        digitalWrite(ledPin15,LOW);
        digitalWrite(ledPin16,LOW);
        digitalWrite(ledPin17,LOW);
        digitalWrite(ledPin18,LOW);
        digitalWrite(ledPin19,HIGH);
        digitalWrite(ledPin20,LOW);
        state = "Mirrors a ser instalado";
        }
    else if (messageTemp == Mirrors){
        // digitalWrite(ledPin,LOW);
        // digitalWrite(ledPin1,LOW);
        // digitalWrite(ledPin2,LOW);
        // digitalWrite(ledPin3,LOW);
        // digitalWrite(ledPin4,LOW);
        // digitalWrite(ledPin5,LOW);
        // digitalWrite(ledPin6,LOW);
        // digitalWrite(ledPin7,LOW);
        // digitalWrite(ledPin8,LOW);
        // digitalWrite(ledPin9,LOW);
        // digitalWrite(ledPin10,LOW);
        // digitalWrite(ledPin11,LOW);
        // digitalWrite(ledPin12,LOW);
        digitalWrite(ledPin13,LOW);
        digitalWrite(ledPin14,LOW);
        digitalWrite(ledPin15,LOW);
        digitalWrite(ledPin16,LOW);
        digitalWrite(ledPin17,LOW);
        digitalWrite(ledPin18,LOW);
        digitalWrite(ledPin19,LOW);
        digitalWrite(ledPin20,HIGH);
        state = "Farol da frente a ser instalado";
        }
       
    else {
      digitalWrite(ledPin,LOW);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin,LOW);
        digitalWrite(ledPin1,LOW);
        digitalWrite(ledPin2,LOW);
        digitalWrite(ledPin3,LOW);
        digitalWrite(ledPin4,LOW);
        digitalWrite(ledPin5,LOW);
        digitalWrite(ledPin6,LOW);
        digitalWrite(ledPin7,LOW);
        digitalWrite(ledPin8,LOW);
        digitalWrite(ledPin9,LOW);
        digitalWrite(ledPin10,LOW);
        digitalWrite(ledPin11,LOW);
        digitalWrite(ledPin12,LOW);
        digitalWrite(ledPin13,LOW);
        digitalWrite(ledPin14,LOW);
        digitalWrite(ledPin15,LOW);
        digitalWrite(ledPin16,LOW);
        digitalWrite(ledPin17,LOW);
        digitalWrite(ledPin18,LOW);
        digitalWrite(ledPin19,LOW);
        digitalWrite(ledPin20,LOW);
        state = "";
    }
  }
    
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("esp32_103268")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("esp32_103268/leds");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    
    
    //publish o estado dos leds
    Serial.print("State: ");
    Serial.println(state);
    client.publish("esp32/leds_state", state.c_str());
    
  }
}