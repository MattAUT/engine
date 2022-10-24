#ifndef __SCENEBALL_H__
#define __SCENEBALL_H__

#include "scene.h"

// Forward Declarations
class Renderer;
class Sprite;
class Ball;

class SceneBalls : public Scene
{
	// Member Methods
public:
	SceneBalls();
	virtual ~SceneBalls();

	virtual bool Initialise(Renderer& renderer) override;
	virtual void Process(float deltaTime) override;
	virtual void Draw(Renderer& renderer) override;

protected:
private:
	SceneBalls(const SceneBalls& sceneBalls);
	SceneBalls &operator=(const SceneBalls& sceneBalls);

	// Member Data
public:
protected:
	Ball** m_pBalls;
	int m_iShowCount;

private:

};

#endif // __SCENESPLASH_H__

