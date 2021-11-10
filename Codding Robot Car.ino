#define BLYNK_PRINT Serial 
#define BLYNK_TEMPLATE_ID "TMPLtXOmjoPr"
#define BLYNK_DEVICE_NAME "SmartCar"
#define BLYNK_AUTH_TOKEN "vXf0BSYIie1DO_95gdKILPJCxqjVcNi8"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define RightMotor1 D1 // D1 <-> IN1
#define RightMotor2 D3  // D3 <-> IN2
#define LeftMotor1 D2  // D2 <-> IN3
#define LeftMotor2 D4  // D4 <-> IN4

char auth[] = "vXf0BSYIie1DO_95gdKILPJCxqjVcNi8";
char ssid[] = "Itmeomex";
char pass[] = "22092544";

void setup()
{
 Serial.begin(115200);
 Blynk.begin(auth, ssid, pass);

 pinMode(RightMotor1, OUTPUT);
 pinMode(RightMotor2, OUTPUT);
 pinMode(LeftMotor1, OUTPUT);
 pinMode(LeftMotor2, OUTPUT);
}

void loop()
{
 Blynk.run();
}

void halt()
{
 digitalWrite(RightMotor2, HIGH);
 digitalWrite(LeftMotor2, HIGH);
 digitalWrite(RightMotor1, HIGH);
 digitalWrite(LeftMotor1, HIGH);
}

void forward()
{
 digitalWrite(RightMotor2, HIGH);
 digitalWrite(LeftMotor2, HIGH);
 digitalWrite(RightMotor1, LOW);
 digitalWrite(LeftMotor1, LOW);
}

void reverse()
{
 digitalWrite(RightMotor2, LOW);
 digitalWrite(LeftMotor2, LOW);
 digitalWrite(RightMotor1, HIGH);
 digitalWrite(LeftMotor1, HIGH);
}

void right()
{
 digitalWrite(RightMotor2, LOW);
 digitalWrite(LeftMotor2, HIGH);
 digitalWrite(RightMotor1, HIGH);
 digitalWrite(LeftMotor1, LOW);
}

void left()
{
 digitalWrite(RightMotor2, HIGH);
 digitalWrite(LeftMotor2, LOW);
 digitalWrite(RightMotor1, LOW);
 digitalWrite(LeftMotor1, HIGH);
}

BLYNK_WRITE(V1)
{
 if (param[0])
 forward();
 else
 halt();
}

BLYNK_WRITE(V2)
{
 if (param[0])
 reverse();
 else
 halt();
}

BLYNK_WRITE(V3)
{
 if (param[0])
 right();
 else
 halt();
}

BLYNK_WRITE(V4)
{
 if (param[0])
 left();
 else
 halt();
}
