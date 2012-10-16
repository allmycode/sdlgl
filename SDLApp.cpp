#include "SDLApp.h"

SDLApp::SDLApp(): Running(true) {
}


bool SDLApp::OnInit() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return false;
  if ((Surface = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    return false;

  return true;
  
}

int SDLApp::OnExecute() {
  if (!OnInit())
    return -1;

  SDL_Event Event;
 
  while(Running) {
    while(SDL_PollEvent(&Event)) {
      OnEvent(&Event);
    }
    
    //OnLoop();
    //OnRender();
  }
 
  OnCleanup();
 
  return 0;
}

void SDLApp::OnCleanup() {
  SDL_Quit();
}

void SDLApp::OnEvent(SDL_Event* event) {
  if(event->type == SDL_QUIT) {
    Running = false;
  }
}

int main(int argc, const char* argv[]) {
  SDLApp app;
  return app.OnExecute();
}
