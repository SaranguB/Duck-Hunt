#include "../../Header/Global/ServiceLocator.h"

namespace Global
{
	using namespace Graphics;

	ServiceLocator::ServiceLocator()
	{
		CreateServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		ClearAllServices();
	}
	
	void ServiceLocator::CreateServices()
	{
		graphicService = new GraphicService();
	}

	void ServiceLocator::ClearAllServices()
	{
		delete(graphicService);
	}

	ServiceLocator* ServiceLocator::GetInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::Initialize()
	{
		graphicService->Initialize();
	}
	void ServiceLocator::Update()
	{

	}
	void ServiceLocator::Render()
	{

	}
	Graphics::GraphicService* ServiceLocator::GetGraphicService()
	{
		return graphicService;
	}
}