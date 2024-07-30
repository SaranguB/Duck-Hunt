#include "../../Header/Player/PlayerService.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Wave/WaveServices.h"
#include "../../Header/Global/ServiceLocator.h"
#include <iostream>

namespace Player
{
	using namespace Wave;
	using namespace Global;
	PlayerService::PlayerService()
	{
		playerController = new PlayerController();
	}

	PlayerService::~PlayerService()
	{
		delete(playerController);
	}

	void PlayerService::Initialize()
	{
		playerController->Initialize();
		currentStatus = PlayerStatus::STATIC;

	}

	void PlayerService::Update()
	{
		playerController->Update();


		CheckForChange();
	}

	void PlayerService::Reset()
	{
		playerController->Reset();
		currentStatus = PlayerStatus::STATIC;
	}



	int PlayerService::GetPlayerScore()
	{
		return playerController->GetPlayerScore();
	}

	void PlayerService::IncreasePlayerScore(int score)
	{
		playerController->SetPlayerScore(playerController->GetPlayerScore() + score);
	}

	void PlayerService::SetCurrentStatus(PlayerStatus status)
	{

		currentStatus = status;


	}

	PlayerStatus PlayerService::GetCurrentStatus()
	{
		return currentStatus;
	}

	void PlayerService::CheckForChange()
	{
		WaveType currentWave;
		sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();
		//std::cout << "Current Status: " << static_cast<int>(currentStatus) << std::endl;
		currentWave = ServiceLocator::GetInstance()->GetWaveService()->GetCurrentWave();

		switch (currentStatus)
		{
		case PlayerStatus::WON:
		{
			ServiceLocator::GetInstance()->GetGraphicService()->ChangeWindowColor(sf::Color::Green);
			if (currentWave == WaveType::FIRSTWAVE)
			{
				printf("first wave\n");
				ServiceLocator::GetInstance()->GetWaveService()->SetCurrentWave(WaveType::SECONDWAVE);
				currentStatus = PlayerStatus::STATIC;
				break;
			}
			if (currentWave == WaveType::SECONDWAVE)
			{
				printf("Second wave\n");
				ServiceLocator::GetInstance()->GetWaveService()->SetCurrentWave(WaveType::THIRDWAVE);
				currentStatus = PlayerStatus::STATIC;
				break;
			
			}

			if (currentWave == WaveType::THIRDWAVE)
			{
				printf("Third wave\n");
				ServiceLocator::GetInstance()->GetWaveService()->SetCurrentWave(WaveType::FINISHED);
				currentStatus = PlayerStatus::STATIC;
				playerController->ResetGame();
				
				break;
			}
			
		}

		case PlayerStatus::FAILED:
		{
			
			ServiceLocator::GetInstance()->GetGraphicService()->ChangeWindowColor(sf::Color::Red);
			DecreasePlayerLive();

			if (currentWave == WaveType::FIRSTWAVE)
			{
				printf("Failed first wave\n");
				ServiceLocator::GetInstance()->GetWaveService()->SetCurrentWave(WaveType::FIRSTWAVE);
				currentStatus = PlayerStatus::STATIC;
				break;
			}
			if (currentWave == WaveType::SECONDWAVE)
			{
				printf("Failed Second wave\n");
				ServiceLocator::GetInstance()->GetWaveService()->SetCurrentWave(WaveType::SECONDWAVE);
				currentStatus = PlayerStatus::STATIC;
				break;

			}

			if (currentWave == WaveType::THIRDWAVE)
			{
				printf("Failed Third wave\n");
				ServiceLocator::GetInstance()->GetWaveService()->SetCurrentWave(WaveType::THIRDWAVE);
				currentStatus = PlayerStatus::STATIC;

				break;
			}
			Reset();
			break;
		}

		}
	}

	void PlayerService::DecreasePlayerLive()
	{
		playerController->DecreasePlayerLive();
	}

}