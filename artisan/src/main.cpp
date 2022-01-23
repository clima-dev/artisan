#include "../include/Artisan.h"
#include <ctime>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define PIPE_SCREEN_COUNT 4

typedef struct Pipe {
    float x, y;
} Pipe;

float RandomFloat(float min, float max)
{
    return (min + 1) + (((float)rand()) / (float)RAND_MAX) * (max - (min + 1));
}

int main(void)
{
    artisan::Window win(SCREEN_WIDTH,SCREEN_HEIGHT,"Artisan | Flappy Bird");

    win.setBgColor(artisan::RGBColor{ 244, 98, 54 });

    Rect player = { 50, 50, 50, 50 };
    Rect rec2 = { 400, 300, 100, 100 };
    Rect floor = { 0, SCREEN_HEIGHT - 25, 10000, 50 };
    
    bool dead = false;
    Pipe groundPipes[PIPE_SCREEN_COUNT];
    Rect groundPipesRec[PIPE_SCREEN_COUNT];

    Pipe ceilingPipes[PIPE_SCREEN_COUNT];
    Rect ceilingPipesRec[PIPE_SCREEN_COUNT];

    bool col1 = false;
    bool col2 = false;
    bool col3 = false;

    float pipeWidth = 90;
    float pipeNormalHeight = 300;
    float pipeCeilingHeight = 320;
    float speed = 1.f;
    bool collisionFloor = false;

    float birdPosY = 90;
    float birdSpeed = 0;
    float gravity = .1;

    Font jetMono = load_font("src/JetBrainsMono-Regular.ttf", "jetMono");

    srand(time(NULL));

    for  (int i = 0; i < PIPE_SCREEN_COUNT; i++)
    {
        groundPipes[i].x = 250 * i + SCREEN_WIDTH;
        groundPipes[i].y = RandomFloat(SCREEN_HEIGHT / 1.5, SCREEN_HEIGHT / 2);

        groundPipesRec[i] = { groundPipes[i].x, groundPipes[i].y, pipeWidth, pipeNormalHeight };

        ceilingPipes[i].x = groundPipes[i].x;
        ceilingPipes[i].y = groundPipes[i].y - 300 - 130;

        ceilingPipesRec[i] = { groundPipes[i].x, ceilingPipes[i].y, pipeWidth, pipeCeilingHeight };

        std::cout << groundPipes[i].x << std::endl;
    }

    while (!win.closed())
    {  
        player.y = birdPosY;

        begin_drawing();
            
            clear_bg(win.getBgColor()); 

            // rendering here
            draw_rectangle_rec(player, WHITE);
            draw_rectangle_rec(floor, RED);

            for (int i = 0; i < PIPE_SCREEN_COUNT; i++)
            {
                draw_rectangle_rec(groundPipesRec[i], GREEN);
                draw_rectangle_rec(ceilingPipesRec[i], GREEN);

                col1 = rec_colliding(player, groundPipesRec[i]);
                col2 = rec_colliding(player, ceilingPipesRec[i]);
                col3 = rec_colliding(player, floor);

                if (col1 || col2 || col3) {
                    draw_text(jetMono, "You lost! Imagine...", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 20, BLACK);
                    dead = true;
                    speed = 0;
                }

                if (col3) {
                    collisionFloor = true;
                }

                groundPipes[i].x -= 2;
                ceilingPipes[i].x -= 2;

                if (groundPipes[i].x + 90 < 0) {
                    groundPipes[i].x = 1.1 * SCREEN_WIDTH;

                    groundPipes[i].y = RandomFloat(SCREEN_HEIGHT / 1.5, SCREEN_HEIGHT / 2);

                    ceilingPipes[i].x = groundPipes[i].y;
                    ceilingPipes[i].y = groundPipes[i].y - 300 - 130;

                    groundPipesRec[i] = { groundPipes[i].x, groundPipes[i].y, pipeWidth, pipeNormalHeight };

                    ceilingPipesRec[i] = { groundPipes[i].x, ceilingPipes[i].y, pipeWidth, pipeCeilingHeight };
                }

                groundPipesRec[i] = { groundPipes[i].x, groundPipes[i].y, pipeWidth, pipeNormalHeight };
                ceilingPipesRec[i] = { groundPipes[i].x, ceilingPipes[i].y, pipeWidth, pipeCeilingHeight };

            }

        end_drawing(win);

        if (win.KeySpace() && dead == false) { birdSpeed = -2.6f; };

        if (speed > 0 && collisionFloor == false)
        {
            birdPosY += birdSpeed;
            birdSpeed += gravity;
        }
        else {
            birdPosY = floor.y - 30;
        }
    }

    return 0;
}