#ifndef APP_h
#define APP_h


#include "GlWindow.h"


class App : public GlWindow
{
	public:
		App();

		/*!
		*\brief Initialization des objets.
		*/
		bool initializeObjects();

		/*!
		*\brief Rendu de la sc?ne.
		*/
		void render();

		void keyPressEvent(QKeyEvent *);
};


#endif
