#include "../../Header/Wave/WaveServices.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Gameplay/GameplayService.h"
#include <iostream>

namespace Wave
{
	using namespace Player;
	using namespace Global;
	using namespace Main;

	WaveService::WaveService() = default;


	WaveService::~WaveService() = default;


	void WaveService::Initialize()
	{
		currentWave = WaveType::FIRSTWAVE;
		EnemiesToBeKilled = 2;
		waveClock.restart();
	}

	void WaveService::Update()
	{
		WaveStateChange();
	}

	void WaveService::ResetTime()
	{

		waveTimer = 0;
		clock.restart();

	}

	bool WaveService::checkTimeForChange()
	{
		return clock.getElapsedTime().asSeconds() >= waveTimer;
	}

	void WaveService::SetCurrentWave(WaveType wave)
	{
		

		GameService::SetGameState(GameState::WAVE);
		switch (wave)
		{

		case WaveType::FIRSTWAVE:

			RestartClock();
			ServiceLocator::GetInstance()->GetEnemyService()->Reset();
			currentWave = WaveType::FIRSTWAVE;

			waveTimer = 10;
			Player::PlayerModel::playerAmmo = 5;
			Enemy::EnemyModel::NumberOfEnemies = 4;
			EnemiesToBeKilled = 3;
			ServiceLocator::GetInstance()->GetPlayerService()->SetCurrentStatus(PlayerStatus::STATIC);
			break;

		case WaveType::SECONDWAVE:
			RestartClock();
			ServiceLocator::GetInstance()->GetEnemyService()->Reset();
			currentWave = WaveType::SECONDWAVE;

			waveTimer = 10;
			Player::PlayerModel::playerAmmo = 10;
			Enemy::EnemyModel::NumberOfEnemies = 8;
			EnemiesToBeKilled = 2;
			ServiceLocator::GetInstance()->GetPlayerService()->SetCurrentStatus(PlayerStatus::STATIC);

			break;

		case WaveType::THIRDWAVE:
			RestartClock();
			ServiceLocator::GetInstance()->GetEnemyService()->Reset();
			currentWave = WaveType::THIRDWAVE;

			waveTimer = 10;
			Player::PlayerModel::playerAmmo = 17;
			Enemy::EnemyModel::NumberOfEnemies = 12;
			EnemiesToBeKilled = 2;
			ServiceLocator::GetInstance()->GetPlayerService()->SetCurrentStatus(PlayerStatus::STATIC);

			break;

		case WaveType::FINISHED:

			PlayerStatus currentStatus = ServiceLocator::GetInstance()->GetPlayerService()->GetCurrentStatus();

			if (currentStatus == PlayerStatus::WON)
			{
				
				ServiceLocator::GetInstance()->GetPlayerService()->SetCurrentStatus(PlayerStatus::GAME_WON);
			}

			else if (currentStatus == PlayerStatus::FAILED)
			{
				ServiceLocator::GetInstance()->GetPlayerService()->SetCurrentStatus(PlayerStatus::GAME_OVER);
			}

			GameService::SetGameState(GameState::CREDITS);

			

		}

	}

	int WaveService::GetEnemiesToBeKilled()
	{
		return EnemiesToBeKilled;
	}

	WaveType WaveService::GetCurrentWave()
	{
		return currentWave;
	}

	void WaveService::RestartClock()
	{
		clock.restart();

	}

	void WaveService::WaveStateChange()
	{
		PlayerStatus currentStatus = ServiceLocator::GetInstance()->GetPlayerService()->GetCurrentStatus();

		if (GameService::GetGameState() == GameState::WAVE)
		{
			if (waveClock.getElapsedTime().asSeconds() >= 2)
			{
				GameService::SetGameState(GameState::GAMEPLAY);
				waveClock.restart();
			}
		}
		else if(currentStatus == PlayerStatus::GAME_WON || currentStatus == PlayerStatus::GAME_OVER)
		{
			if (waveClock.getElapsedTime().asSeconds() >= 5)
			{
				
				RestartClock();
				ServiceLocator::GetInstance()->GetGameplayService()->ResetGame();
				waveClock.restart();
			

			}
			
		}
		else
		{
			waveClock.restart();
		}

		
	}




}