
#include<LiquidCrystal_I2C.h> //library for LCD Display
#include <Wire.h> 

LiquidCrystal_I2C lcd(0x27,16,2); //define pins for LCD Display

#define inSensor 19   //define IR Sensor 1 pins onnnected to D4 
#define outSensor 18  //define IR Sensor 2 pins onnnected to D3
#define LED_1 5     //define LED pins onnnected to D6
#define GND 4
#define R1 2
#define R2 15
//Variables
int inStatus;
int outStatus;
 
int in=0;
int out=0;
int now=0;

int countin = 0;
int countout = 0;
 
 
void setup()
{
  lcd.init(); //Initialise the LCD to 16x2 Character Format
  lcd.backlight();

  //Set Components pin modes
  pinMode(inSensor, INPUT);
  pinMode(outSensor, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(GND,OUTPUT);
  digitalWrite(GND,LOW);
  digitalWrite(LED_1, LOW); // LED ON

  //Print beginning message on LCD Display
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   Welcome!!!   ");
  lcd.setCursor(0,1);
  lcd.print("  ---IDEALAB---  ");
  delay(3000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Bidirectional  ");
  lcd.setCursor(0,1);
  lcd.print("Visitor Counter");
  delay(3000);
}
 
void loop()
{
//  inStatus =  digitalRead(inSensor);  // Read IR Sensor 1 Output
//  outStatus = digitalRead(outSensor); // Read IR Sensor 1 Output
  if(digitalRead(inSensor)==1)// this condition will become true if, first sensor o/p will become HIGH at first.

    {
      while(digitalRead(outSensor)==0);// this condition will wait until the second sensor o/p becomes HIGH.
      in = countin++;
      while(digitalRead(outSensor)==1);// this condition will wait until the second sensor o/p becomes LOW.    
      digitalWrite(LED_1, HIGH); //LED ON
      delay(500);
      digitalWrite(LED_1, LOW); 
        
    }
   else if(digitalRead(outSensor)==1)// this condition will become true if, secont sensor o/p will become HIGH at first.
    {
      while(digitalRead(inSensor)==0);// this condition will wait until the first sensor o/p becomes HIGH.
//      if(count!=0)// this condition will stop the decreament, once if the count reaches 0.
      out = countout++;
      while(digitalRead(inSensor)==1);// this condition will wait until the first sensor o/p becomes LOW. 
      digitalWrite(LED_1, HIGH); //LED ON
      delay(500);
      digitalWrite(LED_1, LOW);
    }     
  //calculate currently visitors present inside the place
  now = in - out;

  //Function for when no visitors inside the room
  if (now <= 0)
  {
    digitalWrite(R1, LOW); //LED ON
    digitalWrite(R2, LOW); 
    //Print Data on LCD Display
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("   No Visitor  ");

    lcd.setCursor(0,1);
    lcd.print("IN:");
    lcd.setCursor(4,1);
    lcd.print(in);

    lcd.setCursor(8,1);
    lcd.print("OUT:");
    lcd.setCursor(13,1);
    lcd.print(out);
    delay(500);
  }

  // Function for when visitors entering and exiting
  else
  {
    digitalWrite(R1, HIGH); //LED ON
    digitalWrite(R2, HIGH); 
        
    //Print Data on LCD Display
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("IN:");
    lcd.setCursor(4,0);
    lcd.print(in);

    lcd.setCursor(8,0);
    lcd.print("OUT:");
    lcd.setCursor(13,0);
    lcd.print(out);

    lcd.setCursor(0,1);
    lcd.print("Current = ");
    lcd.setCursor(9,1);
    lcd.print(now);
    delay(500);
  }
}
