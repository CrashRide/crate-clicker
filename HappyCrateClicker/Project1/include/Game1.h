
/*-----------------------------------------------------------------------------
Author:			
Description:	
-----------------------------------------------------------------------------*/
#ifndef GAME1_H
#define GAME1_H

#include "Application.h"
#include "Buildings.h"
#include "Shop.h"
#include "Box.h"

class String;
class Box;
class Vector2;
class SpriteBatch;

class Game1 : public Application
{
public:

	// assets loaded in constructor
	Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title);

	// assets destroyed in destructor
	virtual ~Game1();

	// update / draw called each frame automaticly
	virtual void Update(float deltaTime);
	virtual void Draw();

	char ClickInput();

	void UpdateCPS(float &a_cps);

protected:

	SpriteBatch *m_spritebatch;

	Texture *m_crate;
	Texture *CursorBoxTexture;
	Texture	*GrandmaBoxTexture;
	Texture	*FarmBoxTexture;
	Texture	*FactoryBoxTexture;
	Texture	*MineBoxTexture;
	Texture	*ShipmentBoxTexture;
	Texture	*AlchemyLabBoxTexture;
	Texture	*PortalBoxTexture;
	Texture *TimeMachineBoxTexture;

	Texture *CursorBoxClickedTexture;
	Texture	*GrandmaBoxClickedTexture;
	Texture	*FarmBoxClickedTexture;
	Texture	*FactoryBoxClickedTexture;
	Texture	*MineBoxClickedTexture;
	Texture	*ShipmentBoxClickedTexture;
	Texture	*AlchemyLabBoxClickedTexture;
	Texture	*PortalBoxClickedTexture;
	Texture *TimeMachineBoxClickedTexture;

	Font *m_text;

	float m_crateCount;

	bool m_mouseCheck;

	float* m_cps;

	int* m_mouseX;
	int* m_mouseY;
	float m_mousePower;

	int textArr;
	int temp;

	float sizeMod;

	Buildings *Cursor;
	Buildings *Grandma;
	Buildings *Farm;
	Buildings *Factory;
	Buildings *Mine;
	Buildings *Shipment;
	Buildings *AlchemyLab;
	Buildings *Portal;
	Buildings *TimeMachine;

	Buildings** Builds;

	Box *CursorBox;
	Box *GrandmaBox;
	Box *FarmBox;
	Box *FactoryBox;
	Box *MineBox;
	Box *ShipmentBox;
	Box *AlchemyLabBox;
	Box *PortalBox;
	Box *TimeMachineBox;

	Shop *shop;

	Texture** BuildTexture;

	char** BuildNames;

private:
};

#endif