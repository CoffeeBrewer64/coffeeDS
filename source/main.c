#include <util/util_log.h>
#include <cart/cart_read.h>
#include <cpu/cpu.h>
#include <cpu/arm7/cpu_arm7_init.h>
#include <stdbool.h>
#include <main.h>
#include <SDL2/SDL.h>

bool isRunning;
SDL_Event event;
SDL_Window* main_window;
SDL_Renderer* main_renderer;

int main()
{
    isRunning = true;
    LOG("Started coffeeDS!");
    cpu_init();
    cartRead_init();

    main_window = SDL_CreateWindow("coffeeDS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 256, 384, 0);
    main_renderer = SDL_CreateRenderer(main_window, 0, 0);

    main_loop();

    SDL_DestroyWindow(main_window);
    SDL_Quit();

    LOG("Ended coffeeDS!");
    return 0;
}

void main_loop()
{
    while (isRunning == true)
    {
        // Main loop

        // Event polling goes at the top above everything else because it is a frontend matter
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_q)
                {
                    isRunning = false;
                }
            }

        }

        // If the reset register of PC is set to -1 (fixing resets with this register is a todo)
        if (current_arm7_registers.SysAndUser_registers.r15_PC == -1)
        {
            isRunning = false;
        }

    }
}
