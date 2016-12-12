///// Libraries Needed
#include <ArduinoJson.h>
#include <WiFi.h>
#include <PubSubClient.h>

#define DEBUG

//// WiFi Configuration
char myhostname[] = "#########";
const char* ssid = "#########;
const char* password = "#########";
WiFiClient espClient;


//// Setup MQTT Messaging
const char* mqtt_server = "#########";
const char* ver = "esp32-v1.0.0a";
PubSubClient client(espClient);
long lastReconnectAttempt = 0;
unsigned long mqttPreviousMillis = 1;
const long publishInterval = 2000;

//// Setup Outlet State(s)
int outlet1 = 0;
int outlet2 = 0;

//// Setup PWM State(s)
int ledChannelOne = 0;
int ledChannelTwo = 0;
int ledChannelThree = 0;
int ledChannelFour  = 0;

boolean ledChannelOneState = false;
boolean ledChannelTwoState = false;
boolean ledChannelThreeState = false;
boolean ledChannelFourState = false;

void setup() {
  // put your setup code here, to run once:
  #ifdef DEBUG
  Serial.begin(115200);
  while (!Serial){
  }
  #endif 	
  outletSetup();
  ledSetup();
  beginNetwork();
  setupMQTT();
  lastReconnectAttempt = 0;  
}

//// Main Loop
void loop() {
  mqttCheckConnection();
  client.loop();
  mqttPublish();
}
