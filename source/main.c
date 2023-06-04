#include <util/util_log.h>
#include <cart/cart_read.h>
#include <cpu/cpu.h>
#include <cpu/common/cpu_read.h>
#include <cpu/arm7/cpu_arm7_init.h>
#include <stdbool.h>
#include <main.h>
#include <SDL2/SDL.h>

bool isRunning;
SDL_Event event;
SDL_Window* main_window;
SDL_Renderer* main_renderer;

// The NDS screen is 256x192. 192 * 2 = 384 (this allows us to have two screens on display during emulation)
const int screen_size_x = 256;
const int screen_size_y = 384;
int screen_size_x_multipler = 1;
int screen_size_y_multiplier = 1;
bool macro_mode = false; // NOTE: Macro mode = GBA mode
bool macro_mode_useTopScreen = true; // If true, the top screen will be used. If false, the bottom screen will be used.

int main()
{
    isRunning = true;
    LOG("Started coffeeDS!");
    cpu_init();
    cartRead_init();

    main_window = SDL_CreateWindow("coffeeDS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_size_x * screen_size_x_multipler, screen_size_y * screen_size_y_multiplier, 0);
#ifdef CONFIG_USE_HARDWARE_ACCELERATION
    main_renderer = SDL_CreateRenderer(main_window, 0, SDL_RENDERER_ACCELERATED);
#else
    main_renderer = SDL_CreateRenderer(main_window, 0, 0);
#endif // CONFIG_USE_HARDWARE_ACCELERATION

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
                switch (event.key.keysym.sym)
                {
                    case SDLK_q:
                        isRunning = false;
                        break;

                    case SDLK_1:
                        main_dumpOpcodes();
                        break;

                    case SDLK_m:
                        switch (macro_mode)
                        {
                            case false:
                                macro_mode = true;
                                LOG("Set macro mode to true");
                                break;
                            case true:
                                macro_mode = false;
                                LOG("Set macro mode to false");
                                break;
                        }
                        break;

                    case SDLK_n:
                        switch (macro_mode_useTopScreen)
                        {
                            case false:
                                macro_mode_useTopScreen = true;
                                LOG("Switched from using the bottom screen to the top screen in macro mode!");
                                break;
                            case true:
                                macro_mode_useTopScreen = false;
                                LOG("Switched from using the top screen to the bottom screen in macro mode!");
                                break;
                        }
                        break;
                }

            }

            // If the reset register of PC is set to -1 (fixing resets with this register is a todo)
            if (current_arm7_registers.SysAndUser_registers.r15_PC == -1)
            {
                isRunning = false;
            }

        }
    }
}

// TODO: Dump to a separate file
// TODO: Put this in a debug section
void main_dumpOpcodes()
{
    int repeat_times = 1000000; // TODO: Find a way to get the total number of opcodes in a whole ROM
    int x = 0;
    repeat_times = repeat_times + 1; // Goes through repeat_times - 1 times if this is NOT present
    while (x != repeat_times)
    {
        LOG("Opcode with index %i: 0x%X",x, cpu_read_arm_opcode(x));
        x++;
        if (x == repeat_times)
        {
            return;
        }
    }
    return;
}
