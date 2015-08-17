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




	s_enemy = new Smith(Vector2(320, 240.0f));
	s_enemy->SetScale(Vector2(0.2f, 0.2f));
	s_enemy->m_objTexture = new Texture("./Images/box0_256.png");
	s_enemy->m_maxVelo = 200.0f;

	
	m_spritebatch->SetColumnMajor(true);



}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);

	delete s_enemy;
	delete m_Graph;
	delete m_NodeTex;
	delete m_font;
	delete one;
	delete two;
}

void Game1::Update(float deltaTime)
{
	Vector2 mouse;
	mouse = Vector2((float)Input::GetSingleton()->GetMouseX(), (float)Input::GetSingleton()->GetMouseY());

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
		cout << "." << endl;
	}

	s_enemy->Update(deltaTime);
}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();

	// TODO: draw stuff.

	s_enemy->Draw(m_spritebatch);
	m_Graph->Draw(m_NodeTex, m_spritebatch);

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


	m_spritebatch->DrawString(m_font, x.c_str(), (float)GetWindowWidth() - 180, 50, 0.5f, 0.5f);
	m_spritebatch->DrawString(m_font, y.c_str(), (float)GetWindowWidth() - 90, 50, 0.5f, 0.5f);


	m_spritebatch->End();

}