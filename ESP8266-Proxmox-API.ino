// Information:
// cURL Command for testing with Windows:
// curl -X POST --insecure -H "Authorization: PVEAPIToken=USERNAME@REALM!TOKENID=SECRET" https://192.168.178.200:8006/api2/json/nodes/NODE/qemu/VMID/status/start
// GET won't work here as no CSRF Value is present (Blocked by Proxmox API). 

// How to use: 
// Add your API Token in the Line with "Authorization"
// Update IP Address
// Update "http_command" and insert NODE and VMID
// Inser WiFi Credentials

#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <Arduino_JSON.h>

// WIFI Config
const char* ssid = "***";
const char* password = "***";

// API Config
const char* server = "https://192.168.178.200:8006";
const char* http_command = "/api2/json/nodes/NODE/qemu/VMID/status/shutdown";
bool ispost = true; // true == POST | false == GET

// Setup
HTTPClient http;

void setup()
{
  Serial.println("[System] >> Proxmox API POST Request Example <<");
  connectWifi();
  Serial.begin(115200);
}
  
void loop() {
  // Disable Certificate Warning
  std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
  client->setInsecure();

  // Create API URL
  char apiURL[1024];
  Serial.println("[HTTP] Creating URL");
  sprintf(apiURL, "%s%s", server, http_command);
  Serial.printf("[HTTP] Proxmox API URL=%s\r\n",apiURL);

  // Send Command to API Endpoint
  Serial.println("[HTTP] Connecting to Server");
  if (http.begin(*client, apiURL)) {
    Serial.println("[HTTP] Connected");
    http.addHeader("Authorization", "PVEAPIToken=USERNAME@REALM!TOKENID=SECRET");
    if (ispost == true)
    {
      auto code = http.POST("");
    }
    else
    {
      int code = http.GET();  
    }
    Serial.printf("[HTTP] Answer-Code [%d]\r\n", code);
    if (code > 0) {
      if (code == HTTP_CODE_OK || code == HTTP_CODE_MOVED_PERMANENTLY) {
        Serial.println("[HTTP] POST OK");
        String payload = http.getString();
        Serial.println(payload);
        Serial.println("===JSON===");
      }
    }
    else {
      Serial.printf("[HTTP] Error with POST: %s", http.errorToString(code).c_str());
    }
  }

  // Repeat API Call each 10 Seconds
  delay(10000);
}

boolean connectWifi() 
{
  // Let us connect to WiFi
  Serial.println("[WiFi] Connecting to WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("[WiFi] Connected");
  Serial.print("[WiFi] IP Address:");
  Serial.println(WiFi.localIP());
  return true;
}
