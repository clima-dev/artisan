#include "../include/Window.h"
#include "../include/Objects/Rect.h"
#include "../include/Vector2.h"

int main(void)
{
    artisan::Window win(800,600,"Artisan | Main Window");

    win.setBgColor(artisan::RGBColor{ 244, 98, 54 });

    while (!win.closed())
    {
        artisan::Rect rect(artisan::Vect2{30, 30}, artisan::Vect2{300, 300});

        rect.Render();

        if (win.KeyD())
        {
            std::cout << "Key D Pressed!" << std::endl;
        }

        win.update();
    }

    return 0;
}