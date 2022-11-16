#include "Window.h"

void Window::setNameWindow(std::string name) {
	m_nameWinow = name;
}

void Window::setXY(size_t x, size_t y) {
	if (x >= 0 && x <= MAX_WIDTH_DISPLAY)
		m_xZero = x;
	else if (x < 0)
		m_xZero = 0;
	else
		m_xZero = MAX_WIDTH_DISPLAY;

	if (y >= 0 && y <= MAX_HEIGT_DISPLAY)
		m_yZero = y;
	else if (y < 0)
		m_yZero = 0;
	else
		m_yZero = MAX_HEIGT_DISPLAY;
}

void Window::setHeight(size_t height) {
	if (height <= MAX_HEIGT_DISPLAY - m_yZero)
		m_height = height;
	else
		m_height = MAX_HEIGT_DISPLAY - m_yZero;
}

void Window::setWidth(size_t width) {
	if (width <= MAX_WIDTH_DISPLAY - m_xZero)
		m_width = width;
	else
		m_width = MAX_WIDTH_DISPLAY - m_xZero;
}

void Window::setAction(bool flag) {
	m_actionWindow = flag;
}

std::string Window::getNameWindow() {
	return m_nameWinow;
}

size_t Window::getXZero() {
	return m_xZero;
}

size_t Window::getYZero() {
	return m_yZero;
}

size_t Window::getHeight() {
	return m_height;
}

size_t Window::getWidth() {
	return m_width;
}

bool Window::getAction() {
	return m_actionWindow;
}
