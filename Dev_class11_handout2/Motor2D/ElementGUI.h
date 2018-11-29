#ifndef __ELEMENTGUI_H__
#define __ELEMENTGUI_H__

#include "j1Gui.h"
#include "p2Point.h"
#include "p2List.h"
#include "SDL/include/SDL.h"  



class ElementGUI
{
public:

	ElementGUI(ElementType Element,iPoint position, SDL_Rect rect, bool isStatic, SDL_Texture*tex = nullptr);



	virtual ~ElementGUI();

	
	virtual bool Awake() { return true; }
	//Start
	virtual bool Start() { return true; }
	//PreUpdate		
	virtual bool PreUpdate() { return true; }
	//Update		
	virtual bool Update() { return true; }
	//PostUpdate	
	virtual bool PostUpdate() { return true; }
	//CleanUp
	virtual bool CleanUp() { return true; }

	

protected:
	
	iPoint position;
	SDL_Rect rect;
	SDL_Texture*tex;

	ElementType type;

	bool isStatic;

	bool hovering;
	bool clicked;

};


#endif