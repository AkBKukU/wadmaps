#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class WADMap 
{
	public:
		WADMap();

		void loadFile(std::string filepath);

		size_t mapCount();

		std::vector<std::string> getMaps();

		const int DOOM_START_INDEX = 0;
		const int DOOM2_START_INDEX = 36;

		std::vector<std::string> foundMaps;
		const std::vector<std::string> maps = 
		{
			"E1M1",
			"E1M2",
			"E1M3",
			"E1M4",
			"E1M5",
			"E1M6",
			"E1M7",
			"E1M8",
			"E1M9",
			"E2M1",
			"E2M2",
			"E2M3",
			"E2M4",
			"E2M5",
			"E2M6",
			"E2M7",
			"E2M8",
			"E2M9",
			"E3M1",
			"E3M2",
			"E3M3",
			"E3M4",
			"E3M5",
			"E3M6",
			"E3M7",
			"E3M8",
			"E3M9",
			"E4M1",
			"E4M2",
			"E4M3",
			"E4M4",
			"E4M5",
			"E4M6",
			"E4M7",
			"E4M8",
			"E4M9",
			"MAP01",
			"MAP02",
			"MAP03",
			"MAP04",
			"MAP05",
			"MAP06",
			"MAP07",
			"MAP08",
			"MAP09",
			"MAP10",
			"MAP11",
			"MAP12",
			"MAP13",
			"MAP14",
			"MAP15",
			"MAP16",
			"MAP17",
			"MAP18",
			"MAP19",
			"MAP20",
			"MAP21",
			"MAP22",
			"MAP23",
			"MAP24",
			"MAP25",
			"MAP26",
			"MAP27",
			"MAP28",
			"MAP29",
			"MAP30",
			"MAP31",
			"MAP32"
		};
	private:

		std::string fileData;

		bool parseFile();


};
