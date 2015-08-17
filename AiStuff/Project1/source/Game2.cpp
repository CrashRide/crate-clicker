#include "Game2.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "IFeels.h"
#include <string>
#include "MathLib.h"
#include <time.h>
#include "IGladiboxer.h"
using namespace MathLib;
using namespace std;

Game2::Game2(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	srand(time(NULL));

	// Create sprite batch
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);

	

	m_Archer = new Archer(Stats(150.0, 35.0, 2.5, 250.0, 1400.0, 'A'));
	m_Warrior = new Warrior(Stats(200.0, 25.0, 1.5, 200.0, 75.0, 'W'));

	m_Archer->m_opponent = m_Warrior;
	m_Warrior->m_opponent = m_Archer;

	m_spritebatch->SetColumnMajor(true);

}

Game2::~Game2()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);

	delete m_Archer;
	delete m_Warrior;
}

void Game2::Update(float deltaTime)
{
	
	// BREAK ON SPACE
	if (GetInput()->WasKeyPressed(GLFW_KEY_SPACE)){
		cout << "." << endl;
	}

	m_Warrior->Update(deltaTime);
	m_Archer->Update(deltaTime);
}

void Game2::Draw()
{
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();

	// TODO: draw stuff.
	

	m_Archer->Draw(m_spritebatch);
	m_Warrior->Draw(m_spritebatch);


	m_spritebatch->End();

}