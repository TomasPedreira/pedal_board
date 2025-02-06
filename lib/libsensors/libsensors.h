#ifndef LIBSENSORS_H
#define LIBSENSORS_H

// Include necessary libraries
#include <Arduino.h>
#include <random>

uint32_t read_accel1();
uint32_t read_accel2();
uint32_t read_break_line_pressure();

void read_pedal_sensors(double* accel1, double* accel2, double* break_line_pressure, uint32_t resolution);

void send_data_to_dashboard(double accel1, double accel2, double break_line_pressure);

#endif // LIBSENSORS_H