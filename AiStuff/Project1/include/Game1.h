
/*-----------------------------------------------------------------------------
Author:			
Description:	
-----------------------------------------------------------------------------*/
#ifndef GAME1_H
#define GAME1_H

#include "Application.h"
#include "MathLib.h"
#include "GameObj.h"
#include "Smith.h"
using namespace MathLib;

class SpriteBatch;
class Graph;
struct Node;
class Font;

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

protected:

	SpriteBatch *m_spritebatch;

private:

	// Graph Temp.
	Graph* m_Graph;
	Texture* m_NodeTex;
	Font* m_font;

	Vector2 m_nodeToolTip;

	// Temp Nodes for Edges
	Node* one;
	Node* two;

	GameObj o_player;
	Smith* s_enemy;


	bool feelSwitch[3];
};

#endif