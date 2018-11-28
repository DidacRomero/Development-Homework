#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "ElementGUI.h"
#include "GuiSprites.h"
#include "GUIText.h"



j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());

	iPoint testPoint = { 30,30 };
	SDL_Rect testRect = { 0,0, 270,777 };
	CreateElement(ElementType::SPRITE,testPoint,testRect,atlas);

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	bool ret = true;
	
	for (p2List_item<ElementGUI*>* item = ElementList.start; item; item = item->next)
	{
		ret = item->data->CleanUp();
		if (!ret)
			break;
	}
	
	
	return ret;

}


// const getter for atlas
const SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

void j1Gui::CreateElement(ElementType element, iPoint position, SDL_Rect &rect, SDL_Texture* tex, ButtonType button)
{

	ElementGUI*ElemGUI = nullptr;

	switch (element)
	{
		
	case ElementType::SPRITE:

		ElemGUI = new GuiSprites(element,position,rect,tex);

			break;

	case ElementType::TEXT:

		ElemGUI = new GUIText();
		
		break;



	}

	if (ElemGUI != nullptr)
		ElementList.add(ElemGUI);
	else
		LOG("ElemGUI is nullptr");

}
// class Gui ---------------------------------------------------

