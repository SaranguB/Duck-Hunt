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


			float verticalSpeed = 1200.f;
			float HorizontalSpeed = 600.f;
			float diagonalLeftSpeed = 700.f;
			float diagonalRightSpeed = 800.f;

		

		

		};
	}
}