#pragma once

#ifdef PNEU_PLATFORM_WINDOWS
	
extern Pneumatic::Application* Pneumatic::CreateApplication();

int main(int argc, char** argv) {
	auto app = Pneumatic::CreateApplication();
	app->Run();
	delete app;
}

#endif // PNEU_PLATFORM_WINDOWS
