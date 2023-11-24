

const long A = 1000, A2 = 1000;     //Resistencia en oscuridad en KΩ
const int B = 15, B2 = 15;        //Resistencia a la luz (10 Lux) en KΩ
const int Rc = 10, Rc2 = 10;       //Resistencia calibracion en KΩ
const int LDRPin = A0, LDRPin2 = A1;   //Pin del LDR

int V, V2;
int ilum, ilum2;

void setup() 
{
   Serial.begin(115200);
   pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
}

void loop()
{
   V = analogRead(LDRPin);         

   //ilum = ((long)(1024-V)*A*10)/((long)B*Rc*V);  //usar si LDR entre GND y A0 
   ilum = ((long)V*A*10)/((long)B*Rc*(1024-V));    //usar si LDR entre A0 y Vcc (como en el esquema anterior)
   Serial.println(ilum);
   if(ilum>5)
   digitalWrite(13, HIGH);
   else  
   digitalWrite(13, LOW);
   ////////////// sensor 2
      V = analogRead(LDRPin);         

   //ilum = ((long)(1024-V)*A*10)/((long)B*Rc*V);  //usar si LDR entre GND y A0 
   ilum = ((long)V*A*10)/((long)B*Rc*(1024-V));    //usar si LDR entre A0 y Vcc (como en el esquema anterior)
   Serial.println(ilum);
   if(ilum>5)
   digitalWrite(13, HIGH);
   else  
   digitalWrite(13, LOW);
   delay(100);
}