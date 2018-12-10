#ifndef __BUTTONCLASS_H__
#define __BUTTONCLASS_H__

#include "ElementGUI.h"
#include "p2Point.h"


struct SDL_Rect;

class ButtonClass :public ElementGUI
{
public:
	ButtonClass(int id,ElementType type, iPoint position, SDL_Rect &rect, bool isStatic, SDL_Texture* tex);


	~ButtonClass();



	bool Awake();
	//Start
	bool Start();
	//PreUpdate		
	bool PreUpdate();
	//Update		
	bool Update();
	//PostUpdate	
	bool PostUpdate();
	//CleanUp
	bool CleanUp();



	void DisplayButton();

public:

	iPoint MousePos;

	SDL_Rect hoveringRect;
	SDL_Rect clickedRect;
	SDL_Rect InterRect;
};




#endif 




