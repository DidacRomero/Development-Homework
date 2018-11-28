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

	iPoint testPoint = { 300,40 };
	SDL_Rect testRect = { 485, 829, 328, 103 };
	CreateElement(ElementType::SPRITE,testPoint,testRect,atlas);

	iPoint textTestPoint = { 300,5 };
	SDL_Rect textTestRect= { 0,0, 300, 20 };
	CreateElement(ElementType::TEXT, textTestPoint, textTestRect,nullptr);

	bool ret = true;
	for (p2List_item<ElementGUI*>* item = ElementList.start; item; item = item->next)
	{
		ret = item->data->Awake();
		if (!ret)
			break;
	}

	return ret;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	bool ret = true;

	for (p2List_item<ElementGUI*>* item = ElementList.start; item; item = item->next)
	{
		ret = item->data->PostUpdate();
		if (!ret)
			break;
	}


	return ret;
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

		ElemGUI = new GuiSprites(element,position,rect,true, tex);

			break;

	case ElementType::TEXT:

		ElemGUI = new GUIText(element, position, rect,true, tex );
		
		break;



	}

	if (ElemGUI != nullptr)
		ElementList.add(ElemGUI);
	else
		LOG("ElemGUI is nullptr");

}
// class Gui ---------------------------------------------------

