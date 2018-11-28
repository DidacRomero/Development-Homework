#ifndef __ELEMENTGUI_H__
#define __ELEMENTGUI_H__

#include "j1Gui.h"
#include "p2Point.h"
#include "p2List.h"
#include "SDL/include/SDL.h"  



class ElementGUI
{
public:

	ElementGUI(ElementType Element,iPoint position, SDL_Rect rect, SDL_Texture*tex = nullptr);



	virtual ~ElementGUI();



	

	

protected:
	
	iPoint position;
	SDL_Rect rect;
	SDL_Texture*tex;

	ElementType type;

	p2List<ElementGUI> ElementList;

};


#endif