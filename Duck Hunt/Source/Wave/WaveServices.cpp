#include "../../Header/Wave/WaveServices.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Wave
{
	using namespace Player;

	WaveService::WaveService()
	{
		
	}

	WaveService::~WaveService()
	{
	}

	void WaveService::Initialize()
	{
	}

	void WaveService::Update()
	{
		if (checkTimeForChange())
		{
			Reset();
		}
	}

	void WaveService::Reset()
	{
		waveTimer = 0;
		clock.restart();
	}
	bool WaveService::checkTimeForChange()
	{	
		return clock.getElapsedTime().asSeconds() >=5 ;
	}
	


}