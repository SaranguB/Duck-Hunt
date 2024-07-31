#include "../../Header/Enemy/Controller/GreenDuckController.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include <iostream>

namespace Enemy
{
	namespace Controller
	{
		using namespace Global;


		GreenDuckController::GreenDuckController(EnemyType type) : EnemyController(type)
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));
			currentDirection = GetRandomMovementDirection();
			
		}

		GreenDuckController::~GreenDuckController() = default;
		


		void GreenDuckController::Initialize()
		{
			EnemyController::Initialize();
		}


		void GreenDuckController::Move()
		{
			if (directionChangeClock.getElapsedTime().asSeconds() >= 1.0f)
			{
				currentDirection = GetRandomMovementDirection();
				directionChangeClock.restart();
			}

			switch (currentDirection)
			{

			case MovementDirection::LEFT:
				MoveInDirection(MovementDirection::LEFT, verticalSpeed);
				break;

			case MovementDirection::RIGHT:
				MoveInDirection(MovementDirection::RIGHT, verticalSpeed);
				break;

			case MovementDirection::UP:
				MoveInDirection(MovementDirection::UP, HorizontalSpeed);
				break;

			case MovementDirection::DOWN:
				MoveInDirection(MovementDirection::DOWN, HorizontalSpeed);
				break;

			case MovementDirection::DIAGONAL_LEFT_UP:
				MoveInDirection(MovementDirection::DIAGONAL_LEFT_UP, diagonalLeftSpeed);
				break;

			case MovementDirection::DIAGONAL_LEFT_DOWN:
				MoveInDirection(MovementDirection::DIAGONAL_LEFT_DOWN, diagonalLeftSpeed);
				break;

			case MovementDirection::DIAGONAL_RIGHT_UP:
				MoveInDirection(MovementDirection::DIAGONAL_RIGHT_UP, diagonalRightSpeed);
				break;

			case MovementDirection::DIAGONAL_RIGHT_DOWN:
				MoveInDirection(MovementDirection::DIAGONAL_RIGHT_DOWN, diagonalRightSpeed);
				break;

			}
		}

		
		/*void GreenDuckController::MoveLeft()
		{
			
			MoveInDirection(MovementDirection::LEFT, verticalSpeed);

		}

		void GreenDuckController::MoveRight()
		{
			MoveInDirection(MovementDirection::RIGHT, verticalSpeed);


		}

		void GreenDuckController::MoveUP()
		{
			

			MoveInDirection(MovementDirection::UP, HorizontalSpeed);

		}

		void GreenDuckController::MoveDown()
		{
			MoveInDirection(MovementDirection::DOWN, HorizontalSpeed);

		}

		void GreenDuckController::MoveDiagonalLeftDown()
		{
			MoveInDirection(MovementDirection::DIAGONAL_LEFT_DOWN, diagonalLeftSpeed);

		}

		void GreenDuckController::MoveDiagonalRightDown()
		{
			MoveInDirection(MovementDirection::DIAGONAL_RIGHT_DOWN, diagonalRightSpeed);

		}

		void GreenDuckController::MoveDiagonalLeftUP()
		{
			MoveInDirection(MovementDirection::DIAGONAL_LEFT_UP, diagonalLeftSpeed);

		}

		void GreenDuckController::MoveDiagonalRightUP()
		{
			
			MoveInDirection(MovementDirection::DIAGONAL_RIGHT_UP, diagonalRightSpeed);

			
		}

		
*/


	}

}