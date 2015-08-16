#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Graph.h"
#include "IFeels.h"
#include <string>
#include "MathLib.h"
#include <time.h>
#include "IGladiboxer.h"
using namespace MathLib;
using namespace std;

Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	srand(time(NULL));

	// Create sprite batch
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);

	// Create node texture.
	m_NodeTex = new Texture("./Images/nodeTexture.png");
	// Create graph.
	m_Graph = new Graph;
	m_Graph->directed = true;
	// Create font.
	m_font = new Font("./Fonts/arial_30px.fnt");

	m_nodeToolTip = Vector2(NULL, NULL);

	one = nullptr;
	two = nullptr;

	m_Archer = new Archer(Stats(150.0, 35.0, 2.5, 150.0, 320.0, 'A'), m_Warrior);
	m_Warrior = new Warrior(Stats(200.0, 25.0, 1.5, 100.0, 75.0, 'W'), m_Archer);

	m_Warrior->m_opponent = m_Archer;

	//o_player.SetPos(Vector2(200, 200));
	//o_player.m_objTexture = new Texture("./Images/box0_256.png");

	//s_enemy = new Smith(Vector2(320, 240.0f));
	//s_enemy->m_objTexture = new Texture("./Images/box0_256.png");
	//s_enemy->AddFeels(new FleeFeels(&o_player));
	//s_enemy->AddFeels(new WanderFeels(25.0f, s_enemy->m_objTexture->GetHeight()/10, 25.0f));
	
	m_spritebatch->SetColumnMajor(true);

	//feelSwitch[0] = false;
	//feelSwitch[1] = false;
	//feelSwitch[2] = false;

}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);

	//delete s_enemy;
	delete m_Archer;
	delete m_Warrior;
	delete m_NodeTex;
	delete m_Graph;
	delete m_font;
	delete one;
	delete two;
}

void Game1::Update(float deltaTime)
{
	Vector2 mouse;
	mouse = Vector2(Input::GetSingleton()->GetMouseX(), Input::GetSingleton()->GetMouseY());

	for (int i = 0; i < m_Graph->GetSize(); i++){
		// Check nodes against mouse position.
		if (((*m_Graph)[i]->data - mouse).Magnatude() < m_NodeTex->GetWidth() / 2){

			m_nodeToolTip = (*m_Graph)[i]->data;
			i = m_Graph->GetSize();
		}
		else
			m_nodeToolTip = Vector2(NULL, NULL);
	}

	// Add edge on left click.
	if (GetInput()->WasMouseButtonPressed(0)){
		if (one == nullptr){
			// Get node
			for (int i = 0; i < m_Graph->GetSize(); i++){
				// Check nodes against mouse position.
				if (((*m_Graph)[i]->data - mouse).Magnatude() < m_NodeTex->GetWidth() / 2){

					std::cout << "Node 1 set.\n";

					// Clicked Node
					one = (*m_Graph)[i];
					i = m_Graph->GetSize();
				}
			}

			if (one == nullptr){
				// Create node
				m_Graph->AddNode(mouse);
			}
		}
		else if (two == nullptr){
			// Get second node
			for (int i = 0; i < m_Graph->GetSize(); i++){
				// Check nodes against mouse position.
				if (((*m_Graph)[i]->data - mouse).Magnatude() < m_NodeTex->GetWidth() / 2){

					std::cout << "Node 2 set.\n";

					// Clicked Node
					two = (*m_Graph)[i];
					i = m_Graph->GetSize();

					std::cout << "Edge added.\n";

					// ADDEDGE
					m_Graph->AddEdge(one, two, Vector2(one->data - two->data).Magnatude());

					// Reset nodes.
					one = nullptr;
					two = nullptr;
				}
			}
		}
	}

	// Delete node on right click where mouse is.
	if (GetInput()->WasMouseButtonPressed(1)){
		// Get node
		for (int i = 0; i < m_Graph->GetSize(); i++){
			// Check nodes against mouse position.
			if (((*m_Graph)[i]->data - mouse).Magnatude() < m_NodeTex->GetWidth() / 2){

				std::cout << "Node " << i << " deleted.\n";

				m_Graph->RemoveNode((*m_Graph)[i]);
			}
		}
		one = nullptr;
		two = nullptr;
	}

	// RUN BFS ON SPACE
	if (GetInput()->WasKeyPressed(GLFW_KEY_SPACE)){
		//m_Graph->BFS((*m_Graph)[0]);
		//m_Graph->DSP((*m_Graph)[0], (*m_Graph)[m_Graph->GetSize() - 1]);
		//m_Graph->AStar((*m_Graph)[0], (*m_Graph)[m_Graph->GetSize() - 1]);
		cout << "." << endl;
	}

	m_Warrior->Update(deltaTime);
	m_Archer->Update(deltaTime);

	/*if (GetInput()->WasKeyPressed(GLFW_KEY_1))
	{
		s_enemy->AddFeels(new SeekFeels(&o_player, 0.5f));
		feelSwitch[0] = !feelSwitch[0];
	}
	if (GetInput()->WasKeyPressed(GLFW_KEY_2))
	{
		s_enemy->AddFeels(new FleeFeels(&o_player, 0.5f));
		feelSwitch[1] = !feelSwitch[1];
	}
	if (GetInput()->WasKeyPressed(GLFW_KEY_3))
	{
		s_enemy->AddFeels(new WanderFeels(25.0f, s_enemy->m_objTexture->GetHeight() / 10, 25.0f, 0.5f));
		feelSwitch[2] = !feelSwitch[2];
	}
	if (GetInput()->IsKeyDown(GLFW_KEY_W))
	{
		o_player.ApplyForce(Vector2(0, -500));
	}
	if (GetInput()->IsKeyDown(GLFW_KEY_A))
	{
		o_player.ApplyForce(Vector2(-500, 0));
	}
	if (GetInput()->IsKeyDown(GLFW_KEY_S))
	{
		o_player.ApplyForce(Vector2(0, 500));
	}
	if (GetInput()->IsKeyDown(GLFW_KEY_D))
	{
		o_player.ApplyForce(Vector2(500, 0));
	}
	o_player.Update(deltaTime);
	s_enemy->Update(deltaTime);*/
}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();

	// TODO: draw stuff.
	//o_player.Draw(m_spritebatch);
	//s_enemy->Draw(m_spritebatch);
	//m_Graph->Draw(m_NodeTex, m_spritebatch);

	if (one != nullptr){
		// Set red
		m_spritebatch->SetRenderColor(255, 0, 0, 255);

		// Draw circle.
		Vector2 oldPos = Vector2(one->data.x + cos(0.f) * m_NodeTex->GetWidth() / 2, one->data.y + sin(0.f) * m_NodeTex->GetWidth() / 2);

		for (float i = 0; i < 2 * 3.1457f; i += 3.1457f / 10.0f)
		{
			Vector2 newPos;

			newPos.x = one->data.x + (cos(i) * m_NodeTex->GetWidth() / 2);
			newPos.y = one->data.y + (sin(i) * m_NodeTex->GetWidth() / 2);

			m_spritebatch->DrawLine(oldPos.x, oldPos.y, newPos.x, newPos.y, 2.0f);

			oldPos = newPos;
		}

		// Set back.
		m_spritebatch->SetRenderColor(255, 255, 255, 255);
	}

	string x = "X: " + to_string(m_nodeToolTip.x);
	string y = "Y: " + to_string(m_nodeToolTip.y);
	x.erase(x.find_last_of('.'), string::npos);
	y.erase(y.find_last_of('.'), string::npos);
	x += " , ";


	m_spritebatch->DrawString(m_font, x.c_str(), GetWindowWidth() - 180, 50, 0.5f, 0.5f);
	m_spritebatch->DrawString(m_font, y.c_str(), GetWindowWidth() - 90, 50, 0.5f, 0.5f);
	//m_spritebatch->DrawString(m_font, " 1. Seek	\n 2. Flee \n 3. Wander", 50.0f, 50.0f, 0.0f,0.0f);

	m_Archer->Draw(m_spritebatch);
	m_Warrior->Draw(m_spritebatch);

	//float shiby = 20.0f;
	//for (int i = 0; i < 3; i++)
	//{
	//	if (feelSwitch[i])
	//		m_spritebatch->DrawString(m_font, "On", 205.0f, shiby+=30, 0.5f, 0.0f);
	//	else
	//		m_spritebatch->DrawString(m_font, "Off", 205.0f, shiby+=30, 0.5f, 0.0f);
	//}

	m_spritebatch->End();

}