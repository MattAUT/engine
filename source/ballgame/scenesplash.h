#ifndef __SCENESPLASH_H__
#define __SCENESPLASH_H__

#include "scene.h"

// Forward Declarations
class Renderer;
class Sprite;

class SceneSplash : public Scene
{
	// Member Methods
public:
	SceneSplash();
	virtual ~SceneSplash();

	virtual bool Initialise(Renderer& renderer) override;
	virtual void Process(float deltaTime) override;
	virtual void Draw(Renderer& renderer) override;

protected:
private:
	SceneSplash(const SceneSplash& sceneSplah);
	SceneSplash& operator=(const SceneSplash& sceneSplash);

	// Member Data
public:
protected:
	Sprite* m_pLogo;
	Scene* m_pNextScene;

	float m_fTime; 
	float m_fSceneLength; // Amount of time the splash screen will last
private:

};

#endif // __SCENESPLASH_H__

