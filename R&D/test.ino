/*
 blynk node code
 
*/

#include <ArduinoJson.h>

String recv_str_jsondata;

StaticJsonDocument<256> doc_send;
StaticJsonDocument<256> doc_recv;

#define RXD2 16
#define TXD2 17

void setup()
{
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);        //Hardware Serial of ESP32
}

void loop() {

  
  // Recieving data (JSON) from Coordinator ESP
  if (Serial2.available())
  {

    recv_str_jsondata = Serial2.readStringUntil('\n');
    Serial.println(recv_str_jsondata);
    DeserializationError error = deserializeJson(doc_recv, recv_str_jsondata);

    if (!error) {                                           // if not error in deserialization
      float temp = doc_recv["<key>"];                       // fetch temprature data from JSON . Here { v1 : 28.55 }
      float hum = doc_recv["v2"];                       // fetch temprature data from JSON . Here { v2 :32.25 }

      if (temp > 0) {
        Serial.print("temp ="); 
        Serial.println(temp);
      }
      if (hum > 0) {
        Serial.print("hum ="); 
        Serial.println(hum);
      }

    }

    else {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }
    recv_str_jsondata = "";
  }

}

/*
Cordinator node code
*/

#include <esp_now.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <Wire.h>

uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; // Universal Broadcast address


StaticJsonDocument<256> doc_from_espnow; // JSON Doc for Receiving data from ESPNOW Devices
StaticJsonDocument<256> doc_to_espnow; // JSON Doc for Transmitting data to ESPNOW Devices

String recv_jsondata;               // recieved JSON string

#define RXD2 16
#define TXD2 17

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status)
{
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

//ESPNOW Receive Callback Function
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len)
{

  char* buff = (char*) incomingData;
  recv_jsondata = String(buff);
  Serial.print("Recieved from ESPNOW: "); Serial.println(recv_jsondata);
  DeserializationError error = deserializeJson(doc_from_espnow, recv_jsondata);
  if (!error) {
    Serial.print("Serilising to Serial2: ");
    Serial.println(recv_jsondata);
    temperature  = doc_from_espnow["<key1>"];                 // Storing Temperature Data
    humidity  = doc_from_espnow["<key2>"]                 // Storing Humidity Data
    serializeJson(doc_from_espnow, Serial2);            // Writing Data to Serial2
  }

  else
  {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

}

void setup()
{
    Serial.begin(115200);
    Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);

      WiFi.mode(WIFI_STA);

  // Initialising ESPNOW Communication
  if (esp_now_init() != ESP_OK)
  {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Defining Callback Functions
  esp_now_register_recv_cb(OnDataRecv);
  esp_now_register_send_cb(OnDataSent);

  // Adding Peer Devices
  esp_now_peer_info_t peerInfo;
  memset(&peerInfo, 0, sizeof(peerInfo));
  for (int ii = 0; ii < 6; ++ii )
  {
    peerInfo.peer_addr[ii] = (uint8_t) broadcastAddress[ii];
  }
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop()
{
    if (Serial2.available())
    {
        // Recieving data (JSON) from BLYNK ESP
        String recv_str_jsondata = Serial2.readStringUntil('\n');

        //Serializing JSON
        serializeJson(doc_to_espnow, recv_str_jsondata);
        Serial.println(recv_str_jsondata);

        // Broadcasting data (JSON) via ESP-NOW
        esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) recv_str_jsondata.c_str(), sizeof(recv_str_jsondata) * recv_str_jsondata.length());

        if (result == ESP_OK)
        {
        Serial.println("Sent with success");
        }
        else
        {
        Serial.println(result);
        }
        delay(20);
    }
}


/*
sensor node code
*/
#include <esp_now.h>
#include <WiFi.h>
uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; //Coordinator ESP MAC address


#include <ArduinoJson.h>
String recv_jsondata;
String send_jsondata;
StaticJsonDocument<256> doc_to_espnow;
StaticJsonDocument<256> doc_from_espnow;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}


void setup() 
{
    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }
    esp_now_register_send_cb(OnDataSent);            
    
    esp_now_peer_info_t peerInfo;
    <key1>(&peerInfo, 0, sizeof(peerInfo));
    for (int ii = 0; ii < 6; ++ii )
    {
        peerInfo.peer_addr[ii] = (uint8_t) broadcastAddress[ii];
    }
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    // Add peer
    if (esp_now_add_peer(&peerInfo) != ESP_OK) {
        Serial.println("Failed to add peer");
        return;
    }
}    

void loop() {
                                                  // Sending Tempreature Every 4 Seconds
  float sensor_data1 = function_to_measure();
  float sensor_data2 = function_to_measure();
  doc_to_espnow["<key1>"] = sensor_data1;                       // Creating JSON data. Here { v1 : 28.55 }
  doc_to_espnow["<key2>"] = sensor_data2;                       // Creating JSON data. Here { v2 : 34.35 }
  serializeJson(doc_to_espnow, send_jsondata);
  esp_now_send(broadcastAddress, (uint8_t *) send_jsondata.c_str(), send_jsondata.length());
                                                    // Sending it to Coordinater ESP
  Serial.println(send_jsondata); 
  send_jsondata = "";
  delay(4000);
}






