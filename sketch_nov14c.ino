#include <Adafruit_CircuitPlayground.h>
float X, Y, Z;


#include <FastLED.h>         //ws2812灯带头文件
#define LED_PIN1    A6       //灯带接2号IO口
#define NUM_LEDS1   143       //灯带数量12
CRGB leds1[NUM_LEDS1];     
uint8_t max_bright=255;      //亮度100（0-255可调）

static bool flag = false;
void setup() 
{
  Serial.begin(9600);
  CircuitPlayground.begin();
  FastLED.addLeds<WS2812, LED_PIN1, GRB>(leds1, NUM_LEDS1);
  FastLED.setBrightness(max_bright);
}

void loop()
{
  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();

  Serial.print("X: ");
  Serial.print(X);
  Serial.print("  Y: ");
  Serial.print(Y);
  Serial.print("  Z: ");
  Serial.println(Z);


  if(abs(Z)<=4 && flag==false)
  {
      for(int x=255;x>=0;x--)
      {
          for(int i=0;i<143;i++)      //灯带变色
          {
             leds1[i] = CRGB (x,0,0);
          }
         FastLED.show(); 
         delay(5);
     }
     flag = true;
     Serial.print("NO1");
  }
   
  else if(abs(Z)>=4 && flag==true)
    {
      for(int x=0;x<=255;x++)
      {
          for(int i=0;i<143;i++)      //灯带变色
          {
              leds1[i] = CRGB (x,0,0);
          }
          FastLED.show(); 
          delay(5);
      }     
      flag = false;   
      Serial.print("NO2");
  }

 


   delay(100);
}
