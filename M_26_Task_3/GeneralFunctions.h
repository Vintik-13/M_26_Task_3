#pragma once

#include <iostream>
#include <iomanip>
#include "Window.h"
#include "Display.h"

namespace Main {
	bool ValidInt(const std::string str, int& i);
	bool WindowName(int x, int y, Window win);
	bool CharOne(int x, int y, Window win);
	void showDisplay(Display& disp);
	void Move(Display& disp);
	void Resize(Display& disp);
	void ChangeActiv(Display& disp);
}


