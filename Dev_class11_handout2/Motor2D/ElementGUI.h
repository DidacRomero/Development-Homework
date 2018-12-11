#ifndef __ELEMENTGUI_H__
#define __ELEMENTGUI_H__

#include "j1Gui.h"
#include "p2Point.h"
#include "p2List.h"
#include "SDL/include/SDL.h"  



class ElementGUI
{
public:

	ElementGUI(int id, ElementType Element, iPoint position, SDL_Rect rect, bool isStatic, bool draggable, bool interactable, bool invisible, SDL_Texture*tex = nullptr);



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

	virtual bool InteractionUpdate() { return true; }
	virtual void UpdatePos() {}

public:
	
	iPoint position;
	iPoint GlobalPosition;
	iPoint MousePos;
	iPoint LastMousePos;
	
	SDL_Rect rect;
	SDL_Rect InterRect;
	SDL_Texture*tex;

	ElementType type;

	bool isStatic;

	bool hovering;
	bool clicked;

	bool was_hovered;
	bool was_clicked;

	bool draggable;
	bool dragging;

	bool interactable;
	bool invisible;
	bool being_used;

	int id;

	ElementGUI*Parent;

};


#endif