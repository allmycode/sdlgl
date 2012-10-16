#ifndef _SDLAPP_H
#define _SDLAPP_H

#include <SDL.h>

class SDLApp {
 private:
  bool Running;  
  SDL_Surface* Surface;

 public:
  SDLApp();
  bool OnInit();
  int OnExecute();
  void OnCleanup();

  void OnEvent(SDL_Event* event);

};


#endif 
