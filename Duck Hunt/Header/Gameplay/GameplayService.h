#pragma once

namespace Gameplay
{
	enum class UIType
	{
		GAMEPLAY,
		STAT,
	};

	class GameplayController;

	class GameplayService
	{

	private:
		GameplayController* gameplayController;
		UIType uiType;


	public:
		GameplayService();
		~GameplayService();

		void Initialize();
		void Update();
		void Render();

		UIType GetUIType();
		UIType SetUIType();
	};
}