#include "windowManager.h"
#include "../timeline/exitKey.h"

EXITKEY exitKeyState;

bool WindowShouldClose()
{
	switch (exitKeyState.exit)
	{
	case exitKeyState.PRESSED:
		return true;
		break;

	default:
		return false;
	}
}
