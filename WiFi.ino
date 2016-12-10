//// Setup WiFi Connection
void beginNetwork() {
    //// Enable WiFi Access    
//  WiFi.hostname(myhostname);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}
