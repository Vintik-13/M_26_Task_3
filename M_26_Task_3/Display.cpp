#include "Display.h"

Display::Display(Window win) {
	m_winList.push_back(win);
}

std::vector<Window> Display::getWindovs() {
	return m_winList;
}

void Display::setZeroXY(int x, int y, int num) {
	m_winList[num].setXY(x, y);
}

void Display::setSizeWindow(int x, int y, int num) {
	m_winList[num].setWidth(x);
	m_winList[num].setHeight(y);
}

size_t Display::getCountWindows() {
	return m_winList.size();
}

int Display::getActivWindow() {
	for (int i = 0; i < m_winList.size(); i++)
		if (m_winList[i].getAction())
			return i;
}

void Display::changeWin(int num) {
	for (int i = 0; i < m_winList.size(); i++) 
		m_winList[i].setAction(i == num ? true : false);		
}

void Display::addWindow(Window win) {
	m_winList.push_back(win);
}
