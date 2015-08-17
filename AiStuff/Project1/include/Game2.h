
/*-----------------------------------------------------------------------------
Author:			
Description:	
-----------------------------------------------------------------------------*/
#ifndef GAME2_H
#define GAME2_H

#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__)
#define new DBG_NEW
#endif

#include "Application.h"
#include "MathLib.h"

using namespace MathLib;

class SpriteBatch;
class Font;
class Warrior;
class Archer;

class Game2 : public Application
{
public:

	// assets loaded in constructor
	Game2(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title);

	// assets destroyed in destructor
	virtual ~Game2();

	// update / draw called each frame automaticly
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	SpriteBatch *m_spritebatch;

private:


	Warrior * m_Warrior;
	Archer * m_Archer;

};

#endif