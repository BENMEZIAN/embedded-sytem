//système fuites de gaz
int ledO = 2;
int ledV = 3;
int ledR = 4;
int capteurGaz = A1;
int gs;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledO,OUTPUT);
  pinMode(ledV,OUTPUT);
  pinMode(ledR,OUTPUT);
  pinMode(capteurGaz,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  gs = analogRead(capteurGaz);
  Serial.print("La valeur de gaz est :");
  Serial.println(gs);

  if(gs>=0 && gs<=120){
    Serial.println("Cas normal : niveau 1");
    Serial.println("**********************");
    digitalWrite(ledO,HIGH);
    digitalWrite(ledV,LOW);
    digitalWrite(ledR,LOW);

  }else if(gs>120 && gs<=200){
    Serial.println("Cas normal : niveau 2");
    Serial.println("**********************");
    digitalWrite(ledO,LOW);
    digitalWrite(ledV,HIGH);
    digitalWrite(ledR,LOW);
    
  }else if(gs>200){
    Serial.println("Cas anormal");
    Serial.println("**********************");
    digitalWrite(ledO,LOW);
    digitalWrite(ledV,LOW);
    digitalWrite(ledR,HIGH);
  }

  delay(1000);
  
}
