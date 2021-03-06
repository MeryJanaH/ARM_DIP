
/*****Meryem ANNOUAR***04/09/21***/

#include "FreeRTOS.h"
#include "uart.h"
#include "task.h"
#include "FreeRTOSConfig.h"

/* Define the strings that will be passed in as the task parameters. These are
defined const and not on the stack to ensure they remain valid when the tasks are
executing. */
static const char *pcTextForTask1 = "FTask 1 is running\r\n";
static const char *pcTextForTask2 = "STask 2 is running\r\n";
void vTask( void *pvParameters );

int main( void )
{
uart_init (9600,16000000UL);
	
/* Create one of the two tasks. */
xTaskCreate (vTask,"Task 1",100,(void*)pcTextForTask1, 1, NULL ); 
/* Create the other task in exactly the same way. Note this time that multiple tasks are being created from the SAME task implementation (vTask). Only the value passed in the parameter is different. Two instances of the same task are being created. */
xTaskCreate (vTask, "Task 2",100, (void*)pcTextForTask2, 2, NULL );
/* Start the scheduler so our tasks start executing. */
vTaskStartScheduler();
/* If all is well then main() will never reach here as the scheduler will
now be running the tasks. If main() does reach here then it is likely that
there was insufficient heap memory available for the idle task to be created.*/
while( 1 );
}

/* Task code */
void vTask( void *pvParameters )
{
  
 TickType_t pxPreviousWakeTime1;
 TickType_t pxPreviousWakeTime2;
 
char *pcTaskName;

pcTaskName = ( char * ) pvParameters;

  if(pcTaskName[0] == 'S')
  {
    pxPreviousWakeTime2 = xTaskGetTickCount(); // 0  23 300 323 600 623  
  }
  else if(pcTaskName[0] == 'F')
  {
    pxPreviousWakeTime1 = xTaskGetTickCount()-18; // 0  23 300 323 600 623  
  }

  /* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
  {
  /* Print out the name of this task. */
  uart_write_string( pcTaskName );
    /* Delay for a period. */
    if(pcTaskName[0] == 'S')
    {
    vTaskDelayUntil(&pxPreviousWakeTime2,200);
    }
    else if(pcTaskName[0] == 'F')
    {
    vTaskDelayUntil(&pxPreviousWakeTime1,350);
    }
  }
}


