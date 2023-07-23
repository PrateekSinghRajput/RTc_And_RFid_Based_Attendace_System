//Prateek
//www.prateeks.in

#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>
#include <DS3231.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial sim(3, 2);


DS3231  rtc(SDA, SCL);

// Define check in time
const int checkInHour = 11;
const int checkInMinute = 50;
int userCheckInHour;
int userCheckInMinute;

String number = "+918830584864";
String number1 = "+91";
String number2 = "+91";
String number3 = "+91";
String number4 = "+91";


int state1 = 0;
int state2 = 0;
int state3 = 0;
int state4 = 0;
int state5 = 0;


#define buzzerPin  A1
#define yellow  7
#define green  6

#define RST_PIN    9
#define SDA_PIN    10

MFRC522 mfrc522(SDA_PIN, RST_PIN);


void setup() {

  //  lcd.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  Serial.begin(9600);
  sim.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  rtc.begin();

  pinMode(buzzerPin, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("    WELCOME    ");
  lcd.setCursor(0, 1);
  lcd.print("TO OUR PROJECT");
  delay(4000);
  lcd.clear();
}

void loop() {
  RTC();
  rfid();
}

void RTC()
{
  //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY
  //rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(1, 1, 2014);   // Set the date to January 1st, 2014
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Put Your Card to" );
  lcd.setCursor(0, 1);
  lcd.print("the Reader......");
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.print(rtc.getTimeStr());
  lcd.setCursor(0, 1);
  lcd.print("Date: ");
  lcd.print(rtc.getDateStr());
  delay(500);
  lcd.clear();

}

void rfid()
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Show UID on serial monitor
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  content.toUpperCase();


  if (content.substring(1) == "D2 73 04 E2" && state1 == 0) //change here the UID of the card/cards that you want to give access
  {
    beepON();
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print("Manas");
    lcd.setCursor(11, 1);
    digitalWrite(green, HIGH);
    delay(2000);
    digitalWrite(green, LOW);
    lcd.print("001");
    info();
    SendKamal();
    state1 = 1;
  }
  else if (content.substring(1) == "D2 73 04 E2" && state1 == 1) //change here the UID of the card/cards that you want to give access
  {
    beepON();
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print("Manas");
    lcd.setCursor(11, 1);
    digitalWrite(yellow, HIGH);
    delay(2000);
    digitalWrite(yellow, LOW);
    lcd.print("001");
    info();
    SendKamal();
    state1 = 0;
  }
  else if (content.substring(1) == "32 5A 06 E2" && state2 == 0) //change here the UID of the card/cards that you want to give access
  {
    beepON();
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print("Sameer");
    lcd.setCursor(11, 1);
    digitalWrite(green, HIGH);
    delay(2000);
    digitalWrite(green, LOW);
    lcd.print("002");
    info();
    SendJamal();
    state2 = 1;
  }
  else if (content.substring(1) == "32 5A 06 E2" && state2 == 1) //change here the UID of the card/cards that you want to give access
  {
    beepON();
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print("Sameer");
    digitalWrite(yellow, HIGH);
    delay(2000);
    digitalWrite(yellow, LOW);
    lcd.setCursor(11, 1);
    lcd.print("002");
    info();
    SendJamal();
    state2 = 0;
  }
  else if (content.substring(1) == "82 5B 43 3A" && state3 == 0) //change here the UID of the card/cards that you want to give access
  {
    beepON();
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print("Achyut");
    lcd.setCursor(11, 1);
    lcd.print("003");
    digitalWrite(green, HIGH);
    delay(2000);
    digitalWrite(green, LOW);
    info();
    SendAzad();
    state3 = 1;
  }
  else if (content.substring(1) == "82 5B 43 3A" && state3 == 1) //change here the UID of the card/cards that you want to give access
  {
    beepON();
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print("Achyut");
    lcd.setCursor(11, 1);
    lcd.print("003");
    digitalWrite(yellow, HIGH);
    delay(2000);
    digitalWrite(yellow, LOW);
    info();
    SendAzad();
    state3 = 0;
  }
  else if (content.substring(1) == "42 FA 07 E2" && state4 == 0) //change here the UID of the card/cards that you want to give access
  {
    beepON();
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print("Narottam");
    lcd.setCursor(11, 1);
    lcd.print("004");
    digitalWrite(green, HIGH);
    delay(2000);
    digitalWrite(green, LOW);
    info();
    SendAkib();
    state4 = 1;
  }
  else if (content.substring(1) == "42 FA 07 E2" && state4 == 1) //change here the UID of the card/cards that you want to give access
  {
    beepON();
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print("Narottam");
    lcd.setCursor(11, 1);
    lcd.print("004");
    digitalWrite(yellow, HIGH);
    delay(2000);
    digitalWrite(yellow, LOW);
    info();
    SendAkib();
    state4 = 0;
  }
  else if (content.substring(1) == "92 09 DF E1" && state5 == 0) //change here the UID of the card/cards that you want to give access
  {
    beepON();
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print("Manas");
    lcd.setCursor(11, 1);
    lcd.print("005");
    digitalWrite(green, HIGH);
    delay(2000);
    digitalWrite(green, LOW);
    info();
    SendNoman();
    state5 = 1;
  }
  else if (content.substring(1) == "92 09 DF E1" && state5 == 1) //change here the UID of the card/cards that you want to give access
  {
    beepON();
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.print("Manas");
    lcd.setCursor(11, 1);
    lcd.print("005");
    digitalWrite(yellow, HIGH);
    delay(2000);
    digitalWrite(yellow, LOW);
    info();
    SendNoman();
    state5 = 0;
  }
  else   {
    digitalWrite(buzzerPin, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ID : ");
    lcd.print("Unknown");
    lcd.setCursor(0, 1);
    lcd.print("Access denied");
    Serial.println(" Access denied");
    delay(1500);
    digitalWrite(buzzerPin, LOW);
    lcd.clear();
  }
}

void smsSend()
{
  lcd.setCursor(0, 0);
  lcd.print("SMS Sending");
  for (int x = 11; x < 16; x++)
  {
    lcd.setCursor(x, 0);
    lcd.print(".");
    delay(1000);
  }

}
void beepON()
{
  digitalWrite(buzzerPin, HIGH);
  delay(200);
  digitalWrite(buzzerPin, LOW);
  delay(100);
}
void info()
{
  lcd.setCursor(0, 0);
  lcd.print("Name : ");
  lcd.setCursor(0, 1);
  lcd.print("Roll No : ");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Authorized Access");
  delay(1000);
  lcd.clear();
}

void SendKamal()
{
  lcd.setCursor(0, 0);
  lcd.print("SMS Sending");
  sim.println("AT+CMGF=1");
  delay(1000);
  sim.println("AT+CMGS=\"" + number + "\"\r");
  delay(1000);
  if (state1 == 0) {
    const char kamal[] = " Manas Bishi is Present at School ";
    sim.print(kamal);
  }
  else if (state1 == 1) {
    const char kamal[] = " Manas Bishi is Out Of The School";
    sim.print(kamal);
  }
  delay(100);
  sim.println((char)26);
  smsSend();
}

void SendJamal()
{
  lcd.setCursor(0, 0);
  lcd.print("SMS Sending");
  sim.println("AT+CMGF=1");
  delay(1000);
  sim.println("AT+CMGS=\"" + number1 + "\"\r");
  delay(1000);
  if (state2 == 0) {
    const char Jamal[] = "Sameer Dwari is Present at School";
    sim.print(Jamal);
  }
  else if (state2 == 1) {
    const char Jamal[] = "Sameer Dwari is Out Of The School";
    sim.print(Jamal);
  }

  delay(100);
  sim.println((char)26);
  smsSend();
}
void SendAzad()
{
  lcd.setCursor(0, 0);
  lcd.print("SMS Sending");
  sim.println("AT+CMGF=1");
  delay(1000);
  sim.println("AT+CMGS=\"" + number2 + "\"\r");
  delay(1000);
  if (state3 == 0) {
    const char Azad[] = "Achyut Bishi is Present at School";
    sim.print(Azad);
  }
  else if (state3 == 1) {
    const char Azad[] = "Achyut Bishi is Out Of The School";
    sim.print(Azad);
  }

  delay(100);
  sim.println((char)26);
  smsSend();
}
void SendAkib()
{
  lcd.setCursor(0, 0);
  lcd.print("SMS Sending");
  sim.println("AT+CMGF=1");
  delay(1000);
  sim.println("AT+CMGS=\"" + number3 + "\"\r");
  delay(1000);
  if (state4 == 0) {
    const char Akib[] = "Narottam Sa is Present at School";
    sim.print(Akib);
  }
  else if (state4 == 1) {
    const char Akib[] = "Narottam Sa is Out Of The School";
    sim.print(Akib);
  }

  delay(100);
  sim.println((char)26);
  smsSend();
}
void SendNoman()
{
  lcd.setCursor(0, 0);
  lcd.print("SMS Sending");
  sim.println("AT+CMGF=1");
  delay(1000);
  sim.println("AT+CMGS=\"" + number4 + "\"\r");
  delay(1000);
  if (state5 == 0) {
    const char Noman[] = "Manas Bishi is Present at School";
    sim.print(Noman);
  }
  else if (state5 == 1) {
    const char Noman[] = "Manas Bishi is Out Of The School";
    sim.print(Noman);
  }

  delay(100);
  sim.println((char)26);
  smsSend();
}
