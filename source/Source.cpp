#include "StemmerPorter.h"
#include "FileAnalyser.h"

#include <cstdio>
#include <windows.h>

#define HELP_USAGE "Usage: <stemmer.exe> <path to source file> <destination .csv file>"

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		std::cout << HELP_USAGE;
		return -1;
	}

	try {
		static_cast<void>(std::locale::global(std::locale("Russian_Russia")));


		ifstream file (argv[1]);
		FileAnalyser fileAnalyser;

		if (!file.is_open()) {
			throw std::runtime_error("Could not found the file");
		}

		textmap textmap = fileAnalyser.stemm(file);
		fileAnalyser.save(argv[1], argv[2], textmap);

		file.close();
	}
	catch (std::exception &ex) {
		std::cout << "Exception occured: " << ex.what() << std::endl;
		return -1;
	}

	std::cout << "Finished sucessfully" << std::endl;

	return 0;
}