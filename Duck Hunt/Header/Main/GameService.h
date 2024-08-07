#pragma once
#include "../../Header/Global/ServiceLocator.h"

namespace Main
{
	enum GameState
	{
		BOOT,
		WAVE,
		GAMEPLAY,
		CREDITS,

	};

	class GameService
	{
	private:

		static GameState currentState;
		sf::RenderWindow* gameWindow;
		Global::ServiceLocator* serviceLocator;

		void InitializeVariable();
		
	public:
		GameService();
		~GameService();

		void Ignite();

		void Initialize();
		void Update();
		void Render();
		bool IsRunning();

		static void SetGameState(GameState newState);
		static GameState GetGameState();

	};
}
