#include "../include/Artisan.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(void)
{
    artisan::Window win(SCREEN_WIDTH,SCREEN_HEIGHT,"Artisan | Plain Window");

    win.setBgColor(artisan::RGBColor{ 244, 98, 54 });

    while (!win.closed())
    {  
        // game loop
        
        begin_drawing();
            
            clear_bg(win.getBgColor()); 

            // rendering

        end_drawing(win);
    }

    return 0;
}
