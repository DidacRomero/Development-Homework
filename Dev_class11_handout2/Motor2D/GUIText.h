#ifndef __GUITEXT_H__
#define  __GUITEXT_H__

#include "ElementGUI.h"

struct _TTF_Font;

class GUIText :public ElementGUI
{


public:
	GUIText();
	
	~GUIText();


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
	void DisplayText();
	
private:

	const char*Text;
	SDL_Color ColorText;
	_TTF_Font*Textfont;

};

#endif