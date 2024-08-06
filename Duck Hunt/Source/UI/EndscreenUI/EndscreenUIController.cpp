#include "../../Header/UI/EndscreenUI/EndscreenUIController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Player/PlayerService.h"

namespace UI
{
	namespace EndscreenUI
	{
		using namespace UIElement;
		using namespace Global;
		using namespace Main;
		using namespace Player;

		EndscreenUIController::EndscreenUIController()
		{
			finalImageWon = new ImageView;
			finalImageLose = new ImageView;
		}

		EndscreenUIController::~EndscreenUIController()
		{
			delete(finalImageWon);
			delete(finalImageLose);
		}

		void EndscreenUIController::Initialize()
		{
			InitializeImage();
		}

		void EndscreenUIController::Update()
		{
			finalImageWon->Update();
			finalImageLose->Update();
		}

		void EndscreenUIController::Render()
		{
			PlayerStatus currentStatus = ServiceLocator::GetInstance()->GetPlayerService()->GetCurrentStatus();
			//printf("Current Status: %d\n", static_cast<int>(currentStatus));

			if (currentStatus == PlayerStatus::GAME_WON)
			{
				finalImageWon->Render();
			}
			if (currentStatus == PlayerStatus::GAME_OVER)
			{
				finalImageLose->Render();

			}
		}

		void EndscreenUIController::Show()
		{
		}

		void EndscreenUIController::InitializeImage()
		{
			sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();
			
		
				printf("hi\n");
				finalImageWon->Initialize(Config::You_Won,
					gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0, 0));
			
				finalImageLose->Initialize(Config::You_lose,
					gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0, 0));;

			
		}
	}
}