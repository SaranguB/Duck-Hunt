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
				MoveLeft();
				break;

			case MovementDirection::RIGHT:
				MoveRight();
				break;

			case MovementDirection::UP:
				MoveUP();
				break;

			case MovementDirection::DOWN:
				MoveDown();
				break;

			case MovementDirection::DIAGONAL_LEFT_UP:
				MoveDiagonalLeftUP();
				break;

			case MovementDirection::DIAGONAL_LEFT_DOWN:
				MoveDiagonalLeftDown();
				break;

			case MovementDirection::DIAGONAL_RIGHT_UP:
				MoveDiagonalRightUP();
				break;

			case MovementDirection::DIAGONAL_RIGHT_DOWN :
				MoveDiagonalRightDown();
				break;

			}
		}

		
		void GreenDuckController::MoveLeft()
		{
			
			sf::Vector2f CurrentPosition = enemyModel->GetEnemyPosition();
			CurrentPosition.x -= verticalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (enemyModel->GetEnemyPosition().x <= enemyModel->LeftMostPosition.x)
			{
				currentDirection = GetRandomMovementDirection();
				directionChangeClock.restart();
				//std::cout << "Hit Left Boundary, new direction: " << static_cast<int>(currentDirection) << std::endl;
			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}
		}

		void GreenDuckController::MoveRight()
		{
			
			//printf("moveright");

			sf::Vector2f CurrentPosition = enemyModel->GetEnemyPosition();
			CurrentPosition.x += verticalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (enemyModel->GetEnemyPosition().x >= enemyModel->RightMostPosition.x)
			{
				currentDirection = GetRandomMovementDirection();
				directionChangeClock.restart();
				//std::cout << "Hit Right Boundary, new direction: " << static_cast<int>(currentDirection) << std::endl;


			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}

		}

		void GreenDuckController::MoveUP()
		{
			

			sf::Vector2f CurrentPosition = enemyModel->GetEnemyPosition();
			CurrentPosition.y -= HorizontalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (CurrentPosition.y <= enemyModel->TopMostPosition.y)
			{
				currentDirection = GetRandomMovementDirection();
				directionChangeClock.restart();
				//std::cout << "Hit Right Boundary, new direction: " << static_cast<int>(currentDirection) << std::endl;


			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}
		}

		void GreenDuckController::MoveDown()
		{
			sf::Vector2f CurrentPosition = enemyModel->GetEnemyPosition();
			CurrentPosition.y += HorizontalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (enemyModel->GetEnemyPosition().y >= enemyModel->BottomMostPosition.y)
			{
				currentDirection = GetRandomMovementDirection();
				directionChangeClock.restart();

			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}
		}

		void GreenDuckController::MoveDiagonalLeftDown()
		{
			sf::Vector2f CurrentPosition = enemyModel->GetEnemyPosition();

			CurrentPosition.x -= diagonalLeftSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			CurrentPosition.y += diagonalLeftSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (enemyModel->GetEnemyPosition().y >= enemyModel->BottomMostPosition.y ||
				enemyModel->GetEnemyPosition().x <= enemyModel->LeftMostPosition.x )
			{
				currentDirection = GetRandomMovementDirection();
				directionChangeClock.restart();
			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}
		}

		void GreenDuckController::MoveDiagonalRightDown()
		{
			sf::Vector2f CurrentPosition = enemyModel->GetEnemyPosition();

			CurrentPosition.x += diagonalRightSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			CurrentPosition.y += diagonalRightSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (enemyModel->GetEnemyPosition().y >= enemyModel->BottomMostPosition.y ||
				enemyModel->GetEnemyPosition().x >= enemyModel->RightMostPosition.x)
			{
				currentDirection = GetRandomMovementDirection();
				directionChangeClock.restart();

			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}
		}

		void GreenDuckController::MoveDiagonalLeftUP()
		{
			sf::Vector2f CurrentPosition = enemyModel->GetEnemyPosition();

			CurrentPosition.x -= diagonalLeftSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			CurrentPosition.y -= diagonalLeftSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (enemyModel->GetEnemyPosition().y <= enemyModel->TopMostPosition.y ||
				enemyModel->GetEnemyPosition().x <= enemyModel->LeftMostPosition.x )
			{
				currentDirection = GetRandomMovementDirection();
				directionChangeClock.restart();
					
			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}

		}

		void GreenDuckController::MoveDiagonalRightUP()
		{
			
			sf::Vector2f CurrentPosition = enemyModel->GetEnemyPosition();

			CurrentPosition.x += diagonalRightSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			CurrentPosition.y -= diagonalRightSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (enemyModel->GetEnemyPosition().y <= enemyModel->TopMostPosition.y ||
				enemyModel->GetEnemyPosition().x >= enemyModel->RightMostPosition.x)
			{
				currentDirection = GetRandomMovementDirection();
				directionChangeClock.restart();

			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}
		}

		






	}

}