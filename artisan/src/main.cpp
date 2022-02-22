#include "../include/Artisan.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
int main(void)
{
    artisan::Window win(SCREEN_WIDTH,SCREEN_HEIGHT,"Artisan | Flappy Bird");

    win.setBgColor(artisan::RGBColor{ 244, 98, 54 });

    Circle c1{
        100, 100, 100.f
    };

    Circle c2{
        200, 200, 100.f
    };

    while (!win.closed())
    {  
        // game loop
        
        

        begin_drawing();

            read_aeg_data("data.aeg", &win);

            draw_imgui(false);

            clear_bg(win.getBgColor());

            

        end_drawing(win);
    }

    return 0;
}