#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Box.h"
#include "Matrix3x3.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Scene.h"
#include <string>
#include <vector>
#include <iostream>
#include <windows.h>
using namespace std;

Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);
	m_crate = new Texture("./Images/happy_crate.png");
	tankBase = new Texture("./Images/tankBase.png");
	tankTurret = new Texture("./Images/tankTurret.png");
	
	m_cookie = new Texture("./Images/cookie32.png");

	CursorBoxTexture = new Texture("./Images/cursor.png");
	GrandmaBoxTexture = new Texture("./Images/grandma.png");
	FarmBoxTexture = new Texture("./Images/farm.png");
	FactoryBoxTexture = new Texture("./Images/factory.png");
	MineBoxTexture = new Texture("./Images/mine.png");
	ShipmentBoxTexture = new Texture("./Images/shipment.png");
	AlchemyLabBoxTexture = new Texture("./Images/alchemylab.png");
	PortalBoxTexture = new Texture("./Images/portal.png");
	TimeMachineBoxTexture = new Texture("./Images/timemachine.png");

	CursorBoxClickedTexture = new Texture("./Images/cursorClicked.png");
	GrandmaBoxClickedTexture = new Texture("./Images/grandmaClicked.png");
	FarmBoxClickedTexture = new Texture("./Images/farmClicked.png");
	FactoryBoxClickedTexture = new Texture("./Images/factoryClicked.png");
	MineBoxClickedTexture = new Texture("./Images/mineClicked.png");
	ShipmentBoxClickedTexture = new Texture("./Images/shipmentClicked.png");
	AlchemyLabBoxClickedTexture = new Texture("./Images/alchemylabClicked.png");
	PortalBoxClickedTexture = new Texture("./Images/portalClicked.png");
	TimeMachineBoxClickedTexture = new Texture("./Images/timemachineClicked.png");
	
	sizeMod = 1.0f;

	m_text = new Font("./Fonts/emulogic_16px.fnt");
	m_crateCount = 0.0f;
	m_mouseCheck = false;

	m_mouseX = new int(0);
	m_mouseY = new int(0);
	m_mousePower = 100.0;

	BuildNames = new char*[9];
	BuildNames[0] = "Cursor";
	BuildNames[1] = "Grandma";
	BuildNames[2] = "Farm";
	BuildNames[3] = "Factory";
	BuildNames[4] = "Mine";
	BuildNames[5] = "Shipment";
	BuildNames[6] = "Alchemy Lab";
	BuildNames[7] = "Portal";
	BuildNames[8] = "Time Machine";

	Cursor = new Buildings(0.1f, 15);
	Grandma = new  Buildings(0.5f, 100);
	Farm = new Buildings(4, 500);
	Factory = new Buildings(10, 3000);
	Mine = new Buildings(40, 10000);
	Shipment = new Buildings(100, 40000);
	AlchemyLab = new Buildings(400, 200000);
	Portal = new Buildings(6666, 1666666);
	TimeMachine = new Buildings(98765, 123456789);

	Builds = new Buildings*[9];
	Builds[0] = Cursor;
	Builds[1] = Grandma;
	Builds[2] = Farm;
	Builds[3] = Factory;
	Builds[4] = Mine;
	Builds[5] = Shipment;
	Builds[6] = AlchemyLab;
	Builds[7] = Portal;
	Builds[8] = TimeMachine;

	BuildTexture = new Texture*[9];
	BuildTexture[0] = CursorBoxTexture;
	BuildTexture[1] = GrandmaBoxTexture;
	BuildTexture[2] = FarmBoxTexture;
	BuildTexture[3] = FactoryBoxTexture;
	BuildTexture[4] = MineBoxTexture;
	BuildTexture[5] = ShipmentBoxTexture;
	BuildTexture[6] = AlchemyLabBoxTexture;
	BuildTexture[7] = PortalBoxTexture;
	BuildTexture[8] = TimeMachineBoxTexture;

	temp = 100;
	int m = 138;
	int h = CursorBoxTexture->GetHeight() / 2;
	int w = CursorBoxTexture->GetWidth() / 2;

	CursorBox = new Box(Vector2(temp - w, 100 - h), Vector2(temp + w, 100 + h));
	GrandmaBox = new Box(Vector2((temp += m) - w, 100 - h), Vector2(temp + w, 100 + h));
	FarmBox = new Box(Vector2((temp += m) - w, 100 - h), Vector2(temp + w, 100 + h));
	FactoryBox = new Box(Vector2((temp += m) - w, 100 - h), Vector2(temp + w, 100 + h));
	MineBox = new Box(Vector2((temp += m) - w, 100 - h), Vector2(temp + w, 100 + h));
	ShipmentBox = new Box(Vector2((temp += m) - w, 100 - h), Vector2(temp + w, 100 + h));
	AlchemyLabBox = new Box(Vector2((temp += m) - w, 100 - h), Vector2(temp + w, 100 + h));
	PortalBox = new Box(Vector2((temp += m) - w, 100 - h), Vector2(temp + w, 100 + h));
	TimeMachineBox = new Box(Vector2((temp += m) - w, 100 - h), Vector2(temp + w, 100 + h));

	v_tankBase = new Vector2(tankBase->GetWidth(), 720 - tankBase->GetHeight() / 2);
	

	m_tankBaseTransMat = new Matrix3x3(Vector3(1,0,0), Vector3(0,1,0), Vector3(v_tankBase->x,v_tankBase->y,1));
	m_ttGlobal = new Matrix3x3();
	m_tankTurretTransMat = new Matrix3x3();
	m_tankTurretTransMat->ScaleMat(1, 1.2);
	m_tankTurretTransMat->TranslateMat(-30, -6);

	tb = new SceneNode(m_tankBaseTransMat, m_tankBaseTransMat);
	tt = new SceneNode(m_tankTurretTransMat, m_ttGlobal);
	gameScene = new Scene(tb);

	tb->AddChild(tt);
	
	for (int i = 0; i < 3; i++)
	{
		cookieMunitions.push_back(new SceneNode(&Matrix3x3(), &Matrix3x3()));
		cookieMunitions[i]->GetLocal()->TranslateMat(75, 0);
		tt->AddChild(cookieMunitions[i]);
		v_cookieProjectile.push_back(Vector2(1, 1));
	}

	shop = new Shop(50);
	textArr = 0;
	temp = 100;
	m_cps = new float(0.0f);
	allInFlight = false;
	m_spritebatch->SetColumnMajor(true);
}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
	delete tankBase;
	delete tankTurret;
	delete v_tankBase;
	delete m_cookie;
	delete m_crate;
	delete m_text;
	delete m_mouseX;
	delete m_mouseY;
	delete m_cps;
	delete shop;
	cookieMunitions.~vector();
	v_cookieProjectile.~vector();
	delete tt;
	delete gameScene;

	delete Cursor;
	delete Grandma;
	delete Farm;
	delete Factory;
	delete Mine;
	delete Shipment;
	delete AlchemyLab;
	delete Portal;
	delete TimeMachine;

	delete CursorBoxTexture;
	delete GrandmaBoxTexture;
	delete FarmBoxTexture;
	delete FactoryBoxTexture;
	delete MineBoxTexture;
	delete ShipmentBoxTexture;
	delete AlchemyLabBoxTexture;
	delete PortalBoxTexture;
	delete TimeMachineBoxTexture;
	
	delete CursorBoxClickedTexture;
	delete GrandmaBoxClickedTexture;
	delete FarmBoxClickedTexture;
	delete FactoryBoxClickedTexture;
	delete MineBoxClickedTexture;
	delete ShipmentBoxClickedTexture;
	delete AlchemyLabBoxClickedTexture;
	delete PortalBoxClickedTexture;
	delete TimeMachineBoxClickedTexture;

	delete[] BuildTexture;
	delete[] Builds;
	delete[] BuildNames;

	delete CursorBox;
	delete GrandmaBox;
	delete FarmBox;
	delete FactoryBox;
	delete MineBox;
	delete ShipmentBox;
	delete AlchemyLabBox;
	delete PortalBox;
	delete TimeMachineBox;
}

char Game1::ClickInput()
{
	GetInput()->GetMouseXY(m_mouseX, m_mouseY);
	if (*m_mouseX > 511 && *m_mouseX < 769 && *m_mouseY > 231 && *m_mouseY < 489)
		return 'C';
	else if (CursorBox->ClickWithinBox(*m_mouseX, *m_mouseY))
		return 'K';
	else if (GrandmaBox->ClickWithinBox(*m_mouseX, *m_mouseY))
		return 'G';
	else if (FarmBox->ClickWithinBox(*m_mouseX, *m_mouseY))
		return 'B';
	else if (FactoryBox->ClickWithinBox(*m_mouseX, *m_mouseY))
		return 'F';
	else if (MineBox->ClickWithinBox(*m_mouseX, *m_mouseY))
		return 'M';
	else if (ShipmentBox->ClickWithinBox(*m_mouseX, *m_mouseY))
		return 'S';
	else if (AlchemyLabBox->ClickWithinBox(*m_mouseX, *m_mouseY))
		return 'A';
	else if (PortalBox->ClickWithinBox(*m_mouseX, *m_mouseY))
		return 'P';
	else if (TimeMachineBox->ClickWithinBox(*m_mouseX, *m_mouseY))
		return 'T';

	
}

void Game1::UpdateCPS(float &a_cps)
{
	a_cps = 0;
	for (int i = 0; i < 9; i++)
	{
		a_cps += Builds[i]->GetCPS();
	}
}

void Game1::Update(float deltaTime)
{
	m_crateCount += *m_cps * deltaTime;
	/*if (GetInput()->IsMouseButtonDown(0))
	{
		m_mouseCheck = true;
		switch (ClickInput())
		{
		case 'C':
		{
					sizeMod = 0.9f;
					break;
		}
		case 'K':
		{
					BuildTexture[0] = CursorBoxClickedTexture;
					break;
		}
		case 'G':
		{
					BuildTexture[1] = GrandmaBoxClickedTexture;
					break;
		}
		case 'B':
		{
					BuildTexture[2] = FarmBoxClickedTexture;
					break;
		}
		case 'F':
		{
					BuildTexture[3] = FactoryBoxClickedTexture;
					break;
		}
		case 'M':
		{
					BuildTexture[4] = MineBoxClickedTexture;
					break;
		}
		case 'S':
		{
					BuildTexture[5] = ShipmentBoxClickedTexture;
					break;
		}
		case 'A':
		{
					BuildTexture[6] = AlchemyLabBoxClickedTexture;
					break;
		}
		case 'P':
		{
					BuildTexture[7] = PortalBoxClickedTexture;
					break;
		}
		case 'T':
		{
					BuildTexture[8] = TimeMachineBoxClickedTexture;
					break;
		}
		default:
		{
				   BuildTexture[0] = CursorBoxTexture;
				   BuildTexture[1] = GrandmaBoxTexture;
				   BuildTexture[2] = FarmBoxTexture;
				   BuildTexture[3] = FactoryBoxTexture;
				   BuildTexture[4] = MineBoxTexture;
				   BuildTexture[5] = ShipmentBoxTexture;
				   BuildTexture[6] = AlchemyLabBoxTexture;
				   BuildTexture[7] = PortalBoxTexture;
				   BuildTexture[8] = TimeMachineBoxTexture;
				   sizeMod = 1.0f;
				   break;
		}
		}
	}
	else if (GetInput()->WasMouseButtonReleased(0) && m_mouseCheck)
	{
		switch (ClickInput())
		{
		case 'C':
		{
					sizeMod = 1.0f;
					m_crateCount += m_mousePower;
					break;
		}
		case 'K':
		{
					BuildTexture[0] = CursorBoxTexture;
					if (m_crateCount >= Cursor->GetCost())
					{
						m_crateCount -= Cursor->GetCost();
						Cursor->Purchase();
						UpdateCPS(*m_cps);
					}
					break;
		}
		case 'G':
		{
					BuildTexture[1] = GrandmaBoxTexture;
					if (m_crateCount >= Grandma->GetCost())
					{
						m_crateCount -= Grandma->GetCost();
						Grandma->Purchase();
						UpdateCPS(*m_cps);
					}
					break;
		}
		case 'B':
		{
					BuildTexture[2] = FarmBoxTexture;
					if (m_crateCount >= Farm->GetCost())
					{
						m_crateCount -= Farm->GetCost();
						Farm->Purchase();
						UpdateCPS(*m_cps);
					}
					break;
		}
		case 'F':
		{
					BuildTexture[3] = FactoryBoxTexture;
					if (m_crateCount >= Factory->GetCost())
					{
						m_crateCount -= Factory->GetCost();
						Factory->Purchase();
						UpdateCPS(*m_cps);
					}
					break;
		}
		case 'M':
		{
					BuildTexture[4] = MineBoxTexture;
					if (m_crateCount >= Mine->GetCost())
					{
						m_crateCount -= Mine->GetCost();
						Mine->Purchase();
						UpdateCPS(*m_cps);
					}
					break;
		}
		case 'S':
		{
					BuildTexture[5] = ShipmentBoxTexture;
					if (m_crateCount >= Shipment->GetCost())
					{
						m_crateCount -= Shipment->GetCost();
						Shipment->Purchase();
						UpdateCPS(*m_cps);
					}
					break;
		}
		case 'A':
		{
					BuildTexture[6] = AlchemyLabBoxTexture;
					if (m_crateCount >= AlchemyLab->GetCost())
					{
						m_crateCount -= AlchemyLab->GetCost();
						AlchemyLab->Purchase();
						UpdateCPS(*m_cps);
					}
					break;
		}
		case 'P':
		{
					BuildTexture[7] = PortalBoxTexture;
					if (m_crateCount >= Portal->GetCost())
					{
						m_crateCount -= Portal->GetCost();
						Portal->Purchase();
						UpdateCPS(*m_cps);
					}
					break;
		}
		case 'T':
		{
					BuildTexture[8] = TimeMachineBoxTexture;
					if (m_crateCount >= TimeMachine->GetCost())
					{
						m_crateCount -= TimeMachine->GetCost();
						TimeMachine->Purchase();
						UpdateCPS(*m_cps);
					}
					break;
		}
		default:
		{
				   break;
		}
		}
	}*/
	/*else
	{
		m_mouseCheck = false;
	}*/
	if (GetInput()->IsKeyDown('W'))
	{
		m_tankBaseTransMat->TranslateMat(0, -45 * deltaTime);
	}
	if (GetInput()->IsKeyDown('S'))
	{
		m_tankBaseTransMat->TranslateMat(0, 45 * deltaTime);
	}
	if (GetInput()->IsKeyDown('D'))
	{
		m_tankTurretTransMat->RotateMat(0.7f * deltaTime);
		ClampRot();
	}
	if (GetInput()->IsKeyDown('A'))
	{
		m_tankTurretTransMat->RotateMat(-0.7f * deltaTime);
		ClampRot();
	}
	if (GetInput()->WasKeyPressed('E'))
	{
		if (projInFlight != cookieMunitions.size())
		{
			tt->RemoveChild(cookieMunitions.front());
		}
		else
			allInFlight = true;
		projInFlight++;
	}
	if (projInFlight > 0)
	{
		for (int i = 0; i < projInFlight; i++)
		{
			cookieMunitions[i]->SetLocal(Matrix3x3::CreateTranslateMat(700 * deltaTime, 0));
			cookieMunitions[i]->UpdateTransforms();


			*cookieMunitions[i]->GetGlobal() *= v_cookieProjectile[i];
			if (v_cookieProjectile[i].x > 1280 || v_cookieProjectile[i].y < 0 || v_cookieProjectile[i].y > 720)
			{
				//allInFlight = false;
				cookieMunitions.erase(cookieMunitions.begin() + i);
				
				
				cookieMunitions.insert(cookieMunitions.begin() + i, new SceneNode(&Matrix3x3::CreateTranslateMat(75, 0), new Matrix3x3()));
				tt->AddChild(cookieMunitions[i]);
				projInFlight--;
			}
			v_cookieProjectile[i].x = 1;
			v_cookieProjectile[i].y = 1;
		}
	}
	gameScene->UpdateTransforms();
}

void Game1::ClampRot()
{
	float angleClamp = 1.04719755f;
	Matrix3x3 temp;
	Matrix3x3 temp2;
	temp.ScaleMat(1, 1.2);
	temp2.ScaleMat(1, 1.2);
	temp.RotateMat(angleClamp);
	temp2.RotateMat(-angleClamp);
	if (m_tankTurretTransMat->m_mat[0][0] <= temp2.m_mat[0][0] && m_tankTurretTransMat->m_mat[0][1] >= temp2.m_mat[0][1])
	{
		m_tankTurretTransMat->RotateMat(0.0174532925);
	}
	else if (m_tankTurretTransMat->m_mat[0][0] <= temp.m_mat[0][0] && m_tankTurretTransMat->m_mat[0][1] <= temp.m_mat[0][1])
	{
		m_tankTurretTransMat->RotateMat(-0.0174532925);
	}
}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();
	std::string str = std::to_string(m_crateCount);
	str.erase(str.find_last_of('.') + 2, std::string::npos);
	std::string cps = std::to_string(*m_cps);
	cps.erase(cps.find_last_of('.') + 2, std::string::npos);

	m_spritebatch->Begin();

	m_spritebatch->DrawSprite(m_crate, 640.0f, 360.0f, m_crate->GetWidth()*sizeMod, m_crate->GetHeight()*sizeMod);
	for (int i = 0; i < cookieMunitions.size(); i++)
	{
		m_spritebatch->DrawSpriteTransformed3x3(m_cookie, &cookieMunitions[i]->GetGlobal()->m_mat[0][0], 32, 24, 0.5f);
	}
	m_spritebatch->DrawSpriteTransformed3x3(tankTurret, &m_ttGlobal->m_mat[0][0], tankTurret->GetWidth(), tankTurret->GetHeight(), -0.3f);
	m_spritebatch->DrawSpriteTransformed3x3(tankBase, &m_tankBaseTransMat->m_mat[0][0], tankBase->GetWidth(), tankBase->GetHeight(), 1.0f);

	for (int i = temp; i < 1280; i += 138)
	{
		m_spritebatch->DrawString(m_text, BuildNames[textArr], (float)i, 40.0f, 0.5f, 0.5f);
		m_spritebatch->DrawSprite(BuildTexture[textArr], (float)i, temp, CursorBoxTexture->GetWidth(), CursorBoxTexture->GetHeight());
		m_spritebatch->DrawString(m_text, to_string(Builds[textArr++]->GetCost()).c_str(), (float)i, 160.0f, 0.0f, 0.0f);
	}

	m_spritebatch->DrawString(m_text, "Crates:", 590.0f, 520.0f, 0.5f, 0.5f);
	m_spritebatch->DrawString(m_text, str.c_str(), 650.0f, 520.0f, 0.0f, 0.0f);
	m_spritebatch->DrawString(m_text, "CPS:", 590.0f, 550.0f, 0.5f, 0.5f);
	m_spritebatch->DrawString(m_text, cps.c_str(), 650.0f, 550.0f, 0.0f, 0.0f);
	// TODO: draw stuff.
	textArr = 0;
	m_spritebatch->End();

}