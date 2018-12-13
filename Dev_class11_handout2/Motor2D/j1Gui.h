#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "p2SString.h"
#include "p2List.h"
#include "p2Point.h"


#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes

// ---------------------------------------------------

class ElementGUI;
struct SDL_Texture;
struct SDL_Rect;


enum class ElementType
{
	BUTTON,
	TEXT,
	SPRITE,
	SLIDER,
	NOT_ELEMENT

};

enum class ButtonType {

	CHECKLIST,
	DEFAULT,
	SLIDER,
	NOT_BUTTON


};

class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();
	
	//Called to Update
	bool Update(float dt);
	
	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// TODO 2: Create the factory methods
	// Gui creation functions

	const SDL_Texture* GetAtlas() const;

	ElementGUI*CreateElement(int id, const char* name, ElementType element, iPoint position, SDL_Rect &rect, SDL_Rect &sliderButtonRect, SDL_Texture* tex, bool interactable, ButtonType button = ButtonType::NOT_BUTTON, const char*Text=nullptr,ElementGUI*Parent=nullptr, bool draggable = false, bool invisible = false);
	

	p2List<ElementGUI*> ElementList;

private:

	SDL_Texture* atlas;
	p2SString atlas_file_name;

	ElementGUI*Panel;

	int elementIds;

	
};

#endif // __j1GUI_H__