#pragma once

#ifdef PNEU_PLATFORM_WINDOWS
	
extern Pneumatic::Application* Pneumatic::CreateApplication();

int main(int argc, char** argv) {
	Pneumatic::Log::Init();
	PNEU_CORE_WARN("Initialized Log");
	PNEU_INFO("Initialized Log");

	auto app = Pneumatic::CreateApplication();
	app->Run();
	delete app;
}

#endif // PNEU_PLATFORM_WINDOWS
