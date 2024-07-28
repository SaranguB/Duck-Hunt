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

		void Reset();

		bool checkTimeForChange();


		int speed;
		int ammo;
	};
}
