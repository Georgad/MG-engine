#pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5/allegro_primitives.h>



namespace MG
{
	class GameLoop
	{
		private:
			//==============================================
			//SHELL VARIABLES
			//==============================================
			bool done = false;
			bool render = false;


			//==============================================
			//ALLEGRO VARIABLES
			//==============================================
			ALLEGRO_DISPLAY *display;
			ALLEGRO_EVENT_QUEUE *event_queue;
			ALLEGRO_TIMER *timer;
	
		public:

			GameLoop();
			~GameLoop();

			void run();
	};
}