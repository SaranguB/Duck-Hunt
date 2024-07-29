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

		switch (currentStatus)
		{
		case PlayerStatus::WON:
		{
			currentWave = ServiceLocator::GetInstance()->GetWaveService()->GetCurrentWave();
			ServiceLocator::GetInstance()->GetWaveService()->ChangeWave(currentWave);
			currentStatus = PlayerStatus::STATIC;
			break;
		}

		case PlayerStatus::FAILED:
		{
			gameWindow->clear(sf::Color::Red);
			DecreasePlayerLive();
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