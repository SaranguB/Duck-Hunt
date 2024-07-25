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

			sf::Sprite imageTexture;
			sf::Sprite imageSprite;

			float imageWidth;
			float imagwHeight;

		public:
			ImageView();
			~ImageView();

			void Initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f position);
			void Update();
			void Render();

			void SetTexture();



		};
	}
}
