void ledSetup() {
  //// Setup LED for Testing
  ledcSetup(1, 1000, 8); 
  ledcSetup(2, 1000, 8);
  ledcSetup(3, 1000, 8);
  ledcSetup(4, 1000, 8);
  ledcAttachPin(15, 1);
  ledcAttachPin(2, 2);
  ledcAttachPin(4, 3);
  ledcAttachPin(16, 4);
}

//// Setup PWM for LED(s)
void leds() {
  channelOne();
  channelTwo();
  channelThree();
  channelFour();
}

void channelOne() {
  ledcWrite(1, ledChannelOne); 
}

void channelTwo() {
  ledcWrite(2, ledChannelTwo); 
}

void channelThree() {
  ledcWrite(3, ledChannelThree); 
}

void channelFour() {
  ledcWrite(4, ledChannelFour); 
}
