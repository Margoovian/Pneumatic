#pragma once

#include "Core.h"

#include "Window.h"
#include "Pneumatic/LayerStack.h"
#include "Events/Event.h"
#include "Pneumatic/Events/ApplicationEvents.h"



namespace Pneumatic {

	class PNEUMATIC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private: 
		static Application* s_Instance;
	};

	//CLIENT
	Application* CreateApplication();

}