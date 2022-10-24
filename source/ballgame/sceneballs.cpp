// This include: 
#include "sceneballs.h"

// Local includes: 
#include "renderer.h"
#include "ball.h"

// Library includes: 
#include <cassert>
#include <cstdlib>
SceneBalls::SceneBalls()
	: m_pBalls{ 0 }
	, m_iShowCount(0)
{
	m_pBalls = new Ball*[100];
}
SceneBalls::~SceneBalls()
{
	
	for (int k = 0; k < 100; ++k)
	{
		delete m_pBalls[k];
		m_pBalls[k] = 0;
	}

	delete[] m_pBalls;
}

bool
SceneBalls::Initialise(Renderer& renderer)
{
	for (int k = 0; k < 100; ++k)
	{
		m_pBalls[k] = new Ball();
		m_pBalls[k]->Initialise(renderer);
		m_pBalls[k]->RandomiseColour();
	}
	// Always place one ball at the centre...
	m_pBalls[0]->Position().x = renderer.GetWidth() / 2.0f;
	m_pBalls[0]->Position().y = renderer.GetHeight() / 2.0f;
	m_iShowCount = 100;
	return true;
}
void
SceneBalls::Process(float deltaTime)
{
	for (int k = 0; k < m_iShowCount; ++k)
	{
		m_pBalls[k]->Process(deltaTime);
	}
}

void
SceneBalls::Draw(Renderer& renderer)
{
	for (int k = 0; k < m_iShowCount; ++k)
	{
		m_pBalls[k]->Draw(renderer);
	}
}