#include <stdint.h>
#include <stddef.h>
#include "contiki.h"
#include "sys/etimer.h"
#include "button-sensor.h"
#include "batmon-sensor.h"
#include "gpio.h"

#include <stdio.h>

/*---------------------------------------------------------------------------*/
#define BUF_SIZE 8
static int buffer[BUF_SIZE];
static int buf_c = 0;
static int min_t = 100;
static int max_t = 0;
static int tenta = 0;

static struct etimer et_sensor;
static struct etimer et_uart;
static struct etimer et_uart_minmax;

/*---------------------------------------------------------------------------*/
PROCESS(sensor_process, "Sensor process");
PROCESS(uart_process, "Serial process");
PROCESS(uart_process_minmax, "Serial process min max");

/*---------------------------------------------------------------------------*/
AUTOSTART_PROCESSES(&sensor_process,&uart_process,&uart_process_minmax);
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(sensor_process, ev, data)
{
  PROCESS_BEGIN();

  SENSORS_ACTIVATE(batmon_sensor);

     // enable output for the red LED
      GPIO_setOutputEnableDio(IOID_14, GPIO_OUTPUT_ENABLE);
      GPIO_setOutputEnableDio(IOID_13, GPIO_OUTPUT_DISABLE);
      GPIO_setOutputEnableDio(IOID_6, GPIO_OUTPUT_ENABLE);
      // turn on the red LED
      GPIO_setDio(IOID_14);

      etimer_set(&et_sensor, 1*CLOCK_SECOND); // a cada segundo

  while(1) {
      tenta=(unsigned int) GPIO_readDio(IOID_13);
          if (tenta==1) GPIO_setDio(IOID_6); else GPIO_clearDio(IOID_6);
    PROCESS_WAIT_EVENT();
    // toggle the red LED

    if(ev == PROCESS_EVENT_TIMER)  // se passou um segundo

    //if(ev == 142)
    {
        etimer_reset(&et_sensor); // reinicia timer
        GPIO_toggleDio(IOID_14);

        int val = batmon_sensor.value(BATMON_SENSOR_TYPE_TEMP); // lê sensor

        /* Insira seu código aqui */

        buffer[buf_c++]=val;
        if (buf_c>7) buf_c=0;
        if (min_t>val) min_t=val;
        if (max_t<val) max_t=val;
        printf("Leu %d\n", val);
    }

  }

  PROCESS_END();
}

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(uart_process, ev, data)
{
  PROCESS_BEGIN();

  /* Insira seu código aqui */
  etimer_set(&et_uart, 10*CLOCK_SECOND); // a cada 10 segundos
  // toggle the red LED
      //GPIO_toggleDio(IOID_4);

  while(1) {
    PROCESS_WAIT_EVENT();
    if(ev == PROCESS_EVENT_TIMER)  // se passaram 10 segundos
    {
        /* Insira seu código aqui */
        etimer_reset(&et_uart); // reinicia timer

        int avg = 0;
        for(int i=0;i<BUF_SIZE;i++) {
            avg += buffer[i];
        }
        avg = avg/BUF_SIZE;
        printf("Temperatura media: %d\n", avg);
    }
  }

  PROCESS_END();
  }

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(uart_process_minmax, ev, data)
{
  PROCESS_BEGIN();
  // toggle the red LED
      //GPIO_toggleDio(IOID_4);

  /* Insira seu código aqui */
  etimer_set(&et_uart_minmax, 20*CLOCK_SECOND); // a cada 20 segundos


  while(1) {
    PROCESS_WAIT_EVENT();
    if(ev == PROCESS_EVENT_TIMER)  // se passaram 20 segundos
    {
        /* Insira seu código aqui */
        etimer_reset(&et_uart_minmax); // reinicia timer

        printf("Temperatura maxima: %d  minima: %d\n", max_t, min_t);
        //printf("Temperatura minima: %d\n", min_t);
    }
  }

  PROCESS_END();
  }
