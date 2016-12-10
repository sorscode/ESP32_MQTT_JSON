//// Setup Outlet Pin(s)
const int outletPin1 = 18;
const int outletPin2 = 19;

void outletSetup()  {
  //// Setup LED for Testing
  pinMode(outletPin1, OUTPUT);
  pinMode(outletPin2, OUTPUT);
  digitalWrite(outletPin1, 0);
  digitalWrite(outletPin2, 0);
}

void outletPort1() {
  if ((outlet1 == 0) && (digitalRead(outletPin1) == 0)) { 
    return;
  }
  else {
    if (outlet1 == 0) {
      digitalWrite(outletPin1, 0);
      client.publish("test/status", "Turned Outlet 1 - Off");
      #ifdef DEBUG
      Serial.println(F("Turn Outlet 1 Off"));
      #endif
    }
  }
  if ((outlet1 == 1) && (digitalRead(outletPin1) == 1)) {
    return;
     }
     else {
      if (outlet1 == 1) {
        digitalWrite(outletPin1, 1);
        client.publish("test/status", "Turned Outlet 1 - On");
        #ifdef DEBUG
        Serial.println(F("Turn Outlet 1 On"));
        #endif
        
      }
   }
}

void outletPort2() {
  if ((outlet2 == 0) && (digitalRead(outletPin2) == 0)) {
  return;
  }
  else {
    if (outlet2 == 0) {
      digitalWrite(outletPin2, 0);
      client.publish("test/status", "Turned Outlet 2 - Off");
      #ifdef DEBUG
      Serial.println(F("Turn Outlet 2 Off"));
      #endif
    }
  }
  if ((outlet2 == 1) && (digitalRead(outletPin2) == 1)) {
    return;
     }
     else {
      if (outlet2 == 1) {
        digitalWrite(outletPin2, 1);
        client.publish("test/status", "Turned Outlet 2 - On");
        #ifdef DEBUG
        Serial.println(F("Turn Outlet 2 On"));
        #endif 
      }
   }
}
