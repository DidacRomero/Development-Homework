#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "ElementGUI.h"
#include "j2GuiSprites.h"
#include "j2GUIText.h"
#include "j2ButtonClass.h"
#include "j2SliderGUI.h"



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
	elementIds = 0;
	atlas = App->tex->Load(atlas_file_name.GetString());

	SDL_Rect defaultRect = {0,0,0,0};

	iPoint testPoint = { 100,50 };
	SDL_Rect testRect = { 31, 544, 422, 448};
	const char* PanelText = "Window";
	Panel=CreateElement(elementIds, PanelText, ElementType::SPRITE, ElementAction::NONE,testPoint,testRect,defaultRect,atlas, true, ButtonType::NOT_BUTTON,nullptr,nullptr,true);

	iPoint textTestPoint = {190,20 };
	SDL_Rect textTestRect= { 0,0, 50, 20 };
	const char*Text = "Window";
	CreateElement(elementIds, Text, ElementType::TEXT, ElementAction::NONE, textTestPoint, textTestRect, defaultRect, nullptr,false,ButtonType::NOT_BUTTON,Text,Panel,false);



	iPoint ButtonTestPoint = { 100,100};
	SDL_Rect unHoveredRect = {2,112,226,64};
	CreateElement(elementIds, "Fade_Button", ElementType::BUTTON, ElementAction::FADE, ButtonTestPoint, unHoveredRect, defaultRect, atlas, true,ButtonType::DEFAULT, nullptr, Panel, true);

	iPoint ButtonTestPoint_2 = { 100, 200 };
	ElementGUI* RRButton = CreateElement(elementIds, "Rick Roll", ElementType::BUTTON, ElementAction::RICK_ROLL, ButtonTestPoint_2, unHoveredRect, defaultRect, atlas,true,ButtonType::DEFAULT, nullptr, Panel, true);

	iPoint RRtextTestPoint = { 50,20 };
	SDL_Rect RRtextTestRect = { 0,0, 100, 25 };
	const char* RRText = "Rick_Roll_Button";
	CreateElement(elementIds, RRText, ElementType::TEXT, ElementAction::NONE, RRtextTestPoint, RRtextTestRect, defaultRect, nullptr, false, ButtonType::NOT_BUTTON, RRText, RRButton, false);

	iPoint SlidertestPos = { 200, 500};
	SDL_Rect SlidertestRect = { 0, 12, 308, 12};
	CreateElement(elementIds, "Slider", ElementType::SLIDER, ElementAction::MUSIC_VOL, SlidertestPos, SlidertestRect, unHoveredRect, atlas, false, ButtonType::NOT_BUTTON, RRText, nullptr, false);


	bool ret = true;
	for (p2List_item<ElementGUI*>* item = ElementList.start; item; item = item->next)
	{
		ret = item->data->Awake();
		if (!ret)
			break;
	}
	
	if (ret)
	{
		for (p2List_item<ElementGUI*>* item = ElementList.start; item; item = item->next)
		{
			ret = item->data->Start();
			if (!ret)
				break;
		}
	}

	return ret;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	return true;
}

bool j1Gui::Update(float dt) {

	bool ret = true;
	//Check interactivity with the elements
	for (p2List_item<ElementGUI*>* item = ElementList.end; item; item = item->prev)
	{

			if (item->data->interactable == true && item->data->invisible == false)
			{
				ret = item->data->InteractionUpdate();
				if (!ret || item->data->being_used)
					break;
			}
	}
	//Do their update
	for (p2List_item<ElementGUI*>* item = ElementList.start; item; item = item->next)
	{
		if (item->data->invisible == false)
		{
				ret = item->data->Update();
		}
	}


	return ret;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	bool ret = true;

	for (p2List_item<ElementGUI*>* item = ElementList.start; item; item = item->next)
	{
		if (item->data->invisible == false)
		{
			ret = item->data->PostUpdate();
			item->data->debugDraw();
			if (!ret)
				break;
		}
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

ElementGUI*j1Gui::CreateElement(int id, const char* name, ElementType element, ElementAction action, iPoint position, SDL_Rect &rect, SDL_Rect &rect2, SDL_Texture* tex, bool interactable, ButtonType button,const char*Text,ElementGUI*Parent, bool draggable,bool invisible)
{

	ElementGUI*ElemGUI = nullptr;
	

	switch (element)
	{
		
	case ElementType::SPRITE:

		ElemGUI = new j2GuiSprites(id, name, element, action, position,rect,true, tex,draggable,interactable,invisible);
		elementIds++;
			break;

	case ElementType::TEXT:

		ElemGUI = new j2GUIText(id,name, element, action, position, rect,true, tex,Text,draggable,interactable, invisible);
		elementIds++;
		break;

	case ElementType::BUTTON:

		ElemGUI = new j2ButtonClass(id, name, element, action, button, position, rect, true, tex,draggable,interactable, invisible);
		elementIds++;
		break;

	case ElementType::SLIDER:
		ElemGUI = new j2SliderGUI(id, name, element, action, position, rect, rect2,  true, tex, draggable, interactable, invisible);
		elementIds++;
		break;
	}

	ElemGUI->Parent = Parent;

	if (ElemGUI->Parent != nullptr)
		ElemGUI->Parent->children.add(ElemGUI);

	if (ElemGUI != nullptr)
		ElementList.add(ElemGUI);
	else
		LOG("ElemGUI is nullptr");


	return ElemGUI;
}



