#include "../../Header/Player/PlayerModel.h"

namespace Player
{
	int PlayerModel::playerAmmo = 0;
	int PlayerModel::enemiesKilled = 0;

	PlayerModel::PlayerModel()
	{
		playerAmmo = maxPlayerAmmo;
	}
	PlayerModel::~PlayerModel()
	{
	}
	void PlayerModel::Initialize()
	{
	}

	void PlayerModel::SetPlayerScore(int score)
	{
	}

	int PlayerModel::GetPlayerAmmo()
	{
		return playerAmmo;
	}
	

}