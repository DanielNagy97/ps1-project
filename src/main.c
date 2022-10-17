/*
===========================================================
            Sony PlayStation 1 Example program
===========================================================
                         FONT EXAMPLE
Displays text on the screen using the built in GPU routines
-----------------------------------------------------------

    Developer / Programmer..............: Daniel Nagy
    Software Ddevelopment Kit...........: PSY-Q
    Last Release........................: 17/OCTOBER/2022

    Original code by SCEI and PSXDEV.net
    
	NOTE: This example uses double buffering!
-----------------------------------------------------------*/
#include <stdlib.h>
#include <display.h>


int main() 
{
	init_graphics();
	FntLoad(960, 256); // load the font from the BIOS into VRAM/SGRAM
	SetDumpFnt(FntOpen(5, 20, 320, 240, 0, 512)); // screen X,Y | max text length X,Y | automatic background clear 0,1 | max characters

	while (1)
	{
		FntPrint("Hello world!\n\n:-)");
		display();
	}

	return 0;
}
