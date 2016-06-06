#include <SoftwareSerial.h>

int ser;
int max = 255;
int min = 0;
int fade = 4 ;
int fade1 = 4;
int fade2 = 4;

int Red, Green, Blue;
int a, b, c;

void setup()
{

  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);

  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);

  pinMode(11, OUTPUT);
  digitalWrite(11, LOW);

  Serial.begin(9600);

}

void loop()  // Continuous loop
{

  if (Serial.available()) {
    ser = Serial.read();

    if (ser < 40) {
      int red = (ser * 6) + 21;
      red = max - red + min;
      analogWrite(9, red);
    }
    if (ser >= 40 && ser < 80) {
      int blue = ((ser - 40) * 6) + 21;
          blue = max - blue + min;
      analogWrite(11, blue);
    }
    if (ser >= 80 && ser < 120) {
      int green = ((ser - 80) * 6) + 21;
          green = max - green + min;
      analogWrite(10, green);
    }



    if (ser == 121) {
      digitalWrite(9, HIGH);
    }
    if (ser == 122) {
      digitalWrite(9, LOW);
    }

    if (ser == 123) {
      digitalWrite(10, HIGH);
    }
    if (ser == 124) {
      digitalWrite(10, LOW);
    }

    if (ser == 125) {
      digitalWrite(11, HIGH);
      Serial.print("On");
      Serial.print(ser);
    }
    if (ser == 126) {
      digitalWrite(11, LOW);
    }



    if (ser > 126) {
      if ((ser - 127) % 5 == 0) {
        int reD = (ser - 127) * 2.55;
//        reD = max - reD + min;
        a = reD;
        fade = 4;
        analogWrite(9, reD);

      }
      if ((ser - 128) % 5 == 0) {
        int greeN = (ser - 128) * 2.55;
//        greeN = max - greeN + min;
        b = greeN;
        fade1 = 4;
        analogWrite(11, greeN);
      }
      if ((ser - 129) % 5 == 0) {
        int bluE = (ser - 129) * 2.55;
//        bluE = max - bluE + min;
        c = bluE;
        fade2 = 4;
        analogWrite(10, bluE);
      }
    }


    if (ser == 255) {

      if (a >= 0 && a <= 3) {
        fade = -fade;
      }

      analogWrite(9, a);
      a = a - fade;

      if (a >= 252 && a <= 255) {
        fade = -fade;
      }

      if (b >= 0 && b <= 3) {
        fade1 = -fade1;
      }

      analogWrite(11, b);
      b = b - fade1;

      if (b >= 252 && b <= 255) {
        fade1 = -fade1;
      }

      if (c >= 0 && c <= 3) {
        fade2 = -fade2;
      }

      analogWrite(10, c);
      c = c - fade2;

      if (c >= 252 && c <= 255) {
        fade2 = -fade2;
      }
    }
  } 
}


