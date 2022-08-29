#include "pneupch.h"
#include "Application.h"

#include "Pneumatic/Events/Application.h"
#include "Pneumatic/Log.h"

namespace Pneumatic {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1920, 1080);
		PNEU_WARN(e.ToString());
		while (true);
	}
}