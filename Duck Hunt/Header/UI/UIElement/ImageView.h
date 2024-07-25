#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace UIElement
	{
		class ImageView
		{
		private:

			sf::RenderWindow* gameWindow;

			sf::Texture imageTexture;
			sf::Sprite imageSprite;

			float imageWidth;
			float imagwHeight;

			

		public:
			ImageView();
			~ImageView();

			void Initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f position);
			void Update();
			void Render();

			void SetTexture(sf::String texturePath);
			void SetScale(float imageWidth, float imageHeight);


		};
	}
}
