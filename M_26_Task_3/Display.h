#pragma once
#include <vector>
#include "Window.h"

class Display {
	std::vector<Window> m_winList;
public:
	Display(Window win);
	std::vector<Window> getWindovs();
	void setZeroXY(int x, int y, int num);
	void setSizeWindow(int x, int y, int num);
	size_t getCountWindows();
	int getActivWindow();
	void changeWin(int num);
	void addWindow(Window win);
};

