#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Global/Config.h"


namespace Graphics
{

	GraphicService::GraphicService()
	{
		gameWindow = nullptr;
		videoMod = nullptr;
	}

	GraphicService::~GraphicService()
	{
		OnDestroy();
	}

	void GraphicService::Initialize()
	{
		gameWindow = CreateGameWindow();
		SetImageTexture();
		gameWindow->setFramerateLimit(frameRate);
	}

	sf::RenderWindow* GraphicService::CreateGameWindow()
	{
		SetVideoMod();
		return new sf::RenderWindow(*videoMod, gameWindowTitle, sf::Style::Fullscreen);
	}

	void GraphicService::SetVideoMod()
	{
		videoMod = new sf::VideoMode(gameWindowWidth, gameWindowHeight, sf::VideoMode::getDesktopMode().bitsPerPixel);
	}

	void GraphicService::OnDestroy()
	{
		delete(gameWindow);
		delete(videoMod);
	}

	void GraphicService::Update()
	{

	}

	void GraphicService::Render()
	{
	}

	bool GraphicService::IsGameWindowOpen()
	{
		return gameWindow->isOpen();
	}

	sf::RenderWindow* GraphicService::GetGameWIndow()
	{
		return gameWindow;
	}

	sf::Color GraphicService::GetWindowColor()
	{
		return gameWindowColor;
	}

	void GraphicService::SetImageTexture()
	{
		if (bgTexture.loadFromFile(Global::Config::Duck_Hunt_BG_Texture_Path))
		{
			bgSprite.setTexture(bgTexture);
			SetScale();
			
		}
	}

	sf::Sprite GraphicService::GetImageSprite()
	{
		return bgSprite;
	}

	void GraphicService::SetScale()
	{
		float scaleX = gameWindowWidth / static_cast<float> (bgSprite.getTexture()->getSize().x);
		float scaleY = gameWindowHeight / static_cast<float> (bgSprite.getTexture()->getSize().y);

		bgSprite.setScale(scaleX, scaleY);
	}

}