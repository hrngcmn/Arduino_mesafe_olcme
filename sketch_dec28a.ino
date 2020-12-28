#define trig 2 // trig sensörün ses dalgası gönderen kısmı.D2 pinine bağlı.
#define echo 7 // echo sensörün ses dalgasını alan kısmıdır.D7 pinine bağlı.
#define buzzer 8 // buzzer 8. pine bağlı
long uzaklik ;
long sure;
void setup() {
  pinMode(trig,OUTPUT); // ses dalgasını gönderdiği için output.
  pinMode(echo,INPUT); // ses dalgasını aldığı için input.
  pinMode(buzzer,OUTPUT);  // sinyal çıkışı olduğu için output.
  Serial.begin(9600); // serial okuma yapılacak. 
}
void loop() {
  //digitalWrite(trig,LOW);
  //delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  sure = pulseIn(echo,HIGH); //echo pin Hıgh oluncaya kadar geçen zaman.
  uzaklik =(sure/2)/29.1;// ölçülen süre uzaklığa çevirildi.
  Serial.print("uzaklık: ");
  Serial.print(uzaklik);
  Serial.println("cm");
  delay(1000); // saniyede bir portta çıkış okumak için
  if(uzaklik >= 300) // uzaklığı ölçmesi için bir sınır koyuyorum.
    uzaklik = 300;
    
}
