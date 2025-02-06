//plase make me the structure for the stm32 code using arduino framework

#include <Arduino.h>
#include <libsensors.h>

// extern "C" {
//   #include "stm32f4xx_hal.h"
// }


#define ACCEL1_PIN PA4
#define ACCEL2_PIN PA5
#define BREAK_LINE_PRESSURE_PIN PA6
#define RESOLUTION 12
#define SERIALSPEED 115200


int receive_can_packet(char* packet);

void setup() {
  pinMode(ACCEL1_PIN, INPUT);
  pinMode(ACCEL2_PIN, INPUT);
  pinMode(BREAK_LINE_PRESSURE_PIN, INPUT);
  Serial.begin(SERIALSPEED);
  analogReadResolution(RESOLUTION);
}

void loop() {
  uint32_t now = millis();
  char packet[16];
  if (receive_can_packet(packet) == 0) {
    // process_packet(packet);
  }
  double raw_accel_value_1;
  double raw_accel_value_2;
  double raw_break_pressure;
  read_pedal_sensors(&raw_accel_value_1, &raw_accel_value_2, &raw_break_pressure, RESOLUTION);
  // process_signal(accel_value_1, accel_value_2, break_pressure);
  send_data_to_dashboard(raw_accel_value_1, raw_accel_value_2, raw_break_pressure);;
  while(millis() - now < 1000);
}




