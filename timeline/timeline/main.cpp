#include "manager.h"
#include "../timeline_static_library/windowManager.h"

int main()
{


	while (!WindowShouldClose())
	{
		sceneManager();
	}


	return 0;
}