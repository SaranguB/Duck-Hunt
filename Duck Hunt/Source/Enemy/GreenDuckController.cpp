#include "../../Header/Enemy/GreenDuckController.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
namespace Enemy
{
	namespace Controller
	{
		using namespace Global;


		GreenDuckController::GreenDuckController(EnemyType type) : EnemyController(type)
		{
		}

		GreenDuckController::~GreenDuckController()
		{

		}


		void GreenDuckController::Initialize()
		{
			EnemyController::Initialize();
		}


		void GreenDuckController::Move()
		{
			switch (GetRandomMovementDirection())
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

			if (CurrentPosition.x <= enemyModel->LeftMostPosition.x)
			{
				Move();
			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}
		}

		void GreenDuckController::MoveRight()
		{
			sf::Vector2f CurrentPosition = enemyModel->GetEnemyPosition();
			CurrentPosition.x += verticalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (CurrentPosition.x >= enemyModel->RightMostPosition.x)
			{
				Move();
			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}

		}

		void GreenDuckController::MoveUP()
		{
			sf::Vector2f CurrentPosition = enemyModel->GetEnemyPosition();
			CurrentPosition.y += verticalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (CurrentPosition.y <= enemyModel->TopMostPosition.y)
			{
				Move();
			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}
		}

		void GreenDuckController::MoveDown()
		{
			sf::Vector2f CurrentPosition = enemyModel->GetEnemyPosition();
			CurrentPosition.y -= verticalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (CurrentPosition.y >= enemyModel->BottomMostPosition.y)
			{
				Move();
			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}
		}

		void GreenDuckController::MoveDiagonalLeftDown()
		{
			sf::Vector2f CurrentPosition = enemyModel->GetEnemyPosition();

			CurrentPosition.x -= verticalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			CurrentPosition.y += verticalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (CurrentPosition.y >= enemyModel->BottomMostPosition.y ||
				CurrentPosition.y <= enemyModel->TopMostPosition.y ||
				CurrentPosition.x <= enemyModel->LeftMostPosition.x ||
				CurrentPosition.x >= enemyModel->RightMostPosition.x)
			{
				Move();
			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}
		}

		void GreenDuckController::MoveDiagonalRightDown()
		{
			sf::Vector2f CurrentPosition = enemyModel->GetEnemyPosition();

			CurrentPosition.x += verticalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			CurrentPosition.y += verticalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (CurrentPosition.y >= enemyModel->BottomMostPosition.y ||
				CurrentPosition.y <= enemyModel->TopMostPosition.y ||
				CurrentPosition.x <= enemyModel->LeftMostPosition.x ||
				CurrentPosition.x >= enemyModel->RightMostPosition.x)
			{
				Move();
			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}
		}

		void GreenDuckController::MoveDiagonalLeftUP()
		{
			sf::Vector2f CurrentPosition = enemyModel->GetEnemyPosition();

			CurrentPosition.x -= verticalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			CurrentPosition.y -= verticalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (CurrentPosition.y >= enemyModel->BottomMostPosition.y ||
				CurrentPosition.y <= enemyModel->TopMostPosition.y ||
				CurrentPosition.x <= enemyModel->LeftMostPosition.x ||
				CurrentPosition.x >= enemyModel->RightMostPosition.x)
			{
				Move();
			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}

		}

		void GreenDuckController::MoveDiagonalRightUP()
		{
			
			sf::Vector2f CurrentPosition = enemyModel->GetEnemyPosition();

			CurrentPosition.x += verticalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
			CurrentPosition.y -= verticalSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (CurrentPosition.y >= enemyModel->BottomMostPosition.y ||
				CurrentPosition.y <= enemyModel->TopMostPosition.y ||
				CurrentPosition.x <= enemyModel->LeftMostPosition.x ||
				CurrentPosition.x >= enemyModel->RightMostPosition.x)
			{
				Move();
			}
			else
			{
				enemyModel->SetEnemyPosition(CurrentPosition);
			}
		}

		






	}

}