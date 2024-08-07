#pragma once
#include "SFML/Audio.hpp"

namespace Sound
{
	enum class SoundType
	{
		START_MUSIC,
		DUCK_SOUND,
		FAIL_SOUND,
		WON_SOUND,
		SHOOT_SOUND,
		EMPTY_SOUND,
	};

	class SoundService
	{
	private:
		sf::Sound soundEffect;
		sf::SoundBuffer bufferDuck;
		sf::SoundBuffer buffeStart;
		sf::SoundBuffer bufferWon;
		sf::SoundBuffer bufferFailed;
		sf::SoundBuffer bufferShooting;
		sf::SoundBuffer bufferEmpty;

		
		void LoadSoundFromFile();

	public:

		void Initialize();

		void PlaySound(SoundType soundType);
	};
}