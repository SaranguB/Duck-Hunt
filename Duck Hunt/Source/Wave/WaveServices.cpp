#include "../../Header/Wave/WaveServices.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Enemy/EnemyModel.h"
#include <iostream>

namespace Wave
{
	using namespace Player;
	using namespace Global;

	WaveService::WaveService()
	{
		
	}

	WaveService::~WaveService()
	{
	}

	void WaveService::Initialize()
	{
		currentWave = WaveType::FIRSTWAVE;
		EnemiesToBeKilled = 2;
	}

	void WaveService::Update()
	{
		
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

	void WaveService::ChangeWave(WaveType wave)
	{

		switch (wave)
		{
		case WaveType::FIRSTWAVE:
			
			RestartClock();
			ServiceLocator::GetInstance()->GetEnemyService()->Reset();
			currentWave = WaveType::SECONDWAVE;
			Player::PlayerModel::playerAmmo = 10;
			Enemy::EnemyModel::NumberOfEnemies = 10;
			EnemiesToBeKilled = 3;
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

	


}