

#define d1 2
#define d2 3
#define d3 4
#define d4 5
#define d5 6
#define d6 7
#define d7 8
#define d8 9
#define d9 10
const int pot1InPin = A4;  // Analog input pin that the potentiometer 1 is attached to
const int pot2InPin = A5;  // Analog input pin that the potentiometer 2 is attached to

int P1sensorValue = 0;        // value read from the pot
int P1outputValue = 0;        // value output to the PWM (analog out)

int P2sensorValue = 0;        // value read from the pot
int P2outputValue = 0;        // value output to the PWM (analog out)

byte ledDelay =  1;
byte framedelay = 5;
byte fps =  8;


// PATTER DEFINITIONS - bottom, middle, top 
int Wall_Y_Left[3][3][3] = { 
                     { 
                     
                     {0,0,1}, 
                     {0,0,1}, 
                     {0,0,1}   },{ 
                     
                     {0,0,1},
                     {0,0,1}, 
                     {0,0,1}   },{
                     
                     {0,0,1}, 
                     {0,0,1}, 
                     {0,0,1}   
                     }
                 };

int Wall_Y_Middle[3][3][3] = { 
                     { 
                     
                     {0,1,0}, 
                     {0,1,0}, 
                     {0,1,0}   },{ 
                     
                     {0,1,0},
                     {0,1,0}, 
                     {0,1,0}   },{
                     
                     {0,1,0}, 
                     {0,1,0}, 
                     {0,1,0}   
                     }
                 };

int Wall_Y_Right[3][3][3] = { 

                     { 
                     
                     {1,0,0}, 
                     {1,0,0}, 
                     {1,0,0}   },{ 
                     
                     {1,0,0},
                     {1,0,0}, 
                     {1,0,0}   },{
                     
                     {1,0,0}, 
                     {1,0,0}, 
                     {1,0,0}   
                     }
                 };

int Wall_X_Top[3][3][3] = { 

                     { 
                     
                     {1,1,1}, 
                     {0,0,0}, 
                     {0,0,0}   },{ 
                     
                     {1,1,1},
                     {0,0,0}, 
                     {0,0,0}   },{
                     
                     {1,1,1}, 
                     {0,0,0}, 
                     {0,0,0}   
                     }
                 };

int Wall_X_Middle[3][3][3] = { 

                     { 
                     
                     {0,0,0}, 
                     {1,1,1}, 
                     {0,0,0}   },{ 
                     
                     {0,0,0},
                     {1,1,1}, 
                     {0,0,0}   },{
                     
                     {0,0,0}, 
                     {1,1,1}, 
                     {0,0,0}   
                     }
                 };

int Wall_X_Bottom[3][3][3] = { 

                     { 
                     
                     {0,0,0}, 
                     {0,0,0}, 
                     {1,1,1}   },{ 
                     
                     {0,0,0},
                     {0,0,0}, 
                     {1,1,1}   },{
                     
                     {0,0,0}, 
                     {0,0,0}, 
                     {1,1,1}   
                     }
                 };

int Wall_Diag_Left[3][3][3] = { 

                     { 
                     
                     {0,0,1}, 
                     {0,1,0}, 
                     {1,0,0}   },{ 
                     
                     {0,0,1},
                     {0,1,0}, 
                     {1,0,0}   },{
                     
                     {0,0,1}, 
                     {0,1,0}, 
                     {1,0,0}   
                     }
                 };

int Wall_Diag_Right[3][3][3] = { 

                     { 
                     
                     {1,0,0}, 
                     {0,1,0}, 
                     {0,0,1}   },{ 
                     
                     {1,0,0},
                     {0,1,0}, 
                     {0,0,1}   },{
                     
                     {1,0,0}, 
                     {0,1,0}, 
                     {0,0,1}   
                     }
                 };

int Floor_Bottom[3][3][3] = { 

                     { 
                     
                     {0,0,0}, 
                     {0,0,0}, 
                     {0,0,0}   },{ 
                     
                     {0,0,0},
                     {0,0,0}, 
                     {0,0,0}   },{
                     
                     {1,1,1}, 
                     {1,1,1}, 
                     {1,1,1}   
                     }
                 };
int Floor_Middle[3][3][3] = { 

                     { 
                     
                     {0,0,0}, 
                     {0,0,0}, 
                     {0,0,0}   },{ 
                     
                     {1,1,1}, 
                     {1,1,1}, 
                     {1,1,1}   },{
                     
                     {0,0,0}, 
                     {0,0,0}, 
                     {0,0,0}   
                     }
                 };

int Floor_Top[3][3][3] = { 

                     { 
                     
                     {1,1,1}, 
                     {1,1,1}, 
                     {1,1,1}   },{ 
                     
                     {0,0,0}, 
                     {0,0,0}, 
                     {0,0,0}   },{
                     
                     {0,0,0}, 
                     {0,0,0}, 
                     {0,0,0}   
                     }
                 };


int Floor_X_Diag_Left[3][3][3] = { 
                     { 
                     {0,0,1}, 
                     {0,0,1}, 
                     {0,0,1}   },{ 
                     
                     {0,1,0}, 
                     {0,1,0}, 
                     {0,1,0}   },{
                     
                     {1,0,0}, 
                     {1,0,0}, 
                     {1,0,0}   
                     }
                 };

int Floor_X_Diag_Right[3][3][3] = { 
                     { 
                     {1,0,0}, 
                     {1,0,0}, 
                     {1,0,0}   },{ 
                     
                     {0,1,0}, 
                     {0,1,0}, 
                     {0,1,0}   },{
                     
                     {0,0,1}, 
                     {0,0,1}, 
                     {0,0,1}   
                     }
                 };
int Floor_Y_Diag_Left[3][3][3] = { 
                     { 
                     {1,1,1}, 
                     {0,0,0}, 
                     {0,0,0}   },{ 
                     
                     {0,0,0}, 
                     {1,1,1}, 
                     {0,0,0}   },{
                     
                     {0,0,0}, 
                     {0,0,0}, 
                     {1,1,1}   
                     }
                 };

int Floor_Y_Diag_Right[3][3][3] = { 
                     { 
                     {0,0,0}, 
                     {0,0,0}, 
                     {1,1,1}   },{ 
                     
                     {0,0,0}, 
                     {1,1,1}, 
                     {0,0,0}   },{
                     
                     {1,1,1}, 
                     {0,0,0}, 
                     {0,0,0}   
                     }
                 };
// END OF PATTERN DEFINITIONS

void setup()
{
    
    for (int i=0;i<11;i++)
    {
        pinMode(i,OUTPUT);    // PINS0-10 are set as output
    }
    pinMode(A0,OUTPUT);    //PIN A0 set as output
    pinMode(A1,OUTPUT);   // PIN A1 set as output
    pinMode(A2,OUTPUT);   // PIN A2 set as output
    
    digitalWrite(A0,HIGH);    //pull up the A0 pin
    digitalWrite(A1,HIGH);   // pull up the A1 pin
    digitalWrite(A2,HIGH);   // pull up the A2 pin



    Serial.begin(9600);
      /* add setup code here, setup code runs once when the processor starts */
}
void SelectBottom() {
  // ** SELECT'S THE BOTTOM LAYER - grounding bottom anode ** //
  digitalWrite(A2, HIGH);   
  digitalWrite(A1, LOW);   
  digitalWrite(A0, HIGH);
}
void SelectMiddle() {
 // ** SELECT THE Middle LAYER ** //
  digitalWrite(A2, LOW);   
  digitalWrite(A1, HIGH);    
  digitalWrite(A0, HIGH);
}
void SelectTop() { 
 // ** SELECTS THE TOP LAYER ** //
  digitalWrite(A2, HIGH);  
  digitalWrite(A1, HIGH);   
  digitalWrite(A0, LOW);    
}
void blinkd(int pin, int interval) {
  digitalWrite(pin, HIGH);
  delay(interval);
  digitalWrite(pin, LOW);
  
}
void TopRow(byte one,byte two,byte three){

 if (one == 1)   {blinkd(d1,ledDelay);} else { digitalWrite(d1,LOW);};
 if (two == 1)   {blinkd(d2,ledDelay);} else { digitalWrite(d2,LOW);};
 if (three == 1) {blinkd(d3,ledDelay);} else { digitalWrite(d3,LOW);};
 
};
void MiddleRow(byte four,byte five,byte six){

 if (four == 1) {blinkd(d4,ledDelay);} else { digitalWrite(d4,LOW);};
 if (five == 1) {blinkd(d5,ledDelay);} else { digitalWrite(d5,LOW);};
 if (six == 1)  {blinkd(d6,ledDelay);} else { digitalWrite(d6,LOW);};
};
void BottomRow(byte seven,byte eight,byte nine){

 if (seven == 1) {blinkd(d7,ledDelay);} else { digitalWrite(d7,LOW);};
 if (eight == 1) {blinkd(d8,ledDelay);} else { digitalWrite(d8,LOW);};
 if (nine == 1)  {blinkd(d9,ledDelay);} else { digitalWrite(d9,LOW);};
};

void frame(int a[3][3][3]){
/* Rendering a full frame, using a pre-determined arrays defined earlier.
My TODO here is to do nested loops to fill up arrays keys in ***Row() function calls
 */

SelectBottom();      TopRow( a[0][0][0], a[0][0][1], a[0][0][2]);
                  MiddleRow( a[0][1][0], a[0][1][1], a[0][1][2]);
                  BottomRow( a[0][2][0], a[0][2][1], a[0][2][2]);

SelectMiddle();      TopRow( a[1][0][0], a[1][0][1], a[1][0][2]);
                  MiddleRow( a[1][1][0], a[1][1][1], a[1][1][2]);
                  BottomRow( a[1][2][0], a[1][2][1], a[1][2][2]);

SelectTop();         TopRow( a[2][0][0], a[2][0][1], a[2][0][2]);
                  MiddleRow( a[2][1][0], a[2][1][1], a[2][1][2]);
                  BottomRow( a[2][2][0], a[2][2][1], a[2][2][2]);
ReadControls();
delay(framedelay); //HOW FAST IT GOES TO NEXT FRAME
};

// READY TO USE ANIMATIONS [UpandDown and Elwator are the same, one on the has to be removed to save space]
void RA_Spinning() {

    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_Diag_Left)    ;}   
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_X_Middle)     ;}  
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_Diag_Right)   ;} 
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_Y_Middle)     ;} 
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_Diag_Left)    ;}  
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_X_Middle)     ;}  
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_Diag_Right)   ;}
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_Y_Middle)     ;}

}
void RA_LeftRight() {
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_Y_Left);   } 
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_Y_Middle); } 
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_Y_Right);  } 
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_Y_Middle); } 
     
    
}
void RA_Spin() {
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_Diag_Right) ;}    
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_X_Middle)   ;}  
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_Diag_Left)  ;} 
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_X_Middle)   ;} 
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_Diag_Right) ;}  
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_X_Middle)   ;}
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_Diag_Left)  ;} 
    for(int ramka = 0; ramka < fps; ramka++){   frame(Wall_X_Middle)   ;}
   
}
void RA_TopBottom() {
    for(int ramka = 0; ramka <fps; ramka++){   frame(Wall_X_Top)     ;}  
    for(int ramka = 0; ramka <fps; ramka++){   frame(Wall_X_Middle)  ;}  
    for(int ramka = 0; ramka <fps; ramka++){   frame(Wall_X_Bottom)  ;}  
    for(int ramka = 0; ramka <fps; ramka++){   frame(Wall_X_Middle)  ;}

    for(int ramka = 0; ramka <fps; ramka++){   frame(Wall_X_Top)     ;}  
    for(int ramka = 0; ramka <fps; ramka++){   frame(Wall_X_Middle)  ;}  
    for(int ramka = 0; ramka <fps; ramka++){   frame(Wall_X_Bottom)  ;}  
    for(int ramka = 0; ramka <fps; ramka++){   frame(Wall_X_Middle)  ;} 

     
}
void RA_UpDown(){
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_Bottom);} 
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_Middle);}
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_Top);}
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_Middle);}    
};
void RA_Elevator() {
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_Bottom);} 
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_Middle);}
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_Top);}
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_Middle);}
}
void RA_Diagonals() {
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_X_Diag_Left);} 
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_Middle);}
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_X_Diag_Right);}
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_Middle);}
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_Y_Diag_Left);}
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_Middle);}
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_Y_Diag_Right);}
    for(int ramka = 0; ramka < fps; ramka++){   frame(Floor_Middle);} 



}


void ReadControls() {
      // read the analog in value:
  P1sensorValue = analogRead(pot1InPin);
  P2sensorValue = analogRead(pot2InPin);
  
  // map it to the range of the analog out:
  P1outputValue = map(P1sensorValue, 0, 1023, 0, 100); // last parameter is the upper limit for value, max is 255 but we need only 100 for delays
  P2outputValue = map(P2sensorValue, 0, 1023, 1, 100);
  // print the resummmmmmmmmmmmmonitolts to the serial monitor:
  Serial.print("P1 sensor = ");
  Serial.print(P1sensorValue);
  Serial.print("\t P1 output = ");
  Serial.println(P1outputValue);
  Serial.print("P2 sensor = ");
  Serial.print(P2sensorValue);
  Serial.print("\t P2 output = ");
  Serial.println(P2outputValue);
  Serial.println(" ");
  ledDelay = P1outputValue;
  framedelay = P2outputValue;
  delay(2);


}

void loop() {

    RA_Spinning();    
    RA_Spinning();    
    RA_Spinning();    
    RA_LeftRight();   
    RA_LeftRight();   
    RA_LeftRight();   
    RA_Spin();         
    RA_Spin();         
    RA_Spin();         
    RA_TopBottom();    
    RA_TopBottom();    
    RA_TopBottom();    
    RA_UpDown();    
    RA_UpDown();    
    RA_UpDown();    
    RA_Elevator();  
    RA_Elevator();  
    RA_Elevator();  
    RA_Diagonals(); 
    RA_Diagonals(); 
    
/** DEBUG TO SERIAL FRAME CODE 
Serial.println("FRAME BEGIN");
for(int q = 0; q < 3; q++) // RAMKI
{
  Serial.println();
   for(int w = 0; w < 3; w++) // WARSTWY
         {
          Serial.println();
            for(int e = 0; e < 3; e++) // LEDY
                    {
                    String keycode = String(" ") + q + " " + w + " " + e+" ";  
                    Serial.print Wall_Left[q][w][e]);Serial.print("   ");
                                    
                                        
                                   
                    }

  
         }

  
//
Serial.println("\nFRAME END LAYER UP");
}
Serial.println("\nNEXT FRAME \n\n\n\n");
*/
        

}

