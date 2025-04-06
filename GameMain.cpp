#include "Application.h"

using namespace ArkanoidGame;

int main() {

	// Init random seed
	srand(time(NULL));

	setlocale(LC_ALL, "ru");
	Application::Instance().Run();
	return 0;
}