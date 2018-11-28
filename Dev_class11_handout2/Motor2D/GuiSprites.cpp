#include "GuiSprites.h"
#include "j1App.h"
#include "j1Render.h"


GuiSprites::GuiSprites() : ElementGUI(type,position, rect,tex){


}


GuiSprites::~GuiSprites()
{
}


void GuiSprites::DisplaySprite() {


	App->render->Blit(tex, position.x, position.y,&rect);

}