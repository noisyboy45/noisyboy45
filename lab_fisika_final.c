#include<LiquidCrystal.h>
LiquidCrystal display1(13,12,7,6,5,4);
LiquidCrystal display2(11,10,7,6,5,4);

int timer1;
int timer2;
int timer3;
int timer4;

float Time1;
float Time2;

int titik1 = 0;
int titik2 = 0;
int titik3 = 0;
int titik4 = 0;

float jarak1 = 5.0;
float jarak2 = 5.0;
float kecepatan1;
float kecepatan2;
float percepatan;

float dv;
float dt;

int ir_s1 = A0;
int ir_s2 = A1;
int ir_s3 = A2;
int ir_s4 = A3;

void setup(){
     display1.begin(16,2);
     display2.begin(16,2);
     
     display1.setCursor(0,0);
          display1.print("Dibuat oleh:");
     display1.setCursor(0,1);
          display1.print("Aang Gunaifi");

     display2.setCursor(0,0);
          display2.print("Denissa P.A.");
     display2.setCursor(0,1);
          display2.print("Sindya L.T.");
     
     delay(3000);
     display1.clear();
     display2.clear();


}

void loop() {
if(digitalRead (ir_s1) == LOW && titik1==0){timer1 = millis(); titik1=1;}
if(digitalRead (ir_s2) == LOW && titik2==0){timer2 = millis(); titik2=1;}
if(digitalRead (ir_s3) == LOW && titik3==0){timer3 = millis(); titik3=1;}
if(digitalRead (ir_s4) == LOW && titik4==0){timer4 = millis(); titik4=1;}

if (titik1==1 && titik2==1){
     if(timer1 > timer2){Time1 = timer1 - timer2;}
     else if(timer2 > timer1){Time1 = timer2 - timer1;}
 Time1=Time1/1000;
 kecepatan1=(jarak1/Time1);

}

if (titik3==1 && titik4==1){
     if(timer3 > timer4){Time2 = timer3 - timer4;}
     else if(timer4 > timer3){Time2 = timer4 - timer3;}
 Time2=Time2/1000;
 kecepatan2=(jarak2/Time2);
}

if (titik2==1 && titik4==1){

     if(Time1 > Time2){dt = Time1 - Time2;}
     else if(Time2 > Time1){dt = Time2 - Time1;}

     if(kecepatan1 > kecepatan2){dv = kecepatan1 - kecepatan2;}
     else if(kecepatan2 > kecepatan1){dv = kecepatan2 - kecepatan1;}

     percepatan = dv / dt;

}

if(kecepatan1==0){ 
display1.setCursor(0, 1); 
if(titik1==0 && titik2==0){display1.print("Tidak Terdeteksi");}
                    else{display1.print("Searching...    ");} 
}

if(kecepatan2==0){ 
display2.setCursor(0, 1); 
if(titik1==0 && titik2==0){display2.print("Yang bener aja");}
                    else{display2.print("Searching...    ");} 
}





if(kecepatan1==0){ 
display1.setCursor(0, 0); 
if(titik1==0 && titik2==0){display1.print("Searching...    ");}
                    else{display1.print("Searching...    ");} 
}

if(kecepatan2==0){ 
display2.setCursor(0, 0); 
if(titik1==0 && titik2==0){display2.print("Searching...    ");}
                    else{display2.print("Searching...    ");} 
}





else{
    display1.clear(); 

    display1.setCursor(0, 0); 

    display1.print("V 1:");
    display1.print(kecepatan1,1);
    display1.print(" m/s");

    display1.setCursor(0, 1); 

    display1.print("V 2:");
    display1.print(kecepatan2,1);
    display1.print(" m/s");
    
     display2.clear(); 

    display2.setCursor(0, 0); 

    display2.print("delta t :");
    display2.print(dt,1);
    display2.print(" S");
 


    display2.setCursor(0, 1); 
    display2.print("a :");
    display2.print(percepatan,1);
    display2.print("m/s^2");
 

    
    delay(5000);
    kecepatan1 = 0;
    kecepatan2 = 0;
    titik1 = 0;
    titik2 = 0;
    titik3 = 0;
    titik4 = 0;

 }



}
