
#ifndef WINDOW_MGR
#define WINDOW_MGR

#include <vector>
#include <string>
#include <iostream>
#include "newscreen.h"

class BitMap;
extern std::stream& storeOn(std::stream &, Screen &);
extern BitMap& storeOn(BitMap &, Screen &);

class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    ScreenIndex addScreen(const Screen&);
    void clear(ScreenIndex);
    void resize(Screen::pos r, Screen::pos c, ScreenIndex i);

private:
    std::vector<Screen> screen(Screen(24, 80, ' '));
};


inline Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &s)
{
    screen.push_back(s);
    return screen.size() - 1;
}

inline void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screen[i];
    s.contents = std::string(s.height * s.width, ' ');
}

inline void Window_mgr::resize(Screen::pos r, Screen::pos c, ScreenIndex i)
{
    screen[i].height = r;
    screen[i].width = c;
    screen[i].contents = std::string(r*c, ' ');
}

#endif
