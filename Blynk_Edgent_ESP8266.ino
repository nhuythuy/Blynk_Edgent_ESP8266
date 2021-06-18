
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLFGbhTB0L"
#define BLYNK_DEVICE_NAME "ThuyESP"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD

#include "BlynkEdgent.h"

long runtimeMinutes = 0;
float temp = 12.34;
float humidity = 56.78;
float systemHourMinute = 12.34;

#define VP_LR_RUNTIME                       V0
#define VP_SYSTEM_TIME                      V1

#define VP_LR_TEMPERATURE                   V2
#define VP_LR_HUMIDITY                      V3

BLYNK_READ(VP_LR_RUNTIME){
    Blynk.virtualWrite(VP_LR_RUNTIME, runtimeMinutes);
}

BLYNK_READ(VP_LR_TEMPERATURE){
  Blynk.virtualWrite(VP_LR_TEMPERATURE, temp);
}

BLYNK_READ(VP_LR_HUMIDITY){
  Blynk.virtualWrite(VP_LR_HUMIDITY, humidity);
}

BLYNK_READ(VP_SYSTEM_TIME){
  Blynk.virtualWrite(VP_SYSTEM_TIME, systemHourMinute);
}

#define MESSAGE_DELAY 50
// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void blynkTimerEvent()
{  
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  yield();
  Serial.println("Blynk timer triggered...");
  // for all signals to be sent at once

    Blynk.virtualWrite(VP_LR_RUNTIME, runtimeMinutes);
  delay(MESSAGE_DELAY);
  Blynk.virtualWrite(VP_SYSTEM_TIME, systemHourMinute);
  delay(MESSAGE_DELAY);
  Blynk.virtualWrite(VP_LR_TEMPERATURE, temp);
  delay(MESSAGE_DELAY);
  Blynk.virtualWrite(VP_LR_HUMIDITY, humidity);
  delay(MESSAGE_DELAY);
}

void setup()
{
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();

  timer.setInterval(2000L, blynkTimerEvent);

}

void loop() {
  BlynkEdgent.run();
  delay(500);
  runtimeMinutes++;
}
