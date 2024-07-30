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
			ServiceLocator::GetInstance()->GetGraphicService()->ChangeWindowColor(sf::Color::Green);
			ServiceLocator::GetInstance()->GetEnemyService()->Reset();
			currentWave = WaveType::SECONDWAVE;
			waveTimer = 20;
			Player::PlayerModel::playerAmmo = 10;
			Enemy::EnemyModel::NumberOfEnemies = 8;
			EnemiesToBeKilled = 8;

		case WaveType::SECONDWAVE:
			ServiceLocator::GetInstance()->GetGraphicService()->ChangeWindowColor(sf::Color::Green);
			ServiceLocator::GetInstance()->GetEnemyService()->Reset();
			currentWave = WaveType::THIRDWAVE;
			waveTimer = 30;
			Player::PlayerModel::playerAmmo = 17;
			Enemy::EnemyModel::NumberOfEnemies = 15;
			EnemiesToBeKilled = 15;

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

	void WaveService::SetCurrentWave(WaveType wave)
	{
		currentWave = wave;

	}

	void WaveService::RestartClock()
	{
		clock.restart();

	}




}