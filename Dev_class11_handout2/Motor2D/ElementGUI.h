#ifndef __ELEMENTGUI_H__
#define __ELEMENTGUI_H__

#include "j1Gui.h"
#include "p2Point.h"
#include "p2List.h"
#include "SDL/include/SDL.h"  //CHANGE FIX




class ElementGUI
{
public:
	ElementGUI();


	virtual ~ElementGUI();



private:
	
	iPoint position;
	SDL_Rect rect;
	SDL_Texture*tex;

	ElementType type;

	//void CreateElement(ElementType element, ButtonType button = ButtonType::NOT_BUTTON);
	p2List<ElementGUI> ElementList;

};


#endif