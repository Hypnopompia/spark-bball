/**
 ******************************************************************************
 * @file    bball.ino
 * @author  TJ Hunter (tjhunter@gmail.com)
 * @source  https://github.com/Hypnopompia/spark-bball
 * @version V1.0.0
 * @date    04/08/2014
 ******************************************************************************
The MIT License (MIT)

Copyright (c) 2014 TJ Hunter

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 ******************************************************************************
 */


/* Spark firmware for the spark powered basketball game */

int LEDpin = D7;
int player1Pin = D0;
int player2Pin = D1;

boolean p1SwitchState = LOW;
boolean p2SwitchState = LOW;

void setup() {
    pinMode(LEDpin, OUTPUT);
    pinMode(player1Pin, INPUT);
    pinMode(player2Pin, INPUT);
}

void loop() {
    int p1 = digitalRead(player1Pin);
    int p2 = digitalRead(player2Pin);
    
    if (p1SwitchState == LOW && p1 == HIGH) { // state changed
        p1SwitchState = HIGH;
        digitalWrite(LEDpin, p1SwitchState);  // indicate via LED
        delay(100);
    } else if (p1SwitchState == HIGH && p1 == LOW) {
        p1SwitchState = LOW;
        Spark.publish("spark-bball", "p1");
        digitalWrite(LEDpin, p1SwitchState);  // indicate via LED
        delay(100);
    }

    if (p2SwitchState == LOW && p2 == HIGH) { // state changed
        p2SwitchState = HIGH;
        digitalWrite(LEDpin, p2SwitchState);  // indicate via LED
        delay(100);
    } else if (p2SwitchState == HIGH && p2 == LOW) {
        p2SwitchState = LOW;
        Spark.publish("spark-bball", "p2");
        digitalWrite(LEDpin, p2SwitchState);  // indicate via LED
        delay(100);
    }
    
}