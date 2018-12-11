
#ifndef __GUISPRITES__H_
#define __GUISPRITES__H_

#include "ElementGUI.h"



class GuiSprites :public ElementGUI
{
public:

	GuiSprites(int id,ElementType type, iPoint position, SDL_Rect &rect, bool isStatic, SDL_Texture* tex, bool draggable, bool interactuable, bool invisible);

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

	bool InteractionUpdate() override;
	void UpdatePos() override;
public:


	void DisplaySprite();


};

#endif