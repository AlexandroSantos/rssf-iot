#include <stdio.h>

#include "contiki.h"


PROCESS(hello_world_process, "Hello world process");
AUTOSTART_PROCESSES(&hello_world_process);

PROCESS_THREAD(hello_world_process, ev, data)
{
  PROCESS_BEGIN();

  /* Insira o codigo aqui */

<<<<<<< HEAD
  printf("Uma frase bem grande...\n");

=======
 printf("Figueira Maior do Estado\n");
>>>>>>> 52fe1e07288371613c36226da4c5f4cc79cd7801
  /************************/

  PROCESS_END();
}
