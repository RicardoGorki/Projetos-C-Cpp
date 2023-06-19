#include "main.hpp"


std::string check_word(const std::string line, const std::string s1, const std::string s2)
{
	std::string	new_line;
	size_t		i;

	i = 0;
	while (i < line.length())
	{
		size_t found = line.find(s1, i);
		if (found == std::string::npos)
		{
			new_line += line.substr(i);
			break;
		}
		else
		{
			new_line += line.substr(i, found - i) + s2;
			i = found + s1.length();
		}
	}
	return new_line;
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream	file(argv[1]);
		std::string		name;
		std::string		s1;
		std::string		s2;
		std::string		line;
		std::string		new_file;

		name = argv[1];
		s1 = argv[2];
		s2 = argv[3];
		if (!file)
		{
			std::cout << "File doesn't exist" << std::endl;
			return (0);
		}
		if (!s1.length())
		{
			std::cout << "You must change something" << std::endl;
			return (0);
		}
		std::ofstream replaceFile(( name + ".replace").c_str());
		while(std::getline(file, line))
		{
			new_file = check_word(line, s1, s2);
			replaceFile << new_file << std::endl;
			std::cout << new_file << std::endl;
		}
		replaceFile.close();
		file.close();
	}
	else
	{
		std::cout << "Only three arguments: filename ";
		std::cout << "s1 (word need replace) to s2" << std::endl;
	}
	return (0);
}
