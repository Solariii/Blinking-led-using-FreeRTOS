#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "HwAb.h"
#include "BlinkingLED_SWC.h"
#include "PushButton_SWC.h"


void Task_100ms(void *pvParameters);
void Task_1000ms(void *pvParameters);

uint8_t task_100ms_runnables_n = 1; 
void (*task_100ms_runnables[])(void) = {run_poll_pushbutton};

uint8_t task_1000ms_runnables_n = 1; 
void (*task_1000ms_runnables[])(void) = {run_blink_led};
	
void SystemInit(void){
	Clk_Init();
	PushButton_Init();
	RGB_LED_Init();
}

int main(void){
	SystemInit();
	
	xTaskCreate(Task_100ms, "Task_100ms", 200, NULL, 1, NULL);
	xTaskCreate(Task_1000ms, "Task_1000ms", 200, NULL, 1, NULL);
	
	vTaskStartScheduler();
	
	// should not reach this line as line 30 doesn`t return
	while(1);
}

void Task_100ms(void *pvParameters) {
	uint8_t task_100ms_runnables_itr; 
	while(1) {
		for(task_100ms_runnables_itr = 0;task_100ms_runnables_itr < task_100ms_runnables_n;task_100ms_runnables_itr++){
			(*task_100ms_runnables[task_100ms_runnables_itr])();
		}
		vTaskDelay(100 / portTICK_RATE_MS);
	}
}
void Task_1000ms(void *pvParameters) {
	uint8_t task_1000ms_runnables_itr; 
	while(1) {
		for(task_1000ms_runnables_itr = 0;task_1000ms_runnables_itr < task_1000ms_runnables_n;task_1000ms_runnables_itr++){
			(*task_1000ms_runnables[task_1000ms_runnables_itr])();
		}
		vTaskDelay(1000 / portTICK_RATE_MS);
	}
}
