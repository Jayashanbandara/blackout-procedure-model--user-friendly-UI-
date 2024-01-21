
//Power Station
int lax_unit=22;
int samanala=23;
int koth_unit=24;
int up_koth=25;
int pol_unit=26;
int lak_unit=27;
int rest_subs=28;

//Transmission line
int koth_cct_2=2;
int koth_cct_1=3;
int koth_anu=4;
int athu_thul=6;
int kol_kos=7;
int rest220KV=9;
int rest132KV=8;

int stage_1=32;
int stage_2=33;
int stage_3=34;
int stage_4=35;

//int stage_5=26;
int tot_black_out=27;


void setup() {
  Serial.begin(9600);
  setArduinoPinModes();
}

void loop() {
  // put your main code here, to run repeatedly:
  //controllingStations("button102FF");
   if (Serial.available()) {
    String receivedString = Serial.readStringUntil('\n');
    Serial.println("Received: " + receivedString);
    
    controllingStations(receivedString);
   }
}


void setArduinoPinModes(){
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(28,OUTPUT);

  pinMode(32,OUTPUT); 
  pinMode(33,OUTPUT);
  pinMode(34,OUTPUT);
  pinMode(35,OUTPUT);


  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(28,HIGH);
  digitalWrite(32,HIGH);
  digitalWrite(33,HIGH);
  digitalWrite(34,HIGH);
  digitalWrite(35,HIGH);



}

int extractNumber(String str) {
  //Serial.println(str );
  String numStr = "";
  int len = str.length();
  for (int i = 0; i < len; i++) {
    char c = str.charAt(i);
    //Serial.println(c );    
    if (isdigit(c)) {
      numStr += c;
    } 
  }
    int num = numStr.toInt();
    return num;
}

void powerOnOffStation(int powerStation, int state){
    if(state==1){
        digitalWrite(powerStation, HIGH);
    }else if(state==0){
        digitalWrite(powerStation, LOW);
    }
}

void powerOffAll(int state){
    powerOnOffStation(koth_unit, state);
    powerOnOffStation(lak_unit, state);
    powerOnOffStation(lax_unit, state);
    powerOnOffStation(pol_unit, state);
    powerOnOffStation(samanala, state);
    powerOnOffStation(up_koth, state);
    powerOnOffStation(rest_subs, state);

    powerOnOffStation(athu_thul, state);
    powerOnOffStation(koth_anu, state);
    powerOnOffStation(kol_kos, state);
    powerOnOffStation(rest220KV,state);
    powerOnOffStation(rest132KV,state);
    

    powerOnOffStation(stage_1, state);
    powerOnOffStation(stage_2, state);
    powerOnOffStation(stage_3, state);
    powerOnOffStation(stage_4, state);
    //powerOnOffStation(stage_5, state);
    
}

void controllingStations(String receivedString){

    int extractedNum = extractNumber(receivedString);
    //Serial.println(extractedNum );
    int state = 0;
    if (extractedNum%2==0){
        state = 1;
    }else{
        extractedNum = extractedNum - 1;
    }

  if(extractedNum == 100){
    powerOnOffStation(koth_cct_2, !state);
   // Serial.println("ON " );
  }else if(extractedNum == 126){
    powerOnOffStation(koth_anu, !state);
  }else if(extractedNum == 136){
    powerOnOffStation(kol_kos, !state);
  }else if(extractedNum == 124){
    powerOnOffStation(athu_thul, !state);
  }else if(extractedNum == 102){
    powerOnOffStation(koth_cct_1, !state);
  }else if(extractedNum == 166){
    powerOnOffStation(rest220KV, !state);
  }else if(extractedNum == 168){
    powerOnOffStation(rest132KV, !state);
  }else if(extractedNum == 104){
    powerOnOffStation(koth_unit, state);
  }else if(extractedNum == 110){
    powerOnOffStation(lak_unit, state);
  }else if(extractedNum == 114){
    powerOnOffStation(lax_unit, state);
  }else if(extractedNum == 134){
    powerOnOffStation(pol_unit, state);
  }else if(extractedNum == 128){
    powerOnOffStation(samanala, state);
  }else if(extractedNum == 132){
    powerOnOffStation(up_koth, state);
  }else if(extractedNum == 170){
    powerOnOffStation(rest_subs, !state);
  }else if(extractedNum == 140){
    powerOnOffStation(stage_1, !state);
  }
  else if(extractedNum == 142){
    powerOnOffStation(stage_2, !state);
  }else if(extractedNum == 144){
    powerOnOffStation(stage_3, !state);
  }else if(extractedNum == 146){
    powerOnOffStation(stage_4, !state);
  }else if(extractedNum == 150){
    powerOffAll(state);
  }
}
