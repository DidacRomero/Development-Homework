#ifndef __BUTTONCLASS_H__
#define __BUTTONCLASS_H__

#include "ElementGUI.h"
#include "p2Point.h"


struct SDL_Rect;

class j2ButtonClass :public ElementGUI
{
public:
	j2ButtonClass(int id, const char* name, ElementType type, iPoint position, SDL_Rect &rect, bool isStatic, SDL_Texture* tex, bool draggable, bool interactable, bool invisible);


	~j2ButtonClass();



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
	bool InteractionUpdate() override;
	void UpdatePos() override;


public:

	iPoint MousePos;

	SDL_Rect hoveringRect;
	SDL_Rect clickedRect;
	
};




#endif 




