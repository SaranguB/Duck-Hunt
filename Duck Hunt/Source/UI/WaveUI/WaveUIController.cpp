#include "../../Header/UI/WaveUI/WaveUIController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Wave/WaveServices.h"


namespace UI
{
	namespace WaveUI
	{
		using namespace UIElement;
		using namespace Global;
		using namespace Wave;

		WaveUIController::WaveUIController()
		{
			waveText = new TextView();
		}

		WaveUIController::~WaveUIController()
		{
			delete(waveText);
		}

		void WaveUIController::Initialize()
		{
			InitialzeWaveText();
		}

		void WaveUIController::Update()
		{
			DisplayWaveText();
		}

		void WaveUIController::Render()
		{
			waveText->Render();
		}

		void WaveUIController::InitialzeWaveText()
		{
			waveText->Initialize("Wave 1", sf::Vector2f(0, 0),
				FontType::BUBBLE_BOBBLE, fontSize, textColor);
		}

		void WaveUIController::DisplayWaveText()
		{
			WaveType currentType = ServiceLocator::GetInstance()->GetWaveService()->GetCurrentWave();
			switch (currentType)
			{
			case WaveType::FIRSTWAVE:
				waveText->setText("wave 1");
				break;
			case WaveType::SECONDWAVE:
				waveText->setText("wave 2");
				break;
			case WaveType::THIRDWAVE:
				waveText->setText("wave 3");
				break;
			}
			waveText->SetTextPosition(GetTextcentreAligned());
		}

		sf::String WaveUIController::CurrentWaveText()
		{
			return sf::String();
		}

		void WaveUIController::Show()
		{
		}
		sf::Vector2f WaveUIController::GetTextcentreAligned()
		{
			gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();

			sf::FloatRect textBounds = waveText->GetLocalBounds();

			float xPosition = (gameWindow->getSize().x - textBounds.width) / 2;
			float yPosition = (gameWindow->getSize().y - textBounds.height) / 2;

			return sf::Vector2f(xPosition, yPosition);
		}
	}
}