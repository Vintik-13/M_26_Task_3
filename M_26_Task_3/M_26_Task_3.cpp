/*Задание 3. Реализация программы управления окном рабочего стола

Что нужно сделать
Реализуйте симуляцию работы окна в визуальном интерфейсе пользователя.
Окно располагается на виртуальном экране монитора, размером 80 × 50 точек.
У окна есть несколько параметров, которые также задаются в пикселях:
двумерные координаты левого верхнего угла и размеры, ширина и высота.
Ширина и высота при этом не могут быть отрицательными, а координаты
не могут выходить за область экрана.
Пользователь взаимодействует с программой с помощью команд:
Команда move принимает вектор, на который надо сместить окно на экране.
Сообщение с новыми координатами окна появляется на экране.
Команда resize запрашивает из стандартного ввода новый размер окна.
После изменения размера сообщение с новым размером выводится на экране.
Команда display выводит текущее изображение монитора в консоль.
0 — это пиксель вне области окна, 1 — с окном.
Команда close закрывает окно, выход из программы.*/

#include <algorithm>
#include "GeneralFunctions.h"

int main()
{
    Window win;
    win.setNameWindow("Window #2");
    win.setXY(0, 0);
    win.setHeight(10);
    win.setWidth(10);
    win.setAction(false);
    Display disp(win);

    win.setNameWindow("Window #3");
    win.setXY(20, 20);
    win.setHeight(15);
    win.setWidth(15);
    win.setAction(true);
    disp.addWindow(win);

    win.setNameWindow("Window #4");
    win.setXY(7, 7);
    win.setHeight(3);
    win.setWidth(3);
    win.setAction(false);
    disp.addWindow(win);

    Main::showDisplay(disp);

    std::vector<std::string> pattern{ "MOVE", "RESIZE", "DISPLAY", "CHANGE", "EXIT" };
    for (std::vector<std::string>::iterator it = pattern.begin(); it != pattern.end(); it++) {
        std::cout << *it << std::endl;
    }
    std::string comand;        

    while (true) {
        std::cout << "\nEnter the command: ";
        std::getline(std::cin, comand);
        std::transform(comand.begin(), comand.end(), comand.begin(), std::toupper);
        if (comand == pattern[0]) {
            Main::Move(disp);
        }
        else if (comand == pattern[1]) {
            Main::Resize(disp);
        }
        else if (comand == pattern[2]) {
            Main::showDisplay(disp);
        }
        else if (comand == pattern[3]) {
            Main::ChangeActiv(disp);
        }
        else if (comand == pattern[4])
            break;
        else {
            std::cout << "\nNot the right team.\nTry again!";
        }
    }
}

