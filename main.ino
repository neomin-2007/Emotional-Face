#include <LiquidCrystal_I2C.h>

#define happy_face "     ^    ^  "
#define happy_face_2 "   ( ------ )   "

#define kinda_face "     -    -  "
#define kinda_face_2 "   ) ------ (   "

#define bad_face "     u    u  "
#define bad_face_2 "    )------(    "

#define sad_face "     T    T  "
#define sad_face_2 "    )wwwwww(    "

#define death_face "     x    x  "
#define death_face_2 "      ----      "

LiquidCrystal_I2C lcd(0x27, 16, 2);

int hp = 100;
String face;
String face_2;

void waitSec(int n) {delay(n * 1000);}
void waitMinute(int n) {delay (n * 60 * 1000);};

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {

  lcd.clear();

  if (hp <= 0) {
    lcd.setCursor(0, 0);
    lcd.print(death_face);
    lcd.print("00");

    lcd.setCursor(0, 1);
    lcd.print(death_face_2);
    waitSec(2);
    return;
  }

  int face_selector = 0;
  if (hp >= 100) {
    face_selector = 0;
  } else if (hp >= 75)  {
    face_selector = 1;
  } else if (hp >= 50) {
    face_selector = 2;
  } else if (hp >= 1) {
    face_selector = 3;
  }

  switch (face_selector) {
    case 0:
      face = happy_face;
      face_2 = happy_face_2;
    break;
    case 1:
      face = kinda_face;
      face_2 = kinda_face_2;
    break;
    case 2:
      face = bad_face;
      face_2 = bad_face_2;
    break;
    case 3:
      face = sad_face;
      face_2 = sad_face_2;
    break;
  }

  lcd.setCursor(0, 0);

  lcd.print(face);
  lcd.print(hp);

  lcd.setCursor(0, 1);

  lcd.print(face_2);

  hp -= 15;
  waitSec(2);
}
