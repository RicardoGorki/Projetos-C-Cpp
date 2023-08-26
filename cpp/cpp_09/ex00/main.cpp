#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::vector<std::string> data;
		std::ifstream fileInput(argv[1]);
		std::ifstream fileData("data.csv");
		if (!fileInput.is_open() || !fileData.is_open())
		{
			std::cout << "Error: could not open file." << std::endl;
			return 1;
		}
		//data.csv carregando o vetor
		std::string lineData;
		std::getline(fileData, lineData);
		while (std::getline(fileData, lineData))
		{
			data.push_back(lineData);
		};

		// input
		std::string line;
		std::getline(fileInput, line);
		while (std::getline(fileInput, line))
		{
			if (verifyFormat(line))
				checkStructure(line, data);
		};
		fileData.close();
		fileInput.close();
	}
	else
		std::cout << "Error: could not open file." << std::endl;
	return 0;
}
