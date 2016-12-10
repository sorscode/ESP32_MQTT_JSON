void setupMQTT(){
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

boolean reconnect() {
  if (client.connect("ESP32")) {
    // Once connected, publish an announcement...
    client.publish("test/status", "Online");
    client.publish("test/status", ver);
    // ... and resubscribe
      client.subscribe("test/ledChannel1");
        client.loop();
      client.subscribe("test/ledChannel2");
        client.loop();
      client.subscribe("test/ledChannel3");
        client.loop();
      client.subscribe("test/ledChannel4");
        client.loop();
      client.subscribe("test/outlet1");
        client.loop();
      client.subscribe("test/outlet2");
        client.loop();                
  }
  return client.connected();
}

void callback(char* topic, byte* payload, unsigned int length) {
  if(strcmp(topic, "test/ledChannel1") == 0) {
    #ifdef DEBUG  
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    #endif
    String value = "";
    for (int i = 0; i < length; i++) {
      #ifdef DEBUG
      Serial.print((char)payload[i]);
      #endif
      value += (char)payload[i]; 
    }
    if(value.toInt() != ledChannelOne){
      ledChannelOneState = true;
    }    
    ledChannelOne = value.toInt();
    leds();
    #ifdef DEBUG
    Serial.println();
    #endif
  }
  if(strcmp(topic, "test/ledChannel2") == 0) {
    #ifdef DEBUG
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    #endif
    String value = "";
    for (int i = 0; i < length; i++) {
      #ifdef DEBUG
      Serial.print((char)payload[i]);
      #endif
      value += (char)payload[i]; 
    }
    if(value.toInt() != ledChannelTwo){
      ledChannelTwoState = true;
    }      
    ledChannelTwo = value.toInt(); 
    leds();
    #ifdef DEBUG
    Serial.println();
    #endif    
  }    

  if(strcmp(topic, "test/ledChannel3") == 0) {
    #ifdef DEBUG
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    #endif
    String value = "";
    for (int i = 0; i < length; i++) {
      #ifdef DEBUG
      Serial.print((char)payload[i]);
      #endif
      value += (char)payload[i]; 
    }
    if(value.toInt() != ledChannelThree){
      ledChannelThreeState = true;
    }    
    ledChannelThree = value.toInt();
    leds(); 
    #ifdef DEBUG
    Serial.println();
    #endif  
  }

  if(strcmp(topic, "test/ledChannel4") == 0) {
    #ifdef DEBUG
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    #endif
    String value = "";
    for (int i = 0; i < length; i++) {
      #ifdef DEBUG
      Serial.print((char)payload[i]);
      #endif
      value += (char)payload[i]; 
    }
    if(value.toInt() != ledChannelFour){
      ledChannelFourState = true;
    }    
    ledChannelFour = value.toInt();
    leds();
    #ifdef DEBUG
    Serial.println();
    #endif    
  }  
  if(strcmp(topic, "test/outlet1") == 0) {
    #ifdef DEBUG
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    #endif
    String value = "";
    for (int i = 0; i < length; i++) {
      #ifdef DEBUG
      Serial.print((char)payload[i]);
      #endif
      value += (char)payload[i]; 
    }
    outlet1 = value.toInt();
    outletPort1(); 
    #ifdef DEBUG
    Serial.println();
    #endif
  }

  if(strcmp(topic, "test/outlet2") == 0) {
    #ifdef DEBUG
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    #endif
    String value = "";
    for (int i = 0; i < length; i++) {
      #ifdef DEBUG
      Serial.print((char)payload[i]);
      #endif
      value += (char)payload[i]; 
    }
    outlet2 = value.toInt();
    outletPort2();
    #ifdef DEBUG 
    Serial.println();
    #endif
  }  
}

void mqttCheckConnection() {
  if (!client.connected()) {
    long now = millis();
    if (now - lastReconnectAttempt > 5000) {
      lastReconnectAttempt = now;
      // Attempt to reconnect
      if (reconnect()) {
        lastReconnectAttempt = 0;
      }
    }
  } else {
    // Client connected
    client.loop();
  }
} 


/*
This is the start of trying to get ArduinoJson Library
to work with the ESP32.
Currently the library is throwing an error. Will return
back to it, once I have everything else working correctly
*/

/*
const int bufferLen = 256;
char jsonMessage[bufferLen];

void mqttPublish() {
   unsigned long mqttPubMillis = millis();
     if (mqttPubMillis - mqttPreviousMillis >= publishInterval) {
      mqttPreviousMillis = mqttPubMillis;
      const char* jsonTopic = "test/json";
      int length;
      DynamicJsonBuffer  jsonBuffer;
      //StaticJsonBuffer<200> jsonBuffer;
      //JsonObject& root = jsonBuffer.createObject();
  
    // jsonData(root);
  
      //length = root.printTo(jsonMessage, bufferLen);
    client.publish(jsonTopic, jsonMessage, true);  
   }
}

void jsonData(JsonObject& root) {
  root["version"] = ver;
  root["ledChannel1"] = ledChannelOne;
  root["ledChannel2"] = ledChannelTwo;
  root["ledChannel3"] = ledChannelThree;
  root["ledChannel4"] = ledChannelFour;
  root["outlet1"] = outlet1;
  root["outlet2"] = outlet2; 
}
*/
