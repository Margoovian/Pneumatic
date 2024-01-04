#pragma once

#ifdef PNEU_PLATFORM_WINDOWS
	
extern Pneumatic::Application* Pneumatic::CreateApplication();

int main(int argc, char** argv) {
	Pneumatic::Log::Init();

	auto app = Pneumatic::CreateApplication();
	app->Run();
	delete app;
}

#endif // PNEU_PLATFORM_WINDOWS
