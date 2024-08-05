#pragma once
#include "../../Header/UI/Interface/IUIcontroller.h"
#include "../../Header/UI/GameplayUI/GameplayUIController.h"


namespace UI
{
	class UIService
	{
	private:
		GameplayUI::GameplayUIController* gameplayUIController;


		void CreateController();
		void InitializeController();

		void Destroy();
		Interface::IUIController* getCurrentUIController();

	public:
		UIService();
		~UIService();

		void Initialize();
		void update();
		void Render();
		
	
	};
}
