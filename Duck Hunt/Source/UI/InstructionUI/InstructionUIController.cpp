#include "../../Header/UI/InstructionUI/InstructionUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"

namespace UI
{
	namespace InstructionUI
	{
		using namespace UIElement;
		using namespace Main;
		using namespace Global;

		InstructionUIController::InstructionUIController()
		{
			instructionText = new TextView();
			menuButton = new ButtonView();
			backgroundImage = new ImageView();
		}

		InstructionUIController::~InstructionUIController()
		{
			delete(instructionText);
			delete(menuButton);
			delete(backgroundImage);

		}
		void InstructionUIController::Initialize()
		{
			InitialzeInstructionText();
			InitializeButton();
			RegisterButtonCallback();

		}
		void InstructionUIController::Update()
		{
			if(GameService::GetGameState() == GameState::INSTRUCTION)
				ServiceLocator::GetInstance()->GetGraphicService()->ChangeWindowColor(sf::Color::Black);

			instructionText->SetTextPosition(GetTextcentreAligned());

			instructionText->Update();
			menuButton->Update();

		}
		void InstructionUIController::Render()
		{
			instructionText->Render();
			menuButton->Render();
		}

		void InstructionUIController::InitialzeInstructionText()
		{
			instructionText->Initialize(text, sf::Vector2f(0, 0),
				FontType::BUBBLE_BOBBLE, fontSize, textColor);
		}

		void InstructionUIController::InitializeButton()
		{
			menuButton->Initialize("Play Button", Config::menu_button_texture_path,
				buttonWidth, buttonHeight, sf::Vector2f(playButtonXposition, playButtonYposition));;
		}

		void InstructionUIController::MenuButtonCallback()
		{
			ServiceLocator::GetInstance()->GetSoundService()->PlaySound(Sound::SoundType::BUTTON_SOUND);
			GameService::SetGameState(GameState::MAINMENU);

		}

		sf::Vector2f InstructionUIController::GetTextcentreAligned()
		{
			gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();

			sf::FloatRect textBounds = instructionText->GetLocalBounds();

			float xPosition = (gameWindow->getSize().x - textBounds.width) / 2;
			float yPosition = (gameWindow->getSize().y - textBounds.height) / 2;

			return sf::Vector2f(xPosition, yPosition);
		}

		void InstructionUIController::RegisterButtonCallback()
		{
			menuButton->RegisterCallBackFuntion
			(std::bind(&InstructionUIController::MenuButtonCallback, this));
		}

		void InstructionUIController::Show()
		{

			menuButton->Show();

		}
		
	}
}