#pragma once
#include "../../Header/Enemy/EnemyController.h"
#include <SFML/System/Clock.hpp>

namespace Enemy
{
	enum class EnemyType;
	namespace Controller
	{
		class GreenDuckController : public EnemyController
		{
		private:


			void MoveLeft();
			void MoveRight();
			void MoveUP();
			void MoveDown();
			void MoveDiagonalLeftUP();
			void MoveDiagonalRightUP();
			void MoveDiagonalRightDown();
			void MoveDiagonalLeftDown();

		public:
			GreenDuckController(EnemyType type);
			~GreenDuckController() override;


			void Initialize() override;
			
			void Move() override;


			float verticalSpeed = 400.f;
			float HorizontalSpeed = 500.f;
			float diagonalLeftSpeed = 600.f;
			float diagonalRightSpeed = 700.f;

			MovementDirection currentDirection;
			sf::Clock directionChangeClock;


		};
	}
}