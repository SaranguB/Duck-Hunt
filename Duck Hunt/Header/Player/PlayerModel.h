#pragma once

namespace Player
{
	
	class PlayerModel
	{
	private:
		int playerScore;
		int playerAmmo;

	public:
		PlayerModel();
		~PlayerModel();

		void Initialize();
		
		
		void SetPlayerScore(int score);
		



	};
}
