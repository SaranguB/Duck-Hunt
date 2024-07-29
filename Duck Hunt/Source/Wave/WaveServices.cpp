#include "../../Header/Wave/WaveServices.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Enemy/EnemyModel.h"

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
		EnemiesToBeKilled = 20;
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
		return clock.getElapsedTime().asSeconds() >=30 ;
	}

	void WaveService::ChangeWave(WaveType wave)
	{
		switch (wave)
		{
		case WaveType::FIRSTWAVE:

			RestartClock();
			ServiceLocator::GetInstance()->GetEnemyService()->Reset();
			currentWave = WaveType::SECONDWAVE;
			Player::PlayerModel::playerAmmo = 9;
			Enemy::EnemyModel::NumberOfEnemies = 8;
			EnemiesToBeKilled = 8;
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