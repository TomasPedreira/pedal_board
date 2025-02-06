#include <libsensors.h>
#include <Arduino.h>
#include <random>
#include <math.h>

#define ACCEL1_PIN PA4
#define ACCEL2_PIN PA5
#define BREAK_LINE_PRESSURE_PIN PA6


/*********************************************************************************************************************************
 * @author Tomás Pedreira
 * @date 22/01/2025
 * @return raw value read from acceleration sensor 1
 * @brief Reads analog pin connected to the first acceleration sensor
 *********************************************************************************************************************************/
uint32_t read_accel1(){
  // return analogRead(ACCEL1_PIN);
  return random(0, 4095);
}
/*********************************************************************************************************************************
 * @author Tomás Pedreira
 * @date 22/01/2025
 * @return raw value read from acceleration sensor 2
 * @brief Reads analog pin connected to the second acceleration sensor
 *********************************************************************************************************************************/
uint32_t read_accel2(){
  // return analogRead(ACCEL2_PIN);
  return random(0, 4095);
}
/*********************************************************************************************************************************
 * @author Tomás Pedreira
 * @date 22/01/2025
 * @return raw value read from break line pressure sensor
 * @brief Reads analog pin connected to the break line pressure sensor
 *********************************************************************************************************************************/
uint32_t read_break_line_pressure(){
  // return analogRead(BREAK_LINE_PRESSURE_PIN);
  return random(0, 4095);
}


/*********************************************************************************************************************************
 * @author Tomás Pedreira
 * @date 23/01/2025
 * @param accel1 pointer to aceleration sensor value 1, [0, 2**res -1]
 * @param accel2 pointer to aceleration sensor value 2, [0, 2**res -1]
 * @param break_line_pressure pointer to break pressure sensor value, [0, 2**res -1]
 * @brief Reads analog pins connected to the 3 sensors to read (brake and 2 acceleration) and assigns the value to 3 variables, 
 * after mappong the values to the [0, 3.3V] range 
 *********************************************************************************************************************************/
void read_pedal_sensors(double* accel1, double* accel2, double* break_line_pressure, uint32_t resolution){

  // Maximum read value = 2**res -1, needs mapping to [0, 3.3V]
  *accel1 = (read_accel1()*3.3/(pow(2,resolution)-1));

  *accel2 = (read_accel2()*3.3/(pow(2,resolution)-1));

  *break_line_pressure = (read_break_line_pressure()*3.3/(pow(2,resolution)-1));

}

/*********************************************************************************************************************************
 * @author Tomás Pedreira
 * @date 22/01/2025
 * @param accel1 acceleration proccessed value 1
 * @param accel2 acceleration proccessed value 2
 * @param break_line_pressure break pressure proccessed value
 * @brief Sends the data to the sensor using something idk yet
 *********************************************************************************************************************************/
void send_data_to_dashboard(double accel1, double accel2, double break_line_pressure){
  Serial.print("Sending data to sensor: ");
  Serial.print("Accel1: ");
  Serial.print(accel1);
  Serial.print(" Accel2: ");
  Serial.print(accel2);
  Serial.print(" Break pressure: ");
  Serial.println(break_line_pressure);
}