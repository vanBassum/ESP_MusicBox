#pragma once

/* Littlevgl specific */
#include "lvgl/lvgl.h"
#include "control.h"
#include "../lib/Misc/Callback.h"




namespace LVGL
{
	
	class Button : public Control
	{
	public:
		Callback<void, Button*> OnClick;
		
	private:
		static void Clicked(lv_obj_t * sender, lv_event_t event)
		{
			
			ESP_LOGI("Test", "Plep");
			
			Button* btn = (Button*)sender->ptrObj;
			if (btn->OnClick.IsBound())
				btn->OnClick.Invoke(btn);
		}
		
	public:
		Button(Control& parent)
		{
			lvglMutex->Take();
			handle = lv_btn_create(parent.GetHandle(), NULL);
			handle->ptrObj = this;
			lv_obj_set_pos(handle, 10, 10);  
			lv_obj_set_size(handle, 120, 50);
			lv_obj_set_event_cb(handle, &Button::Clicked);
			lvglMutex->Give();
		}
	};
}
