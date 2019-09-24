/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         test
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Buzzer_test
* @details
* @par History  
*
*/
int buzzer = 13; //Buzzer connect Pin13 

void setup() 
{ 
  pinMode(buzzer,OUTPUT);//Set digital IO pin mode, OUTPUT is output
} 

void loop() 
{ 
  unsigned char i,j;
  for(i=0; i<80; i++) //Output a frequency of sound
  {
    digitalWrite(buzzer,HIGH);
    delay(1);
    digitalWrite(buzzer,LOW);
    delay(1);
  }
  for(i=0; i<100; i++)
  //Output another frequency of sound, 
  //Here 100 is the same as the previous 80, 
  //Used to control the frequency, Can adjusted by yourself
  {
    digitalWrite(buzzer,HIGH);
    delay(2);
    digitalWrite(buzzer,LOW);
    delay(2);
  }
}

