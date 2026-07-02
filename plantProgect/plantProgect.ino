
const int sensorPin = A0;
const int Relapin = 13;
int Redpin = 8;

const int Turn_On_pump = 600;
const int Turn_off_pump = 200;

void setup() {
  pinMode(Relapin, OUTPUT);
  pinMode(Redpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int sum = 0;
  for(int i = 0; i < 5; i++){
    sum += analogRead(sensorPin);
    delay(10);
  }

  int moisture = sum / 5;
  Serial.println(moisture);

  // 🔴 LED
  if(moisture > Turn_On_pump){
    digitalWrite(Redpin, HIGH);
  } else {
    digitalWrite(Redpin, LOW);
  }

  // 🔵 المضخة
  if(moisture > Turn_On_pump){
    digitalWrite(Relapin, LOW);   // تشغيل
  } else if(moisture < Turn_off_pump){
    digitalWrite(Relapin, HIGH);  // إطفاء
  }

  delay(500);
} 