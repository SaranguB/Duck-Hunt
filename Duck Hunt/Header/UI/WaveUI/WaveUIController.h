#pragma once
#include "../../Header/UI/Interface/IUIController.h"

namespace UI
{
	namespace WaveUI
	{
		class WaveUIController : public Interface::IUIController
		{
		private:


		public:
			WaveUIController();
			~WaveUIController();

			void Initialize() override;
			void Update() override;
			void Render() override;

			void Show() override;

		};
	}
}
