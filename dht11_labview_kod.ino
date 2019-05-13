#include <DHT.h>
#include <DHT_U.h>

#include <dht11.h>
#define DHT11PIN 2
#define dhttype DHT11 //sensör tipi

dht11 DHT11;

char in;
int temp ;
int hum;

void setup() 
{
 Serial.begin(9600);


}

void loop() 
{ 
  if(Serial.available()>0)
  {
   in = (byte)Serial.read() & ~(0x20);

   if(in == 'T') // temp döndürmek
   {
     temp = dht11.readTemperature();  
    Serial.println("temp"); 
   }else if (in == 'H')
   {
    hum = DHT11.readHumidity();
    Seial.println(hum);
   }  
  }
}

