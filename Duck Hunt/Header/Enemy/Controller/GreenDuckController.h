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


			float verticalSpeed = 1000.f;
			float HorizontalSpeed = 300.f;
			float diagonalLeftSpeed = 400.f;
			float diagonalRightSpeed = 500.f;

			MovementDirection currentDirection;
			sf::Clock directionChangeClock;

		

		};
	}
}