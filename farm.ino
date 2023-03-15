#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
int AA = 5;
int AB = 6;

void setup() {
  Serial.begin(9600); //시리얼 모니터를 시작합니다.
  pinMode(AA, OUTPUT);
  pinMode(AB, OUTPUT); 
  mlx.begin();
  Serial.println("CLEARDATA");
  Serial.println("LABEL,W,H,T"); 
}

void loop() {
  int level = analogRead(A0);
  int leve2 = analogRead(A1);
  int leve3 = mlx.readObjectTempC();
  Serial.print("DATA,"); 
  Serial.print(level);
  Serial.print(",");
  Serial.print(leve2);
  Serial.print(",");
  Serial.println(leve3);
  digitalWrite(AA, HIGH);
  digitalWrite(AB, LOW);
  delay(4000);
  digitalWrite(AA, LOW);
  digitalWrite(AB, LOW);
  delay(2000);
}
