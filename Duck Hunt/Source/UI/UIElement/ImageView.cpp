#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/Global/ServiceLocator.h"

namespace UI
{
	namespace UIElement
	{
		
		using namespace Global;

		ImageView::ImageView()
		{
		}

		ImageView::~ImageView()
		{
		}

		void ImageView::Initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f position)
		{
			gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();
			SetTexture(texturePath);
			SetScale(imageWidth, imageHeight);

		}

		void ImageView::Update()
		{
		}
		
		void ImageView::SetTexture(sf::String texturePath)
		{

			if (imageTexture.loadFromFile(texturePath))
			{

				imageSprite.setTexture(imageTexture);


			}
		}

		void ImageView::SetScale(float imageWidth, float imageHeight)
		{
			float scaleX = imageWidth / static_cast<float> (imageSprite.getTexture()->getSize().x);
			float scaleY = imageHeight / static_cast<float> (imageSprite.getTexture()->getSize().y);

			imageSprite.setScale(scaleX, scaleY);
		}

		void ImageView::Render()
		{
			gameWindow->draw(imageSprite);

		}
	}



}