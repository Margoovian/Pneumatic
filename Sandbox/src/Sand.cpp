#include <Pneumatic.h>

class DemoLayer : public Pneumatic::Layer
{
public:
	DemoLayer()
		: Layer("Demo Layer")
	{	}

	void OnUpdate() override {
		//PNEU_INFO("DemoLayer::Update");
	}

	void OnEvent(Pneumatic::Event& event) override {
		//PNEU_TRACE("{0}", event);
	}
};

class Sandbox : public Pneumatic::Application {
public:
	Sandbox() {
		PushLayer(new DemoLayer());
		PushOverlay(new Pneumatic::ImGuiLayer());
	}
	~Sandbox(){

	}
};

Pneumatic::Application* Pneumatic::CreateApplication() {
	return new Sandbox();
}