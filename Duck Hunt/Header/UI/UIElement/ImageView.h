#pragma once
#include "../../Header/UI/UIElement/UIView.h"

namespace UI
{
	namespace UIElement
	{
		class ImageView : public UIView
		{
		private:

			sf::Texture imageTexture;
			sf::Sprite imageSprite;

			float imageWidth;
			float imagwHeight;

			

		public:
			ImageView();
			~ImageView();

			void Initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f position);
			
			void Render();

			void SetTexture(sf::String texturePath);
			void SetScale(float imageWidth, float imageHeight);
			void SetPosition(sf::Vector2f position);

			sf::Sprite& GetImageSprite();
		};
	}
}
