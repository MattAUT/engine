// COMP710 GP Framework 2022

#include "scenesplash.h"

#include "renderer.h"
#include "sprite.h"

#include <cassert>
#include <cmath>

SceneSplash::SceneSplash()
	: m_pLogo(0)
	, m_fTime(-0.4f) 
	, m_fSceneLength(5)
{

}

SceneSplash::~SceneSplash()
{
	m_fSceneLength = 0.0f;

	delete m_pLogo;
	m_pLogo = NULL;
}

bool SceneSplash::Initialise(Renderer& renderer)
{
	m_pLogo = renderer.CreateSprite("assets\\splash-logo.png");

	const int SCREEN_WIDTH = renderer.GetWidth();
	const int SCREEN_HEIGHT = renderer.GetHeight();

	m_pLogo->SetX(SCREEN_WIDTH / 2);
	m_pLogo->SetY(SCREEN_HEIGHT / 2);
	m_pLogo->SetScale(0.4f);
	m_pLogo->SetAlpha(0.0f);

	return true;
}

void SceneSplash::Process(float deltaTime)
{
	m_fTime += deltaTime;
	float alpha = powf(sinf((M_PI * m_fTime) / m_fSceneLength), 0.65);
	m_pLogo->SetAlpha(alpha);
}

void SceneSplash::Draw(Renderer& renderer)
{
	m_pLogo->Draw(renderer);
}