#include <iostream>
#include <string>
#include <vector>
#include "WADMap.h"

int main(int argc, char** args)
{
	// Create a WADMap instance
	WADMap *wad = new WADMap;

	// Load the filepath passed as argument 1
	wad->loadFile(std::string(args[1]));

	// Make sure maps were found
	if( wad->mapCount() )
	{
		// Get the found maps
		std::vector<std::string> maps = wad->getMaps();

		// List all found map names
		for (auto map : maps)
		{
			std::cout << map << " ";
		}
		std::cout << "\n";

		return 0;
	} else {
		return 1;
	}
}
