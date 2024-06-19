#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
float t, h;

#define LDRPIN 13
int l;

#define HUMPIN 33
int hum;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  Serial.println("Comienza el dht");

  pinMode(13, INPUT);
  Serial.println("LDR conectado");

  pinMode(33, INPUT);
  Serial.println("Pica de humedad Conectada");
}

void loop() {
  // put your main code here, to run repeatedly:
  t=dht.readTemperature();
  h=dht.readHumidity();

  if (isnan(h) || isnan(t)) {
    Serial.println("Lectura fallida");
    return;
  }

  l=analogRead(LDRPIN);

  hum=analogRead(HUMPIN);
  
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print("%  //  Temperatura: ");
  Serial.print(t);
  Serial.print("°C   //  "); 

  Serial.print("Nivel de luz: ");
  Serial.print(l);

  Serial.print("  //  Humedad del suelo:  ");
  Serial.println(hum);

  delay(120);
}
