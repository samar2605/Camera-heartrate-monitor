float currentTime,firstTime;
int count[6]={0};
static int flag=0;
int wave;
void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(10, INPUT); // Setup for leads off detection LO +
  pinMode(11, INPUT); // Setup for leads off detection LO -
  currentTime=millis();
  firstTime=millis();
  for(int i=0;i<6;i++){
    count[i]=0;
  }
  
}

void loop() {
  if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
    Serial.println('!');
  }
  else{
    // send the value of analog input 0:
      wave=analogRead(A0);
      Serial.println(wave);

       if(millis()-currentTime>=6000){
        currentTime=millis();
        if(millis()-firstTime>=60000){
          Serial.print("Heart rate(in bpm):");
          Serial.println(count[flag]);
          Serial.print("flag:");
          Serial.println(flag);
        }  
        
        count[flag]=0;
        flag++;
        if(flag>5)
          flag=0;       
      }
      if(wave>480)
      { for(int i=0;i<6;i++) 
          count[i]++;
      }
  }
  
  //Wait for a bit to keep serial data from saturating
  delay(10);
}