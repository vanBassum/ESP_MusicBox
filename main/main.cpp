
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "display.h"


extern "C"{	
	void app_main();
}


void app_main() 
{
    Display display;


    while(1)
        vTaskDelay(1000);
}
