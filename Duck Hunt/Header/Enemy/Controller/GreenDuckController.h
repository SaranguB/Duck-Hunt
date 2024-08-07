#pragma once
#include "../../Header/Enemy/EnemyController.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

namespace Enemy
{
	enum class EnemyType;
	namespace Controller
	{
		class GreenDuckController : public EnemyController
		{
		private:

		public:
			GreenDuckController();
			~GreenDuckController() override;


			void Initialize() override;
			
			void Move() override;


			float verticalSpeed = 1200.f;
			float HorizontalSpeed = 800.f;
			float diagonalLeftSpeed = 700.f;
			float diagonalRightSpeed = 800.f;

		

		

		};
	}
}