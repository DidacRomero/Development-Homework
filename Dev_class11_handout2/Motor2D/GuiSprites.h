
#ifndef __GUISPRITES__H_
#define __GUISPRITES__H_

#include "ElementGUI.h"



class GuiSprites :public ElementGUI
{
public:

	GuiSprites(ElementType type, iPoint position, SDL_Rect &rect, bool isStatic, SDL_Texture* tex );

	~GuiSprites();


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


public:



	void DisplaySprite();


};

#endif