#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


struct Stock
{
	char name[30];
	float price = 0;
	float quantity = 0;
	float markup_percentage = 0;
}stck;


FILE* f;
int choice = 0;


int menu();
void createFile();
void printFile();
void addToFile();
void findInFile();


int main()
{
	menu();


	return 0;
}


int menu()
{
	while (true)
	{
		int choice = 0;
		std::cout << std::endl << "Menu: " << std::endl;
		std::cout << "1) Create file" << std::endl;
		std::cout << "2) Add to file" << std::endl;
		std::cout << "3) Output" << std::endl;
		std::cout << "4) Search by criteria" << std::endl;
		std::cout << "69) Exit" << std::endl;
		std::cout << "_________________________________" << std::endl << std::endl;
		bool IsIncorrect;
		do {
			IsIncorrect = false;
			std::cout << "Your choice: ";
			std::cin >> choice;
			if (std::cin.fail())
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				IsIncorrect = true;
				std::cout << "TYPR ERR" << std::endl;
			}
			if (!IsIncorrect && std::cin.get() != '\n')
			{
				std::cin.clear();
				while (std::cin.get() != '\n');

				std::cout << "Err" << std::endl;
				IsIncorrect = true;
			}
			if (!IsIncorrect && (choice < 1 || (choice > 5 && choice != 69)))
			{
				IsIncorrect = true;
				std::cout << "RANGE ERR" << std::endl;
			}
		} while (IsIncorrect);
		

		if (choice == 1)
		{
			createFile();
		}
		if (choice == 2)
		{
			addToFile();
		}
		if (choice == 3)
		{
			printFile();
		}
		if (choice == 4)
		{
			findInFile();
		}
		if (choice == 69)
		{
			std::cout << "Exit, have a nice day :3";
			return 0;
		}
	}

	return 1;
}


void createFile()
{
	if (!(f = fopen("inf.dat", "r")))
	{
		if (!(f = fopen("inf.dat", "w+")))
		{
			std::cout << "Error file creating!" << std::endl;
			return;
		}
		std::cout << "File was created successfully" << std::endl;
		fclose(f);
	}
	else
	{
		std::cout << "File already exists" << std::endl;
		fclose(f);
	}
}


void printFile()
{
	if (!(f = fopen("inf.dat", "r")))
	{
		std::cout << "File does't exist" << std::endl;;
		return;
	}
	int counter = 0;
	while (true)
	{
		if (fread(&stck, sizeof(stck), 1, f))
		{
			std::cout << "__________________________________" << std::endl;
			std::cout << "Product name: " << stck.name << std::endl;
			std::cout << "Product price: " << stck.price << std::endl;
			std::cout << "Product quantity: " << stck.quantity << std::endl;
			std::cout << "Product markup percentage: " << stck.markup_percentage << std::endl;
			counter++;
		}
		else
		{
			if (counter == 0)
			{
				std::cout << "No recordings";
			}
			break;
		}
	}
}


void addToFile()
{
	if (!(f = fopen("inf.dat", "r")))
	{
		std::cout << "File doesn't exist" << std::endl;
		return;
	}
	fclose(f);
	f = fopen("inf.dat", "a");


	while (true)
	{
		std::cout << std::endl << "Enter product name (if you want to exit enter '0'): ";
		rewind(stdin);
		gets_s(stck.name);
		if (stck.name[0] == '0')
		{
			std::cout << std::endl << "Breaking changings...." << std::endl;
			break;
		}
		rewind(stdin);


		std::cout << "Enter product price: ";
		bool IsIncorrect;
		do {
			IsIncorrect = false;
			std::cin >> stck.price;
			if (std::cin.fail())
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				IsIncorrect = true;
				std::cout << "TYPR ERR" << std::endl;
			}
			if (!IsIncorrect && std::cin.get() != '\n')
			{
				std::cin.clear();
				while (std::cin.get() != '\n');

				std::cout << "Err" << std::endl;
				IsIncorrect = true;
			}
			if (!IsIncorrect && stck.price < 0)
			{
				IsIncorrect = true;
				std::cout << "RANGE ERR" << std::endl;
			}
		} while (IsIncorrect);


		std::cout << std::endl << "Enter product quantity: ";
		bool IsIncorrect1;
		do {
			IsIncorrect1 = false;
			std::cin >> stck.quantity;
			if (std::cin.fail())
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				IsIncorrect1 = true;
				std::cout << "TYPR ERR" << std::endl;
			}
			if (!IsIncorrect1 && std::cin.get() != '\n')
			{
				std::cin.clear();
				while (std::cin.get() != '\n');

				std::cout << "Err" << std::endl;
				IsIncorrect1 = true;
			}
			if (!IsIncorrect1 && stck.quantity < 0)
			{
				IsIncorrect1 = true;
				std::cout << "RANGE ERR" << std::endl;
			}
		} while (IsIncorrect1);


		std::cout << std::endl << "Enter product murkup percentage: ";
		bool IsIncorrect2;
		do {
			IsIncorrect2 = false;
			std::cin >> stck.markup_percentage;
			if (std::cin.fail())
			{
				std::cin.clear();
				while (std::cin.get() != '\n');
				IsIncorrect2 = true;
				std::cout << "TYPR ERR" << std::endl;
			}
		} while (IsIncorrect2);


		fwrite(&stck, sizeof(stck), 1, f);
	}
	fclose(f);


}


void findInFile()
{
	if (!(f = fopen("inf.dat", "r")))
	{
		std::cout << "File doesn't exist!" << std::endl;
		return;
	}
	
	if (check == 0)
	{
		std::cout << "__________________________________" << std::endl;
		std::cout << "Product name: " << stck.name << std::endl;
		std::cout << "Product price: " << stck.price << std::endl;
		std::cout << "Product quantity: " << stck.quantity << std::endl;
		std::cout << "Product markup percentage: " << stck.markup_percentage << std::endl;
	}
	else
	{
		std::cout << "Such recording doesn't exists" << std::endl;
		fclose(f);
	}
}