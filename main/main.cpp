
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "lvglext/lvgl.h"
#include "esp_log.h"
#include "lvgl/lvgl.h"



LVGL::Label* label;


extern "C"{	
	void app_main();
}


void OnClick(LVGL::Widget* btn, lv_event_t event)
{
	static int cnt = 0;
	if (event == LV_EVENT_PRESSED)
	{
		label->SetText("hello %d", cnt++);
	}
}


void app_main() 
{
	LVGL::Screen screen = LVGL::Init();
	LVGL::Button btn(screen);	
	LVGL::Style style;
	
	label = new LVGL::Label(btn);
	

	
	btn.SetSize(200, 100);
	btn.SetPosition(50, 50);
	btn.SetCallback(&OnClick);
	
	label->SetText("hello");
	
	
	style.SetBackgroundColor();
	btn.AddStyle(style);
	
	
	//btn.OnPressed.Bind(&OnClick);

    while(1)
        vTaskDelay(1000);
}
