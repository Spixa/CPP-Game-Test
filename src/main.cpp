#include "Game.h"
#define VERSION "0.1.0 Beta"

/*	Dungeons And Dragons  		-- Name not officail yet
 *
 * Version ("Maj.Min.Bui Prototype") : 0.1.0 Beta
 * License: {license_name}
 *
 *
 *					Untitled Topdown 2d game v0.1.0 Beta
 *		============================================================================
 *		Xasetho Incorporated Software Product			XISP
 *		
 *		All Xasetho projects are open-source and legally can be accessed but cannot
 *		be distributed.       Licensed under {license_name}
 *		============================================================================
 *								
 * */


int main(int argc,char** argv) {
	--argc;
	if (argc < 1) {
	Game engine;
	engine.run();
	return engine.exitLog;
	} else{
		std::string text = argv[1];
		if (text == "debug") {
			std::cout << "Debug mode hasn't been fetched yet.\n";

		} else 
		if (text == "inf") {
			std::cout << "Made by Xasetho Incorporated.\n\t* Developers: https://github.com/phnixir, https://github.com/Spixa\n\t*GitHub: https://github.com/Spixa/CPP-Game-Test/\n";

		} else
		if (text == "version" or text == "ver") {
			std::cout << "Version is " << VERSION << std::endl;
		} else 	
		if (text == "help" or text == "h") {
			
			std::cout << "Available commandline arguments:\n\tdebug\tinf\n\tversion/ver\t\thelp/h\n";
	

		} else 
		{
			std::cout << "Commandline argument was not recognized.\n";

		}	
	}

	return 0;
}


