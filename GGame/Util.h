#pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5/allegro_primitives.h>

namespace MG 
{

	void input_handler()
	{}

	void update()
	{
		if (keys[LEFT])
		{
			
		}
		else if (keys[RIGHT])
		{
			
		}
		else if (keys[UP])
		{
		}
		else if (keys[DOWN])

		if (keys[SPACE]);


	}


	void render()
	{
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
	
	void init()
	{}


}