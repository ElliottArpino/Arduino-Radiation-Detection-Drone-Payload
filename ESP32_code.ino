#include <WiFi.h>
#include <WebServer.h>
#include <TinyGPS++.h>

//*****************************//
//          Wi-Fi Setup        //
//*****************************//

const char* ssid = "username";
const char* password = "password";

//*****************************//
//     GPS Configuration       //
//*****************************//

// Define the RX and TX pins for Serial 2
#define RXD2 16
#define TXD2 17
#define GPS_BAUD 9600

// The TinyGPS++ object
TinyGPSPlus gps;

// Create an instance of the HardwareSerial class for Serial 2
HardwareSerial gpsSerial(2);

//*****************************//
//     Sensor Configuration    //
//*****************************//

// Geiger Counter Configuration
const int geigerPin = 32;
volatile int count = 0;  // Radiation count from Geiger counter
unsigned long lastMillis = 0;  // For timing 10-second intervals
float countsPerMinute = 0.0;  // Radiation counts per minute
float radiationLevel = 0.0;  // Radiation level (calibration required)

//*****************************//
//         Web Server          //
//*****************************//

// Create a web server object on port 80
WebServer server(80);

//*****************************//
//        Functionality        //
//*****************************//

// Function to calculate the radiation level
float readSensor() {
  if (millis() - lastMillis >= 10000) {  // Every 10 seconds
    countsPerMinute = (float)count * 6;  // Convert counts to CPM
    radiationLevel = countsPerMinute / 100.0; // 1 CPM ≈ 0.01 µSv/h
    count = 0;  // Reset the count for the next interval
    lastMillis = millis();  // Update the lastMillis timestamp
  }
  return radiationLevel;  // Always return the last calculated value
}

// Function to format GPS and sensor data for server output
String getSensorAndGPSData() {
  float latestRadiation = readSensor();

  String latitude = gps.location.isValid() ? String(gps.location.lat(), 6) : "0.000000";
  String longitude = gps.location.isValid() ? String(gps.location.lng(), 6) : "0.000000";
  String altitude = gps.altitude.isValid() ? String(gps.altitude.meters(), 2) : "0.00";

  // Combine all values into one line
  return String(latestRadiation, 2) + " " + latitude + " " + longitude + " " + altitude;
}

// Function to handle HTTP requests to the root URL
void handleRoot() {
  String response = getSensorAndGPSData();
  server.send(200, "text/plain", response);
}

// ISR Function to count Geiger events
void countRadiation() {
  count++;
}

//*****************************//
//           Setup             //
//*****************************//

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Start the server and define routes
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");

  // Initialize Geiger counter
  pinMode(geigerPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(geigerPin), countRadiation, RISING);
  Serial.println("Geiger-Muller Radiation Detector Initialized");

  // Initialize GPS
  gpsSerial.begin(GPS_BAUD, SERIAL_8N1, RXD2, TXD2);
  Serial.println("GPS Module Initialized");
}

//*****************************//
//            Loop             //
//*****************************//

void loop() {
  // Handle incoming client requests
  server.handleClient();

  // Read GPS data
  while (gpsSerial.available() > 0) {
    gps.encode(gpsSerial.read());
  }
}


