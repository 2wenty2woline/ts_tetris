#include <time.h>
#include "TestApp.h"

void main()
{
	srand(time(0));
	TestApp app;
	app.Run();
}