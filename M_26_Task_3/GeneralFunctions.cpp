#include "GeneralFunctions.h"

namespace Main {
    bool ValidInt(const std::string str, int& i) {

        try {
            i = std::stoi(str);
            return true;
        }
        catch (const std::exception& ex) {            
            return false;
        }        
    }

    void ChangeActiv(Display& disp) {
        std::string activ;
        for (int i = 0; i < disp.getCountWindows(); i++) {            
            activ = (disp.getWindovs()[i].getAction()) ? "Active window" : "Passive window";
            std::cout << i + 1 << ". " << disp.getWindovs()[i].getNameWindow() << " " << activ << std::endl;
        }
        std::cout << "\nEnter the activation window number: ";
        std::string num;
        int intNum {-1};
        std::getline(std::cin, num);
        
        while (!Main::ValidInt(num, intNum) && (intNum >= 1 && intNum <= disp.getCountWindows())) {
            std::cout << "Input error!\nTry again\n";
            std::getline(std::cin, num);
        }
        disp.changeWin(intNum - 1);
        for (int i = 0; i < disp.getCountWindows(); i++) {
            activ = (disp.getWindovs()[i].getAction()) ? "Active window" : "Passive window";
            std::cout << i + 1 << ". " << disp.getWindovs()[i].getNameWindow() << " " << activ << std::endl;
        }
    }

    //Если истина рисуем char строки имя окна
    bool WindowName(int x, int y, Window win) {

        bool if1 = y == win.getYZero() && x >= win.getXZero();
        bool if2 = x < win.getXZero() + win.getNameWindow().size();
        bool if3 = x < win.getXZero() + win.getWidth();
        bool if4 = x < MAX_WIDTH_DISPLAY;

        if (if1 && ((if2 && if3) && if4))
            return true;
        else
            return false;
    }

    //Если истина рисуем *
    bool CharOne(int x, int y, Window win) {        

        bool if1 = (x >= win.getXZero() && y >= win.getYZero());
        bool if2 = (x < win.getXZero() + win.getWidth()) && (y < win.getYZero() + win.getHeight());

        if (if1 && if2)
            return true;
        else
            return false;
    }

    void showDisplay(Display& disp) {
        for (int i = 0; i < disp.getCountWindows(); i++) {
            std::string activ;
            activ = (disp.getWindovs()[i].getAction()) ? "ACTIVE" : "Passive";
            std::cout << i + 1 << ". "
                      << disp.getWindovs()[i].getNameWindow() << " "
                      << " Location: X = " << disp.getWindovs()[i].getXZero() << " Y = " << disp.getWindovs()[i].getYZero() << "  "
                      << " Size: Width - " << disp.getWindovs()[i].getWidth() << " Height - " << disp.getWindovs()[i].getHeight() << "  "
                      << activ << std::endl;
        }
        std::cout << std::endl;
        for (auto& it : disp.getWindovs()) {
            if (it.getAction() == true) {
                for (int y = 0; y < MAX_HEIGT_DISPLAY; y++) {
                    for (int x = 0; x < MAX_WIDTH_DISPLAY; x++) {
                        if (WindowName(x, y, it))
                            std::cout << it.getNameWindow()[x - it.getXZero()];
                        else if (CharOne(x, y, it))
                            std::cout << "*";
                        else
                            std::cout << "0";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
            }
        }
    }

    void Move(Display& disp) {
        int oldX, oldY;
        std::cout << "Active Window ";
        for (auto p : disp.getWindovs()) {
            if(p.getAction() == true)
                std::cout << p.getNameWindow() << std::endl;            
        }
        std::cout << "Enter the coordinates of the window offset vector: ";
        std::string xStr, yStr;
        int x, y;
        std::cout << "Enter X: ";
        std::getline(std::cin, xStr);
        while (!Main::ValidInt(xStr, x)) {
            std::cout << "Input error!\nTry again\n";
            std::getline(std::cin, xStr);
        }
        std::cout << "Enter Y: ";
        std::getline(std::cin, yStr);
        while (!Main::ValidInt(yStr, y)) {
            std::cout << "Input error!\nTry again\n";
            std::getline(std::cin, yStr);
        }
        oldX = disp.getWindovs()[disp.getActivWindow()].getXZero();
        oldY = disp.getWindovs()[disp.getActivWindow()].getYZero();
        disp.setZeroXY(x, y, disp.getActivWindow());        
        
        std::cout << "Old coordinates X = " << oldX << " Y = " << oldY << std::endl
            << "New coordinates X = " << disp.getWindovs()[disp.getActivWindow()].getXZero()
            << " Y = " << disp.getWindovs()[disp.getActivWindow()].getYZero() << std::endl;
    }

    void Resize(Display& disp) {
        int oldWidthSize, oldHeghtSize;
        std::cout << "Active Window ";
        for (auto p : disp.getWindovs()) {
            if (p.getAction() == true)
                std::cout << p.getNameWindow() << std::endl;
        }
        std::cout << "Enter a new window size: ";
        std::string xStr, yStr;
        int x, y;
        std::cout << "Enter Width: ";
        std::getline(std::cin, xStr);
        while (!Main::ValidInt(xStr, x)) {
            std::cout << "Input error!\nTry again\n";
            std::getline(std::cin, xStr);
        }
        std::cout << "Enter Height: ";
        std::getline(std::cin, yStr);
        while (!Main::ValidInt(yStr, y)) {
            std::cout << "Input error!\nTry again\n";
            std::getline(std::cin, yStr);
        }
        oldWidthSize = disp.getWindovs()[disp.getActivWindow()].getWidth();
        oldHeghtSize = disp.getWindovs()[disp.getActivWindow()].getYZero();
        disp.setSizeWindow(x, y, disp.getActivWindow());

        std::cout << "Old size = " << oldWidthSize << " x " << oldHeghtSize << std::endl
            << "New size = " << disp.getWindovs()[disp.getActivWindow()].getWidth()
            << " x " << disp.getWindovs()[disp.getActivWindow()].getHeight() << std::endl;
    }    
}


