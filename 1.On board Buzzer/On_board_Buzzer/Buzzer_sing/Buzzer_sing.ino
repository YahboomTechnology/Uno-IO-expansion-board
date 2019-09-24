/*
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         Buzzer_sing
* @author       Jessica
* @version      V1.0
* @date         2019.8.21
* @brief        Buzzer_sing
* @details
* @par History  
*
*/
#define NTBL1 248
#define NTBL2 278
#define NTBL3 294
#define NTBL4 330
#define NTBL5 371
#define NTBL6 416
#define NTBL7 467

#define NTB1 495
#define NTB2 556
#define NTB3 624
#define NTB4 661
#define NTB5 742
#define NTB6 833
#define NTB7 935

#define NTBH1 990
#define NTBH2 1112
#define NTBH3 1178
#define NTBH4 1322
#define NTBH5 1484
#define NTBH6 1665
#define NTBH7 1869

#define NTCL1 131
#define NTCL2 147
#define NTCL3 165
#define NTCL4 175
#define NTCL5 196
#define NTCL6 221
#define NTCL7 248

#define NTC1 262
#define NTC2 294
#define NTC3 330
#define NTC4 350
#define NTC5 393
#define NTC6 441
#define NTC7 495

#define NTCH1 525
#define NTCH2 589
#define NTCH3 661
#define NTCH4 700
#define NTCH5 786
#define NTCH6 882
#define NTCH7 990

#define NTD0 -1
#define NTD1 294
#define NTD2 330
#define NTD3 350
#define NTD4 393
#define NTD5 441
#define NTD6 495
#define NTD7 556

#define NTDL1 147
#define NTDL2 165
#define NTDL3 175
#define NTDL4 196
#define NTDL5 221
#define NTDL6 248
#define NTDL7 278

#define NTDH1 589
#define NTDH2 661
#define NTDH3 700
#define NTDH4 786
#define NTDH5 882
#define NTDH6 990
#define NTDH7 1112

#define NTE1 330
#define NTE2 350
#define NTE3 393
#define NTE4 441
#define NTE5 495
#define NTE6 556
#define NTE7 624

#define NTEL1 165
#define NTEL2 175
#define NTEL3 196
#define NTEL4 221
#define NTEL5 248
#define NTEL6 278
#define NTEL7 312

#define NTEH1 661
#define NTEH2 700
#define NTEH3 786
#define NTEH4 882
#define NTEH5 990
#define NTEH6 1112
#define NTEH7 1248

int buzzer = 13;      //Buzzer connect Pin13 
//Ode
int tune[]=                
{
NTC3, NTC3, NTC4, NTC5, NTC5, NTC4, NTC3, NTC2, NTC1, NTC1, NTC2, NTC3, NTC3,NTC2, NTC2, 
 NTC3, NTC3, NTC4, NTC5, NTC5, NTC4, NTC3, NTC2, NTC1, NTC1, NTC2, NTC3, NTC2, NTC1, NTC1,
NTC2, NTC2, NTC3,NTC1, NTC2, NTC3, NTC4, NTC3, NTC1, NTC2, NTC3, NTC4, NTC3, NTC2,

NTC1, NTC2, NTCL5, NTC3, NTC3, NTC3, NTC4, NTC5, NTC5, NTC4, NTC3, NTC4, NTC2, NTC1, NTC1, NTC2, NTC3, 
 NTC2, NTC1,NTC1,
};

float durt[]= 
{
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 2, 0.5, 0.5, 1, 1, 1, 1, 1, 0.5, 0.5, 1, 1, 1, 0.5, 0.5, 1, 1,
0.5, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 1, 1, 1, 1, 2, 0.5, 0.5,
};

/*
//生日歌C
/*
int tune[]=                 //根据简谱列出各频率
{
NTC5, NTC5, NTC6, NTC5, NTCH1, NTC7, 
NTC5, NTC5, NTC6, NTC5, NTCH2, NTCH1, 
NTC5, NTC5, NTCH5, NTCH3, NTCH1, NTC7, NTC6, 
NTCH4, NTCH4, NTCH3, NTCH1, NTCH2, NTCH1,
};
float durt[]=                   //根据简谱列出各节拍
{
0.5, 0.5, 1, 1, 1, 2,
 0.5, 0.5, 1, 1, 1, 2,
 0.5, 0.5, 1, 1, 1, 1, 2,
 0.5, 0.5, 1, 1, 1, 2,
};
*/

void PlayTest()
{
 int length = sizeof(tune)/sizeof(tune[0]);   
 for(int x=0; x < length; x++)
  {
    tone(buzzer,tune[x]);
    delay(500*durt[x]);   
    //This is used to adjust the delay according to the beat. 
    //The 500 index can be adjusted by yourself. In this music, I found that it is more suitable to use 500.
    noTone(buzzer);
  }
}

void setup() 
{ 
  pinMode(buzzer,OUTPUT);
}

void loop() 
{ 
  PlayTest();
}

