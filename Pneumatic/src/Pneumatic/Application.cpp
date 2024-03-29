#include "pneupch.h"
#include "Application.h"

#include "Pneumatic/Log.h"

#include <glad/glad.h>

namespace Pneumatic {


	Application* Application::s_Instance = nullptr;

	Application::Application() {
		PNEU_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(PNEU_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application() {

	}

	void Application::Run() {

		while (m_Running) {

			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();

		}
	}

	void Application::OnEvent(Event& e) {

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(PNEU_BIND_EVENT_FN(Application::OnWindowClose));

		//PNEU_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	bool Application::OnWindowClose(WindowCloseEvent e) {
		m_Running = false;
		return true;
	};
}