#include <Arduino.h>
#include <ESP32QRCodeReader.h>

#include <WiFi.h>
#include <PubSubClient.h> 

//Escolha do tipo de espcam e a sua configuração da libraria
ESP32QRCodeReader reader(CAMERA_MODEL_AI_THINKER);

// Replace with your network credentials
const char* ssid = "EletroWIFI";
const char* password = "12345678";

// TCP server details
const char* host = "193.137.172.20";
const uint16_t port = 85;

WiFiClient TCP_Client; // Objecto do tipo TCP 
PubSubClient client(TCP_Client);

struct QRCodeData qrCodeData;
bool isConnected = false;
// outra maneira de fazer o que se faz na linha 20, mas é incompativel com o pubsub
// void onQrCodeTask(void *pvParameters)
// {
//   struct QRCodeData qrCodeData;

//   while (true)
//   {
//     if (reader.receiveQrCode(&qrCodeData, 100))
//     {
//       Serial.println("Found QRCode");
//       if (qrCodeData.valid)
//       {
//         Serial.print("Payload: ");
//         Serial.println((const char *)qrCodeData.payload);
//       }
//       else
//       {
//         Serial.print("Invalid: ");
//         Serial.println((const char *)qrCodeData.payload);
//       }
//     }
//     vTaskDelay(100 / portTICK_PERIOD_MS);
//   }
// }
//conecção ao wifi
bool connectWifi()
{
  if (WiFi.status() == WL_CONNECTED)
  {
    return true;
  }
  //esperar conectar-se escrevendo "." até coectar
  WiFi.begin(ssid, password);
  int maxRetries = 50;
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
    maxRetries--;
    if (maxRetries <= 0)
    {
      return false;
    }
  }
  // mandar na porta série que está connectado
  Serial.println("");
  Serial.println("WiFi connected");
  client.setServer("193.137.172.20", 85); // O Servidor MQTT, Broker
//  // client.setCallback(callback); 
  client.connect("esp32_103268"); // nome com o qual o esp se connecta
  return true;
}
void setup()
{
  // inicio da comunicação serie
  Serial.begin(115200);
  Serial.println();
  // setup do leitor de qr
  reader.setup();

  Serial.println("Setup QRCode Reader");
  // definir que o programa de ler qr é corrido no core nº1 do esp
  reader.beginOnCore(1);

  Serial.println("Begin on Core 1");

  // xTaskCreate(onQrCodeTask, "onQrCode", 4 * 1024, NULL, 4, NULL); 
  //reader.setup();
  //reader.setDebug(true);
  //Serial.println("Setup QRCode Reader");

  //reader.begin();
  //Serial.println("Begin QR Code reader");

  delay(1000);
}

void loop()
{
  // chamar a função onde se faz a conecção ao wifi e ao servidor mqtt
  bool connected = connectWifi();
  if (isConnected != connected)
  {
    isConnected = connected;
  }
  if (reader.receiveQrCode(&qrCodeData, 100))
  {
    Serial.println("Found QRCode");
    if (qrCodeData.valid)
    {
      Serial.print("Payload: ");
      Serial.println((const char *)qrCodeData.payload);
      client.loop();
      delay(500);
    // Send the decoded QR code para o tópico "qrcode_espcam" no mqtt
      client.publish("qrcode_espcam", (const char *)qrCodeData.payload);
      
      Serial.println("Sent QR code to server");
      Serial.println((const char *)qrCodeData.payload);
    }
    else
    {
      Serial.print("Invalid: ");
      Serial.println((const char *)qrCodeData.payload);
    }
  }
  delay(300);
}