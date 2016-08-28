#include "WADMap.h"

/*
 * Constructor to define the file data value.
 */
WADMap::WADMap()
{
	fileData = "no file";
}

/*
 * Load file data into string 
 */
void WADMap::loadFile( std::string filepath )
{

	// Define Buffer to hold file data
	std::streampos size;
	char * inputBuffer;
	int fileSize = 0;

	// Load the file in binary mode
	const char* filename = filepath.c_str();
	std::ifstream file (filename, std::ios::in|std::ios::binary|std::ios::ate);
	if (file.is_open())
	{
		// Initilize buffer to hold data
		size = file.tellg();
		fileSize = size;
		inputBuffer = new char [size];

		// Read data into buffer
		file.seekg (0, std::ios::beg);
		file.read (inputBuffer, size);

		int curloc = file.tellg();
		// Done with file
		file.close();
		
		// Initialize fileData member with new data
		fileData = std::string(inputBuffer, size);

		// Clear input buffer
		delete[] inputBuffer;

		// Parse the file
		this->parseFile();
	}
	else std::cout << "Unable to open file: " << filepath;

}

bool WADMap::parseFile()
{
	// Start map index at E1M1
	size_t mapIndex = WADMap::DOOM_START_INDEX;
	bool isDoom1 = false; // Use to skip checking for doom 2 maps

	// Check for doom 1 first map
	if ( fileData.find(WADMap::maps[WADMap::DOOM_START_INDEX]) != std::string::npos )
	{
		// Put map into found list
		foundMaps.push_back(WADMap::maps[WADMap::DOOM_START_INDEX]);

		// Mark wad as a doom 1 wad
		isDoom1 = true;

		// Move to look for E1M2
		mapIndex++;
	}

	// Check for doom 2 first map
	if ( 
		!isDoom1 &&  
		fileData.find(WADMap::maps[WADMap::DOOM2_START_INDEX]) != std::string::npos )
	{
		// Put map into found list
		foundMaps.push_back(WADMap::maps[WADMap::DOOM2_START_INDEX]);
		
		// Move to look for MAP02
		mapIndex = WADMap::DOOM2_START_INDEX + 1;
	}

	// Go through standard map names and search for them.
	for (; mapIndex < WADMap::maps.size();mapIndex++)
	{
		// Exit if wad is for doom 1 and have tested all levels
		if ( isDoom1 && mapIndex > WADMap::DOOM2_START_INDEX ) 
		{
			break;
		}
		
		// Look for next level in wad
		if ( fileData.find(WADMap::maps[mapIndex]) != std::string::npos )
		{
			foundMaps.push_back(WADMap::maps[mapIndex]);
		}
	}	
}

/*
 * Return the number of found levels
 */
size_t WADMap::mapCount()
{
	return foundMaps.size();
}

/*
 * Return the names of the found levels
 */
std::vector<std::string> WADMap::getMaps()
{
	return foundMaps;
}
