#pragma once
#include <string>

const size_t MAX_WIDTH_DISPLAY = 15;
const size_t MAX_HEIGT_DISPLAY = 10;

class Window {
	std::string m_nameWinow{""};
	size_t m_xZero{ 0 };
	size_t m_yZero{ 0 };
	size_t m_width{ 0 };
	size_t m_height{ 0 };
	bool m_actionWindow = false;

public:
	void setNameWindow(std::string name);
	void setXY(size_t x, size_t y);	
	void setHeight(size_t hight);
	void setWidth(size_t width);
	void setAction(bool flag);

	std::string getNameWindow();
	size_t getXZero();
	size_t getYZero();
	size_t getHeight();
	size_t getWidth();
	bool getAction();

};

