
class MD {
  public:
    void on();
    void off();
    int getNextDeviceIndex();
    MD(int size, int devices[]);
  private:
    int _size;
    int _devices[2] = {10,11};
    unsigned long lastTimeDevices[4] = {0UL,0UL,0UL,0UL};
    unsigned long reqDelay = 50;
    unsigned long delayNeedForDevice = 50; 
    unsigned long lastTime = 0UL; 
    int _currentIndex = -1;
};

MD::MD(int size, int devices[]) {
  _size = size;
  //_devices = devices;
}
void MD::off() {
   unsigned long currentMillis = millis();
   //Logic for off
   for(int i =0; i< _size;  i++) {
      if(abs(currentMillis - lastTimeDevices[i]) >= delayNeedForDevice) {
         digitalWrite(_devices[i], true);  
      }
   }
}

void MD::on() {
   unsigned long currentMillis = millis();
   //Logic for off
   for(int i =0; i< _size;  i++) {
      if(abs(currentMillis - lastTimeDevices[i]) >= delayNeedForDevice) {
         digitalWrite(_devices[i], true);  
      }
   }
   //Logic for off 
   if (abs(currentMillis - lastTime) >= reqDelay) {
      lastTime = millis();
      _currentIndex = getNextDeviceIndex();
      digitalWrite(_devices[_currentIndex], false);
      lastTimeDevices[_currentIndex] = lastTime;
   } 

}

int MD::getNextDeviceIndex() {
  return (_currentIndex + 1) % _size;
}
int dev[] = {8,9};
MD a(2, dev); 

const int analogInPin = A0;
int sensorValue = 0;
void setup() {
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {

  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  if (sensorValue < 900) {
     a.on();
  } else {
    a.off();
  }
 
}
