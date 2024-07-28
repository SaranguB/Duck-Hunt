#pragma once

namespace Player
{
	
	class PlayerModel
	{
	private:
		int playerScore;
		
		int maxPlayerAmmo = 5;
	;

	public:
		PlayerModel();
		~PlayerModel();

		void Initialize();
		
		
		void SetPlayerScore(int score);
		int GetPlayerAmmo();
	
		
		static int playerAmmo;


	};
}
