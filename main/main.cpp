
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "lvglext/lvgl.h"


extern "C"{	
	void app_main();
}


void app_main() 
{

	LVGL::Screen screen = LVGL::Init();

	LVGL::Button btn(screen);	
	LVGL::Label label(btn);

	

    while(1)
        vTaskDelay(1000);
}
