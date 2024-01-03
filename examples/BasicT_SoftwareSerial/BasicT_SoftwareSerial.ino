#include "PMS.h"
#include <SoftwareSerial.h>

SoftwareSerial pmsSerial(14, 13); // SoftwareSerial(rxPin, txPin)
PMS pms(pmsSerial);
PMS::DATA data;

void setup()
{
  Serial.begin(115200);
  pmsSerial.begin(9600); // Software serial begin for PMS sensor
  Serial.println("");
  Serial.println("Start PMSx003T: ");
  delay(1000);
}

void loop()
{

  if (pms.readUntil(data))
  {
    Serial.print("PM 1.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_1_0);

    Serial.print("PM 2.5 (ug/m3): ");
    Serial.println(data.PM_AE_UG_2_5);

    Serial.print("PM 10.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_10_0);

    Serial.print("Temperature °C: ");
    Serial.print(data.TEMP);
    Serial.print("  -  round: ");
    Serial.println(round(TEMPround));
    
    Serial.print("Humidity %: ");
    Serial.print(data.HUMI);
    Serial.print("  -  round: ");
    Serial.println(round(HUMI));

    Serial.println();
  }

  // Do other stuff...
}