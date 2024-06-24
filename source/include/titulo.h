#ifndef TITULO_H
#define TITULO_H

#include <stdio.h>
#include <windows.h>


void titulo(){


  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
  WORD saved_attributes;
  
   GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
   saved_attributes = consoleInfo.wAttributes;
  
  SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
printf("##   ##  #######   #####     ###        ###    ##   ##   # #####  #####      #####    ######  ##   ##   #####    #####  \n");
printf("### ###   ##   #  ##   ##   ## ##      ## ##   ##   ##  ## ## ## ### ###      ## ##     ##    ###  ##  ### ###  ##   ## \n");
printf("#######   ##      ##       ##   ##    ##   ##  ##   ##     ##    ##   ##      ##  ##    ##    #### ##  ##   ##  ##      \n");
printf("## # ##   ####    ## ####  ##   ##    ##   ##  ##   ##     ##    ##   ##      ##  ##    ##    #######  ##   ##   #####  \n");
printf("##   ##   ##      ##   ##  #######    #######  ##   ##     ##    ##   ##      ##  ##    ##    ## ####  ##   ##       ## \n");
printf("##   ##   ##   #  ##   ##  ##   ##    ##   ##  ##   ##     ##    ### ###      ## ##     ##    ##  ###  ### ###  ##   ## \n");
printf("### ###  #######   #####   ##   ##    ##   ##   #####     ####    #####      #####    ######  ##   ##   #####    #####  \n");

SetConsoleTextAttribute(hConsole, saved_attributes);


}



#endif
	
	
	
	
	
	
	
