#pragma once
#include <SFML/System/Clock.hpp>

namespace Wave
{
	class PlayerModel;

	enum class WaveType
	{
		FIRSTWAVE,
		SECONDWAVE,
	};
	class WaveService
	{
		PlayerModel* playerModel;
	private:
		int waveTimer = 5;
		sf::Clock clock;

	public:
		WaveService();
		~WaveService();

		void Initialize();
		void Update();

		void ResetTime();

		bool checkTimeForChange();


		int speed;
		int ammo;
		int EnemiesToBeKilled;

		void ChangeWave(WaveType wave);

		WaveType currentWave;
		int GetEnemiesToBeKilled();

		void waveDetails();

		WaveType GetCurrentWave();
		void RestartClock();
	};
}
