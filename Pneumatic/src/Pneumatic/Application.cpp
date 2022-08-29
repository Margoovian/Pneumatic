#include "pneupch.h"
#include "Application.h"

#include "Pneumatic/Events/Application.h"
#include "Pneumatic/Log.h"

namespace Pneumatic {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}