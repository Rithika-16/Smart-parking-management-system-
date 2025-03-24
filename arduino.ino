#include <WiFi.h>
#include <WebServer.h>

// WiFi Credentials
const char* ssid = "HAM";       // 🔹 Change to your WiFi SSID
const char* password = "VU2HCF@55";  // 🔹 Change to your WiFi Password

WebServer server(80);  // Create web server on port 80

// Sensor Pins (for 3 slots)
const int sensor1 = 34;
const int sensor2 = 35;
const int sensor3 = 32;

// Parking Slot Status
int slot1 = 0, slot2 = 0, slot3 = 0;

// Function to read sensor values
void readSensors() {
    slot1 = digitalRead(sensor1);  // Read IR sensor 1
    slot2 = digitalRead(sensor2);  // Read IR sensor 2
    slot3 = digitalRead(sensor3);  // Read IR sensor 3
}

// Function to send JSON data with CORS enabled
void handleData() {
    readSensors();  // Get fresh sensor data

    String json = "{";
    json += "\"slot1\":" + String(slot1) + ",";
    json += "\"slot2\":" + String(slot2) + ",";
    json += "\"slot3\":" + String(slot3);
    json += "}";

    server.sendHeader("Access-Control-Allow-Origin", "*");  // 🔥 Enable CORS
    server.send(200, "application/json", json);
}

void setup() {
    Serial.begin(115200);

    // Set Sensor Pins as Input
    pinMode(sensor1, INPUT);
    pinMode(sensor2, INPUT);
    pinMode(sensor3, INPUT);

    // Connect to WiFi
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi...");
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi connected.");
    Serial.print("ESP32 IP: ");
    Serial.println(WiFi.localIP());

    // Define Web Server Route
    server.on("/getData", handleData);
    
    // Start Server
    server.begin();
}

void loop() {
    server.handleClient(); // Handle web requests
}
