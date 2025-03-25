#pragma once

struct EXITKEY
{
	enum exitButton { NOT_PRESSED,PRESSED};
	exitButton exit = NOT_PRESSED;
};

extern EXITKEY exitKeyState;