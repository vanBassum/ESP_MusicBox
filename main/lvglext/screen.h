#pragma once


/* Littlevgl specific */
#include "lvgl/lvgl.h"
#include "widget.h"

namespace LVGL
{
	class Screen : public Widget
	{
	public:
		Screen()
		{
			handle = lv_scr_act();
		}
		
		//Multiple screens
		
	};	
}












