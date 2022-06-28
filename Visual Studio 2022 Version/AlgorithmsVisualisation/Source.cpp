#include "Sort.h"
#include <thread>

#define BLACK {0,0,0}
#define WHITE {255,255,255}
#define RED {255,0,0}
#define LIME {0,255,0}
#define BLUE {0,0,255}
#define ORANGE {255,127,80}
#define AQUA {0,255,255}
#define MAGENTA {255,0,255}
#define SILVER {192,192,192}
#define GRAY {100,100,100}
#define MAROON {128,0,0}
#define OLIVE {128,128,0}
#define GREEN {0,128,0}
#define PURPLE {128, 0, 128}
#define TEAL {0,128,128}
#define NAVY {0,0,128}

struct color {
    int r;
    int g;
    int b;
};

std::vector<color> colors = { BLACK, WHITE, RED, LIME, BLUE, ORANGE, AQUA, MAGENTA, SILVER, GRAY, MAROON, OLIVE, GREEN, PURPLE, TEAL, NAVY };

#define WIDTH 1000
#define HEIGHT 800
int button_option = 0;
bool quit = false;

//----------------------------------------------------------------------------------------------------------------------------------------------------//
void set_vec(std::vector<int>& vec) {
    for (int i = 0; i < 100; i++) {
        vec.push_back(rand() % 100 + 1);
    }
}

void INIT(SDL_Window*& window, SDL_Renderer*& render, std::vector<int>& vec) {
    srand(time(NULL));

    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("Sorting Algorithms Visualisation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 2);
    if (window == nullptr) { std::cout << "Cannot create window!" << std::endl; SDL_Quit();  exit(1); }

    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (render == nullptr) { std::cout << "Cannot create renderer" << std::endl; SDL_DestroyWindow(window); SDL_Quit();  exit(1); }

    set_vec(vec);
}

//Button_option=1 -> red Bubble
//Button_option=2 -> red Maximum
//Button_option=3 -> red Minimum
//Button_option=4 -> red Insertion
//Button_option=5 -> red Merge
//Button_option=6 -> red Quick
//Button_option=7 -> red Heap
//Button_option=8 -> red Shell
void show_BubbleSort(SDL_Renderer*& render, SDL_Texture* buttons) {
    SDL_Rect button;
    SDL_Rect pos;
    //Bubble
    button_option != 1 ? button = { 0,0,100,25 } : button = { 100,0,100,25 };
    pos = { 0,0,196,48 };
    SDL_RenderCopy(render, buttons, &button, &pos);
}

void show_MaxSelectionSort(SDL_Renderer*& render, SDL_Texture* buttons) {
    SDL_Rect button;
    SDL_Rect pos;
    //Maximum
    button_option != 2 ? button = { 0,25,100,25 } : button = { 100,25,100,25 };
    pos = { 200,0,196,48 };
    SDL_RenderCopy(render, buttons, &button, &pos);
}

void show_MinSelectionSort(SDL_Renderer*& render, SDL_Texture* buttons) {
    SDL_Rect button;
    SDL_Rect pos;
    //Minimum
    button_option != 3 ? button = { 0,50,100,25 } : button = { 100,50,100,25 };
    pos = { 400,0,196,48 };
    SDL_RenderCopy(render, buttons, &button, &pos);
}

void show_InsertionSort(SDL_Renderer*& render, SDL_Texture* buttons) {
    SDL_Rect button;
    SDL_Rect pos;
    //Insertion
    button_option != 4 ? button = { 0,75,100,25 } : button = { 100,75,100,25 };
    pos = { 600,0,196,48 };
    SDL_RenderCopy(render, buttons, &button, &pos);
}

void show_MergeSort(SDL_Renderer*& render, SDL_Texture* buttons) {
    SDL_Rect button;
    SDL_Rect pos;
    //Merge
    button_option != 5 ? button = { 0,100,100,25 } : button = { 100,100,100,25 };
    pos = { 0,52,196,48 };
    SDL_RenderCopy(render, buttons, &button, &pos);
}

void show_QuickSort(SDL_Renderer*& render, SDL_Texture* buttons) {
    SDL_Rect button;
    SDL_Rect pos;
    //Quick
    button_option != 6 ? button = { 0,125,100,25 } : button = { 100,125,100,25 };
    pos = { 200,52,196,48 };
    SDL_RenderCopy(render, buttons, &button, &pos);
}

void show_HeapSort(SDL_Renderer*& render, SDL_Texture* buttons) {
    SDL_Rect button;
    SDL_Rect pos;
    //Heap
    button_option != 7 ? button = { 0,150,100,25 } : button = { 100,150,100,25 };
    pos = { 400,52,196,48 };
    SDL_RenderCopy(render, buttons, &button, &pos);
}

void show_ShellSort(SDL_Renderer*& render, SDL_Texture* buttons) {
    SDL_Rect button;
    SDL_Rect pos;
    //Shell
    button_option != 8 ? button = { 200,0,100,25 } : button = { 200,25,100,25 };
    pos = { 600,52,196,48 };
    SDL_RenderCopy(render, buttons, &button, &pos);
}

void show_ColorOptions(SDL_Renderer*& render, SDL_Texture* buttons, SDL_Texture* texts) {
    SDL_Rect button;
    SDL_Rect pos;

    //Background of Color settings
    button = { 200,50,100,50 };
    pos = { 800,0,200,100 };
    SDL_RenderCopy(render, buttons, &button, &pos);

    //Background text
    button = { 0,25,600,75 };
    pos = { 845,3,120,15 };
    SDL_RenderCopy(render, texts, &button, &pos);

    //Background text colors
    for (int i = 0; i < (int)colors.size(); i++) {
        SDL_SetRenderDrawColor(render, colors[i].r, colors[i].g, colors[i].b, 255);
        pos = { 845 + i % 8 * 15 , 20 + i / 8 * 15,10,10 };
        SDL_RenderFillRect(render, &pos);
    }

    //Data column color
    button = { 0,125,600,60 };
    pos = { 845,55,115,12 };
    SDL_RenderCopy(render, texts, &button, &pos);

    //Background text colors
    for (int i = 0; i < (int)colors.size(); i++) {
        SDL_SetRenderDrawColor(render, colors[i].r, colors[i].g, colors[i].b, 255);
        pos = { 845 + i % 8 * 15 , 70 + i / 8 * 15,10,10 };
        SDL_RenderFillRect(render, &pos);
    }
}

void show_buttons(SDL_Renderer*& render, SDL_Texture* buttons, SDL_Texture* texts) {
    show_BubbleSort(render, buttons);
    show_MaxSelectionSort(render, buttons);
    show_MinSelectionSort(render, buttons);
    show_InsertionSort(render, buttons);
    show_MergeSort(render, buttons);
    show_QuickSort(render, buttons);
    show_HeapSort(render, buttons);
    show_ShellSort(render, buttons);
    show_ColorOptions(render, buttons, texts);
}

void sorting_simulation(std::vector<int> vec, Sort* s) {
    while (!quit) {
        SDL_Delay(1);
        switch (button_option)
        {
        case 1:
            s->BubbleSort(vec);
            break;
        case 2:
            s->MaxSelectionSort(vec);
            break;
        case 3:
            s->MinSelectionSort(vec);
            break;
        case 4:
            s->InsertionSort(vec);
            break;
        case 5:
            s->MergeSort(vec);
            break;
        case 6:
            s->QuickSort(vec);
            break;
        case 7:
            s->HeapSort(vec);
            break;
        case 8:
            s->ShellSort(vec);
            break;
        case 9:
            return;
        default:
            while (button_option == 0) {
            
            }
        }
    }
}


int main(int argc, char* argv[]) {
    SDL_Window* window;
    SDL_Renderer* render;
    std::vector<int> vec;
    INIT(window, render, vec);
    Sort* s = new Sort(render, window);
    s->background = BLACK;
    s->data_column = RED;


    SDL_Texture* buttons = IMG_LoadTexture(render, "Buttons.png");
    SDL_Texture* texts = IMG_LoadTexture(render, "Text.png");
    show_buttons(render, buttons, texts);
    SDL_RenderPresent(render);

    std::thread th(sorting_simulation, vec, s);
    th.detach();
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            SDL_Delay(1);
            switch (event.type) {
            case SDL_QUIT:
                quit = true;
                button_option = 9; s->option = 9;
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;
                    //Bubble
                    if (button_option != 1 && x >= 0 && x <= 196 && y >= 0 && y <= 48) {
                        button_option = 1; s->option = 1;
                        show_buttons(render, buttons, texts);
                        SDL_RenderPresent(render);
                    }
                    //Maximum
                    else if (button_option != 2 && x >= 200 && x <= 396 && y >= 0 && y <= 48) {
                        button_option = 2; s->option = 2;
                        show_buttons(render, buttons, texts);
                        SDL_RenderPresent(render);
                    }
                    //Minimum
                    else if (button_option != 3 && x >= 400 && x <= 596 && y >= 0 && y <= 48) {
                        button_option = 3; s->option = 3;
                        show_buttons(render, buttons, texts);
                        SDL_RenderPresent(render);
                    }
                    //Insertion
                    else if (button_option != 4 && x >= 600 && x <= 796 && y >= 0 && y <= 48) {
                        button_option = 4; s->option = 4;
                        show_buttons(render, buttons, texts);
                        SDL_RenderPresent(render);
                    }
                    //Merge
                    else if (button_option != 5 && x >= 0 && x <= 196 && y >= 50 && y <= 98) {
                        button_option = 5; s->option = 5;
                        show_buttons(render, buttons, texts);
                        SDL_RenderPresent(render);
                    }
                    //Quick
                    else if (button_option != 6 && x >= 200 && x <= 396 && y >= 50 && y <= 98) {
                        button_option = 6; s->option = 6;
                        show_buttons(render, buttons, texts);
                        SDL_RenderPresent(render);
                    }
                    //Heap
                    else if (button_option != 7 && x >= 400 && x <= 596 && y >= 50 && y <= 98) {
                        button_option = 7; s->option = 7;
                        show_buttons(render, buttons, texts);
                        SDL_RenderPresent(render);
                    }
                    //Shell
                    else if (button_option != 8 && x >= 600 && x <= 796 && y >= 50 && y <= 98) {
                        button_option = 8; s->option = 8;
                        show_buttons(render, buttons, texts);
                        SDL_RenderPresent(render);
                    }
                    //Change background color
                    if (x >= 845 && x <= 960 && y >= 20 && y <= 45) {
                        bool l = false;
                        int c;
                        for (int i = 0; i < (int)colors.size() && !l; i++) {
                            int x = 845 + i % 8 * 15;
                            int y = 20 + i / 8 * 15;
                            l = l || (event.button.x >= x && event.button.x <= x + 10 && event.button.y >= y && event.button.y <= y + 10);
                            c = i;
                        }
                        if (l) {
                            s->color_has_changed = true;
                            s->background = { colors[c].r,colors[c].g ,colors[c].b };
                        }
                    }
                    //Change data column color
                    if (x >= 845 && x <= 960 && y >= 70 && y <= 95) {
                        bool l = false;
                        int c;
                        for (int i = 0; i < (int)colors.size() && !l; i++) {
                            int x = 845 + i % 8 * 15;
                            int y = 70 + i / 8 * 15;
                            l = l || (event.button.x >= x && event.button.x <= x + 10 && event.button.y >= y && event.button.y <= y + 10);
                            c = i;
                        }
                        if (l) {
                            s->color_has_changed = true;
                            s->data_column = { colors[c].r,colors[c].g ,colors[c].b };
                        }
                    }
                }
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    SDL_DestroyTexture(buttons);
    SDL_DestroyTexture(texts);
    SDL_Quit();
    return 0;
}