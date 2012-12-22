#include <nds.h>
#include <fat.h>
#include <stdio.h>

#include "intro.h"
#include "ds_tools.h"

int main(int argc, char **argv) {
  // Init sound
  consoleDemoInit();
  soundEnable();
  lcdMainOnTop();

  // Init Fat
	if (!fatInitDefault()) {
		iprintf("Unable to initialize libfat!\n");
		return -1;
	}

  // Init Timer
	dsInitTimer();
  dsInstallSoundEmuFIFO();

  // Intro and main screen
  intro_logo();
  dsInitScreenMain();
  etatEmu = STELLADS_MENUINIT;
  
  //load rom file via args if a rom path is supplied
  if(argc > 1) {
    dsShowScreenMain();
    dsLoadGame(argv[1]);
    etatEmu = STELLADS_PLAYINIT;
  }

  // Main loop of emulation
  dsMainLoop();
  	
  // Free memory to be correct 
  dsFreeEmu();
 
	return 0;
}

