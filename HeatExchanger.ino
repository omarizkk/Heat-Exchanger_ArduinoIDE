#include <OneWire.h>                                           // initialize One Wire library
#include <DallasTemperature.h>                                 // initialize Dallas Tempreature library
#include <LiquidCrystal.h>                                     // initialize LCD library


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);                         // Digital pins to which LCD is connected



#define ONE_WIRE_BUS 6                                         // Data wire is plugged into digital pin 6 on the Arduino

OneWire oneWire(ONE_WIRE_BUS);                                 // Setup a oneWire instance to communicate with any OneWire device
  


DallasTemperature sensors(&oneWire);                           // Pass oneWire reference to DallasTemperature library



int deviceCount = 0;                                           // Variable to detect number of connected devices on the data bus
float tempC ;
float temp0 , temp1 , temp2 , temp3;

void setup(void)
{
  sensors.begin();
  lcd.begin(16,4);
  Serial.begin(9600);
  
  deviceCount = sensors.getDeviceCount();                     // Get number on connected sensors
}

void loop(void)
{ 
  
  sensors.requestTemperatures();                              // Send command to all the sensors for temperature conversion 
  
  
  for ( int i = 0 ;  i < deviceCount ;  i++ )                 // Display temperature from each sensor
  {
     Serial.print("Sensor ");
     Serial.print(i+1);
     Serial.print(" : ");
     tempC = sensors.getTempCByIndex(i);
     Serial.print(tempC);
     Serial.print("");
     Serial.print("C");
     Serial.print("\n");    


    if (i==0){      
      temp0 = sensors.getTempCByIndex(i);
      lcd.setCursor ( 0 , 0 ) ;
      lcd.print( "TC in = " ) ;
      lcd.print(temp0) ;
      lcd.print(" C") ;
    }
      
      if (i==1){
      
      temp1 = sensors.getTempCByIndex(i);
      lcd.setCursor ( 0 , 1 ) ;
      lcd.print( "TC out= " ) ;
      lcd.print(temp1) ;
      lcd.print(" C") ;
      }

      if (i==2){
      
      temp2 = sensors.getTempCByIndex(i);
      lcd.setCursor ( 0 , 2 ) ;
      lcd.print( "TH in = " );
      lcd.print(temp2);
      lcd.print(" C");
      }
   
      if (i==3){
    
      temp3 = sensors.getTempCByIndex(i);
      lcd.setCursor ( 0 , 3 ) ;
      lcd.print( "TH out= " ) ;
      lcd.print(temp3);
      lcd.print(" C");
      }
   
    /*Serial.print("Sensor ");
    Serial.print(i+1);
    Serial.print(" : ");
    tempC = sensors.getTempCByIndex(i);
    Serial.print(tempC);
    Serial.print();
    Serial.print("C");
    Serial.print("\n");
   */ 
  
  }
 
  delay(2000);
}
