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
#include "ButtonClass.h"



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

	iPoint testPoint = { 100,50 };
	SDL_Rect testRect = { 31, 544, 422, 448};
	Panel=CreateElement(elementIds,ElementType::SPRITE,testPoint,testRect,atlas, true, ButtonType::NOT_BUTTON,nullptr,nullptr,true);

	iPoint textTestPoint = {190,20 };
	SDL_Rect textTestRect= { 0,0, 50, 20 };
	const char*Text = "Window";
	CreateElement(elementIds,ElementType::TEXT, textTestPoint, textTestRect,nullptr,false,ButtonType::NOT_BUTTON,Text,Panel,false);



	iPoint ButtonTestPoint = { 100,100};
	SDL_Rect unHoveredRect = {2,112,226,64};
	CreateElement(elementIds, ElementType::BUTTON, ButtonTestPoint, unHoveredRect, atlas, true,ButtonType::DEFAULT, nullptr, Panel, true);

	iPoint ButtonTestPoint_2 = { 100, 200 };
	CreateElement(elementIds, ElementType::BUTTON, ButtonTestPoint_2, unHoveredRect, atlas,false,ButtonType::DEFAULT, nullptr, Panel, false);


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
	for (p2List_item<ElementGUI*>* item = ElementList.end; item; item = item->prev)
	{
		if (item->data->invisible == false)
		{
				ret = item->data->Update();
				if (!ret || item->data->being_used)
					break;
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

ElementGUI*j1Gui::CreateElement(int id,ElementType element, iPoint position, SDL_Rect &rect, SDL_Texture* tex, bool interactable, ButtonType button,const char*Text,ElementGUI*Parent, bool draggable,bool invisible)
{

	ElementGUI*ElemGUI = nullptr;
	

	switch (element)
	{
		
	case ElementType::SPRITE:

		ElemGUI = new GuiSprites(id,element,position,rect,true, tex,draggable,interactable,invisible);
		elementIds++;
			break;

	case ElementType::TEXT:

		ElemGUI = new GUIText(id,element, position, rect,true, tex,Text,draggable,interactable, invisible);
		elementIds++;
		break;

	case ElementType::BUTTON:

		ElemGUI = new ButtonClass(id,element, position, rect, true, tex,draggable,interactable, invisible);
		elementIds++;
		break;
	}

	ElemGUI->Parent = Parent;

	if (ElemGUI != nullptr)
		ElementList.add(ElemGUI);
	else
		LOG("ElemGUI is nullptr");


	return ElemGUI;
}



