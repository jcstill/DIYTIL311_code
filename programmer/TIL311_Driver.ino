#define DIA A0
#define DIB A1
#define DIC A2
#define DID A3
#define RDP A4
#define LDP A5
 
#define HLD 3
#define BLNK 2

#define PRG 7
#define ERR 8
#define HRBT 9

void setup() {
  pinMode(DIA, OUTPUT);
  pinMode(DIB, OUTPUT);
  pinMode(DIC, OUTPUT);
  pinMode(DID, OUTPUT);
  pinMode(RDP, OUTPUT);
  pinMode(LDP, OUTPUT);
  pinMode(HLD, OUTPUT);
  pinMode(BLNK, OUTPUT);

  pinMode(PRG, OUTPUT);
  pinMode(ERR, OUTPUT);
  pinMode(HRBT, OUTPUT);

  digitalWrite(BLNK, LOW);
  digitalWrite(HLD, LOW);
  digitalWrite(LDP, HIGH);
  digitalWrite(RDP, HIGH);

  digitalWrite(DIA, LOW);
  digitalWrite(DIB, LOW);
  digitalWrite(DIC, LOW);
  digitalWrite(DID, LOW);
}

void loop() {
  // put your main code here, to run repeatedly
  

  digitalWrite(LDP, LOW);
  digitalWrite(RDP, HIGH);
  delay(500);
  digitalWrite(LDP, HIGH);
  digitalWrite(RDP, LOW);
  delay(500);
  digitalWrite(LDP, LOW);
  digitalWrite(RDP, LOW);
  delay(500);
  digitalWrite(LDP, HIGH);
  digitalWrite(RDP, HIGH);
  
  digitalWrite(BLNK, LOW);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, LOW);
  digitalWrite(DIB, LOW);
  digitalWrite(DIC, LOW);
  digitalWrite(DID, LOW);
  digitalWrite(HLD, LOW);
  delay(500);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, HIGH);
  digitalWrite(DIB, LOW);
  digitalWrite(DIC, LOW);
  digitalWrite(DID, LOW);
  digitalWrite(HLD, LOW);
  delay(500);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, LOW);
  digitalWrite(DIB, HIGH);
  digitalWrite(DIC, LOW);
  digitalWrite(DID, LOW);
  digitalWrite(HLD, LOW);
  delay(500);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, HIGH);
  digitalWrite(DIB, HIGH);
  digitalWrite(DIC, LOW);
  digitalWrite(DID, LOW);
  digitalWrite(HLD, LOW);
  delay(500);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, LOW);
  digitalWrite(DIB, LOW);
  digitalWrite(DIC, HIGH);
  digitalWrite(DID, LOW);
  digitalWrite(HLD, LOW);
  delay(500);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, HIGH);
  digitalWrite(DIB, LOW);
  digitalWrite(DIC, HIGH);
  digitalWrite(DID, LOW);
  digitalWrite(HLD, LOW);
  delay(500);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, LOW);
  digitalWrite(DIB, HIGH);
  digitalWrite(DIC, HIGH);
  digitalWrite(DID, LOW);
  digitalWrite(HLD, LOW);
  delay(500);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, HIGH);
  digitalWrite(DIB, HIGH);
  digitalWrite(DIC, HIGH);
  digitalWrite(DID, LOW);
  digitalWrite(HLD, LOW);
  delay(500);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, LOW);
  digitalWrite(DIB, LOW);
  digitalWrite(DIC, LOW);
  digitalWrite(DID, HIGH);
  digitalWrite(HLD, LOW);
  delay(500);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, HIGH);
  digitalWrite(DIB, LOW);
  digitalWrite(DIC, LOW);
  digitalWrite(DID, HIGH);
  digitalWrite(HLD, LOW);
  delay(500);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, LOW);
  digitalWrite(DIB, HIGH);
  digitalWrite(DIC, LOW);
  digitalWrite(DID, HIGH);
  digitalWrite(HLD, LOW);
  delay(500);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, HIGH);
  digitalWrite(DIB, HIGH);
  digitalWrite(DIC, LOW);
  digitalWrite(DID, HIGH);
  digitalWrite(HLD, LOW);
  delay(500);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, LOW);
  digitalWrite(DIB, LOW);
  digitalWrite(DIC, HIGH);
  digitalWrite(DID, HIGH);
  digitalWrite(HLD, LOW);
  delay(500);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, HIGH);
  digitalWrite(DIB, LOW);
  digitalWrite(DIC, HIGH);
  digitalWrite(DID, HIGH);
  digitalWrite(HLD, LOW);
  delay(500);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, LOW);
  digitalWrite(DIB, HIGH);
  digitalWrite(DIC, HIGH);
  digitalWrite(DID, HIGH);
  digitalWrite(HLD, LOW);
  delay(500);
  digitalWrite(HLD, HIGH);
  digitalWrite(DIA, HIGH);
  digitalWrite(DIB, HIGH);
  digitalWrite(DIC, HIGH);
  digitalWrite(DID, HIGH);
  digitalWrite(HLD, LOW);
  delay(500);

  
  digitalWrite(LDP, HIGH);
  digitalWrite(RDP, HIGH);
  digitalWrite(BLNK, HIGH);
  digitalWrite(PRG, HIGH);
  delay(500);
  digitalWrite(PRG, LOW);  
  digitalWrite(ERR, HIGH);
  delay(500);
  digitalWrite(ERR, LOW); 
  digitalWrite(HRBT, HIGH);
  delay(500);
  digitalWrite(HRBT, LOW); 
  
}
