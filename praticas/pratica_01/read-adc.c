#include "contiki.h"
#include "sys/etimer.h"
#include "sys/ctimer.h"
#include "dev/leds.h"
#include "dev/watchdog.h"
#include "random.h"
#include "dev/adc-sensor.h"
#include "button-sensor.h"
#include "batmon-sensor.h"
#include "board-peripherals.h"
#include "rf-core/rf-ble.h"

#include "ti-lib.h"

#include <stdio.h>
#include <stdint.h>

/*---------------------------------------------------------------------------*/

static struct etimer et_adc_sensor;

/*---------------------------------------------------------------------------*/

PROCESS(adc_process_sensor, "adc driver process");


AUTOSTART_PROCESSES( &adc_process_sensor);
/*---------------------------------------------------------------------------*/



PROCESS_THREAD(adc_process_sensor, ev, data)
{
  static struct sensors_sensor *sensor;
  static int rv;
  static float sane = 0;
  static int dec;
  static int frac;
  PROCESS_BEGIN();

  etimer_set(&et_adc_sensor, CLOCK_SECOND * 1);
  while(1) {

      PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et_adc_sensor));

      sensor = (struct sensors_sensor *) sensors_find(ADC_SENSOR);
      if(sensor) {
          SENSORS_ACTIVATE(*sensor);
          sensor->configure(ADC_SENSOR_SET_CHANNEL,ADC_COMPB_IN_AUXIO7);
          rv = sensor->value(ADC_SENSOR_VALUE);
          SENSORS_DEACTIVATE(*sensor);
          sane = rv /1000000;
          dec = sane;
          frac = ((float)rv /1000000 - dec)*100;
          printf("Tender ADC=%d.%02u V (%d)\n", dec, frac, rv);
      }
      else
      {
          printf("Sensor not found!\n");

      }
      etimer_reset(&et_adc_sensor);
  }

  PROCESS_END();
}
