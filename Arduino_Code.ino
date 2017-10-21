#include <SoftwareSerial.h>// import the serial library

const int right = 5;
const int left = 4;

const int backward = 2;
const int forward = 3;

SoftwareSerial Genotronex(10, 11); // RX, TX

void setup() {

    Genotronex.begin(9600);
    Serial.begin(9600);
    pinMode(right, OUTPUT);
    pinMode(left, OUTPUT);
    pinMode(backward, OUTPUT);
    pinMode(forward, OUTPUT);
    Genotronex.println("Bluetooth Is ON. Press f for forward, b for backward, r for right, and l for left.");

}

void loop() {

    if (Genotronex.available()) {

        char x = char(Genotronex.read());

        if (x == 'f')
        {
            moveForward();
        }
        else if (x == 'b')
        {
            moveBackward();
        }
        else if (x == 'r')
        {
            turnRight();
            delay(90);
            moveForward();

        }
        else if (x == 'l')
        {
            turnLeft();
            delay(90);
            moveForward();
        }
        else if (x == 's')
        {
            stopIT();
        }
    }
}

void moveForward()// Makes car move forward. It does so until another function is called.
{

    digitalWrite(right, LOW);
    digitalWrite(left, LOW);
    digitalWrite(backward, LOW);
    digitalWrite(forward, HIGH);
}

void moveBackward()//Makes car move backward. It does so until another function is called.
{
    digitalWrite(left, LOW);
    digitalWrite(right, LOW);
    digitalWrite(forward, LOW);
    digitalWrite(backward, HIGH);
}

void turnRight()// Calling this function makes the car turn right. And it keeps on doing this unless move forward is called.
{
    digitalWrite(left, LOW);
    digitalWrite(right, HIGH);

}

void turnLeft()// Calling this function makes the robot turn left. And it keeps on doing this unless move forward is called.
{
    digitalWrite(right, LOW);
    digitalWrite(left, HIGH);

}

void stopIT()// Stops the car. You have to continuously call it.
{
    digitalWrite(right, LOW);
    digitalWrite(left, LOW);
    digitalWrite(backward, LOW);
    digitalWrite(forward, LOW);
}
