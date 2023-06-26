#include <iostream>

int main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc > 1)
	{
		while(i < argc)
		{
			j = 0;
			while (argv[i][j])
			{
				if(islower(argv[i][j]))
					argv[i][j] -= 32;
				std::cout << argv[i][j++];
			}
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
