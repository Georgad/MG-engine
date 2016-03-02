#include "GameLoop.h"
#include "Globals.h"
#include "Util.h"

#include "allegro5\allegro.h"
#include <allegro5\allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

MG::GameLoop::GameLoop()
{
	//==============================================
	//ALLEGRO INIT FUNCTIONS
	//==============================================
	al_init();
	display = al_create_display(WIDTH, HEIGHT); 
	al_clear_to_color(al_map_rgb(0, 0, 0));

	//==============================================
	//ADDON INSTALL
	//==============================================
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_image_addon();

	//==============================================
	//TIMER AND EVENT QUEUE INIT
	//==============================================
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

}

MG::GameLoop::~GameLoop()
{



	//==============================================
	//DESTROY OBJECTS
	//==============================================

	std::cout << "lel";
	//SHELL OBJECTS=================================

	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);

}

void MG::GameLoop::run()
{
	al_start_timer(timer);
	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//==============================================
		//INPUT
		//==============================================
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
				break;
			}
		}
		//==============================================
		//GAME UPDATE
		//==============================================
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			render = true;

			MG::update();


		}
		
		

		//==============================================
		//RENDER
		//==============================================
		if (render && al_is_event_queue_empty(event_queue))
		{
			render = false;

			MG::render();
		}
	}

}
