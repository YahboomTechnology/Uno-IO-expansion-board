/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         On_board_IR.ino
* @author       Jessica
* @version      V1.0
* @date         2019.09.17
* @brief        On_board_IR
* @details
* @par History  
*
*/
#include "./IRremote.h"

enum {
  enSTOP = 0,
  enLIGHT,
  en0,
  en1,
  en2,
  en3,
  en4,
  en5,
  en6,
  en7,
  en8,
  en9,
  enPLUS,
  enLESS,
  enBEEP,
  enRUN,
  enBACK,
  enLEFT,
  enRIGHT,
  enTLEFT,
  enTRIGHT
} enCarState;


int RECV_PIN = 12; //IR reciving connect to Pin 12 of Arduino UNO
IRrecv irrecv(RECV_PIN);
decode_results results; //Object for storing the encoded result
unsigned long last = millis();

int g_carstate = enSTOP; 
int g_colorlight = 0;

/**
* Function       setup
* @author        Jessica
* @date          22019.09.17
* @brief         
* @param[in]     void
* @retval        void
* @par History   
*/
void setup()
{
  Serial.begin(9600);	//Baud rate 9600
  irrecv.enableIRIn(); 
  pinMode(RECV_PIN, INPUT_PULLUP);    
}


/**
* Function       IR_Deal
* @author        Jessica
* @date          22019.09.17
* @brief         IR_Deal
* @param[in]     void
* @retval        void
* @par History   
*/
void IR_Deal()
{
  if (irrecv.decode(&results))
  {
    //Serial.println(results.value, HEX);

    //button of the IR Controller
    //FF00FF  Power switch
    //FF807F  Advance
    //FF40BF  Light
    //FF20DF  Left
    //FFA05F  Beep
    //FF609F  Right
    //FF10EF  Turn left
    //FF906F  Back
    //FF50AF  Turn right
    //FF30CF  Plus
    //FFB04F  0
    //FF708F  Minus
    //FF08F7  Num 1
    //FF8877  Num 2
    //FF48B7  Num 3
    //FF28D7  Num 4
    //FFA857  Num 5
    //FF6897  Num 6
    //FF18E7  Num 7
    //FF9867  Num 8
    //FF58A7  Num 9    

      switch (results.value)
      {
        case 0X00FF00FF: g_carstate = enSTOP;  break;
        case 0X00FF40BF: g_carstate = enLIGHT;  break;
        case 0X00FFB04F: g_carstate = en0;  break;
        case 0X00FF08F7: g_carstate = en1;  break;
        case 0X00FF8877: g_carstate = en2;  break;
        case 0X00FF48B7: g_carstate = en3; break;
        case 0X00FF28D7: g_carstate = en4; break;
        case 0X00FFA857: g_carstate = en5; break;
        case 0x00FF6897: g_carstate = en6;  break;
        case 0x00ff18e7: g_carstate = en7; break;
        case 0x00ff9867: g_carstate = en8; break;
        case 0x00ff58a7: g_carstate = en9; break;
        case 0x00FF30CF: g_carstate = enPLUS;  break;
        case 0x00FF708F: g_carstate = enLESS; break;
        case 0x00FFA05F: g_carstate = enBEEP; break;
        case 0x00FF807F:  g_carstate = enRUN; break;
        case 0x00FF20DF:  g_carstate = enLEFT; break;
        case 0x00FF609F:  g_carstate = enRIGHT; break;
        case 0x00FF906F:  g_carstate = enBACK; break;
        case 0x00FF10EF:  g_carstate = enTLEFT; break;
        case 0x00FF50AF:  g_carstate = enTRIGHT; break;
        default: break; 

      }

    
    last = millis();
    irrecv.resume(); //Receive the next code
  }
  else if (millis() - last > 120)
  {
    g_carstate = enSTOP;
    last = millis();
  }

}

/**
* Function       loop
* @author        Jessica
* @date          22019.09.17
* @brief         
* @param[in]     void
* @retval        void
* @par History   
*/
void loop()
{
  IR_Deal();
  switch (g_carstate)
  {
    case enSTOP: break;
    case enLIGHT: Serial.println("LIGHT"); break; //Press light botton，serial port print"LIGHT"
    case en0: Serial.println("0"); break;         //Press 0 botton，serial port print 0
    case en1: Serial.println("1"); break;         //Press 1 botton，serial port print 1
    case en2: Serial.println("2"); break;         //Press 2 botton，serial port print 2
    case en3: Serial.println("3"); break;         //Press 3 botton，serial port print 3
    case en4: Serial.println("4"); break;         //Press 4 botton，serial port print 4
    case en5: Serial.println("5"); break;         //Press 5 botton，serial port print 5
    case en6: Serial.println("6"); break;         //Press 6 botton，serial port print 6
    case en7: Serial.println("7"); break;         //Press 7 botton，serial port print 7
    case en8: Serial.println("8"); break;         //Press 8 botton，serial port print 8
    case en9: Serial.println("9");break;          //Press 9 botton，serial port print 9
    case enPLUS: Serial.println("PLUS"); break;   //Press + botton，serial port print PLUS
    case enLESS: Serial.println("LESS"); break;   //Press - botton，serial port print LESS
    case enBEEP: Serial.println("BEEP"); break;   //Press beep botton，serial port print BEEP
    case enRUN: Serial.println("RUN"); break;     //Press advance botton，serial port print RUN 
    case enLEFT: Serial.println("LEFT"); break;   //Press left botton，serial port print LEFT
    case enRIGHT: Serial.println("RIGHT"); break; //Press right botton，serial port print RIGHT 
    case enBACK: Serial.println("BACK"); break;   //Press back botton，serial port print BACK 
    case enTLEFT:Serial.println("TLEFT"); break;  //Press spinleft botton，serial port print TLEFT
    case enTRIGHT:Serial.println("TRIGHT");break; //Press spinright botton，serial port print TRIGHT 
    default: break;
  }
  delay(500);
}
