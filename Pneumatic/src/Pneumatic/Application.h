#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Pneumatic {

	class PNEUMATIC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//CLIENT
	Application* CreateApplication();

}