#include <Pneumatic.h>

class Sandbox : public Pneumatic::Application {
public:
	Sandbox() {

	}
	~Sandbox(){

	}
};

Pneumatic::Application* Pneumatic::CreateApplication() {
	return new Sandbox();
}