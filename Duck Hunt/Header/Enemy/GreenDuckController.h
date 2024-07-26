#pragma once
#include "../../Header/Enemy/EnemyController.h"

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


			float verticalSpeed = 200.f;
			float HorizontalSpeed = 200.f;
			float diagonalLeftSpeed = 200.f;
			float diagonalRightSpeed = 200.f;
		};
	}
}