#pragma once

typedef struct color
{
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int a;
} color;

#define WHITE      color{255,255,255,255}
#define GRAY       color{84, 84, 84, 255}
#define RED        color{255,0,0,255}
#define ORANGE     color{255,153,51,255}
#define GREEN      color{102,255,102,255}
#define BLUE       color{0,128,255,255}
#define PURPLE     color{178,102,255,255}
#define PINK       color{255,204,255,255}
#define MAGENTA    color{255,102,255,255}
#define YELLOW     color{255,255,51,255}
#define USAF_BLUE  color{0,48,143,255}
#define BLACK      color{0,0,0,255}