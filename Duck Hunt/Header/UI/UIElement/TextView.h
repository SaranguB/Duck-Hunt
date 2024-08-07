#pragma once
#include "../../Header/UI/UIElement/UIView.h"


namespace UI
{
	namespace UIElement
	{
		enum class FontType
		{
			BUBBLE_BOBBLE,
			DS_DIGIB,
		};
		class TextView : public UIView
		{
		private:	
			static const int defualtFontSize = 55;

			static sf::Font fontBubbleBobble;
			static sf::Font fontDSDIGIB;

			sf::Text text;

			static void LoadFont();

			void SetFont(FontType fontType);
			void SetFontSize(int fontSize);
			void SetTextColor(sf::Color color);


		public:
			TextView();
			~TextView();

			void Initialize(sf::String textValue, sf::Vector2f position,
				FontType fontType = FontType::BUBBLE_BOBBLE, int fontSize = defualtFontSize,
				sf::Color color = sf::Color::White);
		
			void SetTextPosition(sf::Vector2f position);

			void Render();

			void setText(sf::String textValue);
			sf::FloatRect GetLocalBounds();
		};
	}
}
