#include "SDL_rect.h"
#include "SDL_surface.h"
#include "SDL_video.h"
#include<stdio.h>
#include<stdlib.h>
#include<SDL.h>

int main(){
    FILE *in = stdin;
    char *s = calloc(1000 , sizeof(char));
    char *dim = calloc(1000, sizeof(char));
    int width = -1;
    int height = -1;

    fgets(s , 1000 ,in);
    fgets(dim , 1000 , in);
    sscanf(dim, "%d %d\n", &width , &height);
    fgets(s , 1000 ,in);
    free(s);
    free(dim);

    SDL_Window *pwind = SDL_CreateWindow("image-viewer",
                                        SDL_WINDOWPOS_CENTERED ,
                                        SDL_WINDOWPOS_CENTERED ,
                                        width , height ,0);

    SDL_Surface *psurface = SDL_GetWindowSurface(pwind);


    SDL_Rect pixel = (SDL_Rect){0,0,1,1};

    for(int y=0 ; y<height ; y++){
        for(int x=0 ; x<width ; x++){
            Uint32 color = SDL_MapRGB(psurface->format, (char)getchar(), (char)getchar(), (char)getchar());
            pixel.x=x;
            pixel.y=y;
            SDL_FillRect(psurface, &pixel, color);
        }
    }

    SDL_UpdateWindowSurface(pwind);


    SDL_Event e;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                running = 0;
        }
    }

    printf("Hello World\n");
}
