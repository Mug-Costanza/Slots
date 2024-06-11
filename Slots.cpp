#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctime>

int money = 25;
int amountbet;

void Init();
void Roll();
void Bet();

int AmountBet();
bool DoubleDown();
int RandomNumber();

int main()
{
	Init();

	return 0;
}

void Init()
{
	system("clear");

	if(money <= 0)
	{
		std::cout << "Game Over." << std::endl;
	}
	else
	{
	std::cout << "Your current balance: $" << money << std::endl;
	std::cout << "Roll or bet?" << std::endl;
	std::string response;
	std::cin >> response;
	
	if(response == "Roll" || response == "roll")
	{
		Roll();
	}
	else if(response == "Bet" || response == "bet")
	{
		Bet();
	}
	else
	{
		Init();
	}
	}
}

void Roll()
{
	int amountbet = AmountBet();

	system("clear");

	int firstNumber, secondNumber, thirdNumber;
	
	std::cout << "Roll three numbers. If the sum of the numbers is less than 15 you lose." << std::endl;
	std::cout << "If you roll a 0 at any point you lose." << std::endl;
	std::cout << "Press any key to continue..." << std::endl;
	system("read");
	system("clear");

	std::cout << "Press any key to roll." << std::endl;

	system("read");

	firstNumber = RandomNumber() - 1;

	std::cout << "You rolled a " << firstNumber << "." << std::endl;

	if(firstNumber == 0)
	{
		std::cout << "You lose." << std::endl;
		money -= amountbet;
		Init();
	}
	else
	{

	std::cout << "Press any key to roll." << std::endl;

	system("read");

	secondNumber = RandomNumber() - 1;

	int sum = firstNumber + secondNumber;

	std::cout << "You rolled a " << secondNumber << ". Sum : " << sum << "."  << std::endl;

	if(secondNumber == 0)
	{
		std::cout << "You lose." << std::endl;
		std::cout << "Press enter to continue..." << std::endl;
		system("read");
		money -= amountbet;
		Init();
	}
	else
	{
	if(sum < 10)
	{
		std::cout << "You lose." << std::endl;
		money -= amountbet;
		std::cout << "Press enter to continue..." << std::endl;
		system("read");
		Init();
	}
	else
	{

	if(DoubleDown())
	{
		amountbet *= 2;
	}

	std::cout << "Press any key to roll." << std::endl;

	system("read");

	thirdNumber = RandomNumber() -1;

	sum = firstNumber + secondNumber + thirdNumber;

	std::cout << "You rolled a " << thirdNumber << ". Sum : " << sum << "." << std::endl;

	if(thirdNumber == 0)
	{
		std::cout << "You lose." << std::endl;
		money -= amountbet;
		std::cout << "Press enter to continue..." << std::endl;
		system("read");
		Init();
	}
	else
	{
	if(sum < 20)
	{
		std::cout << "You lose." << std::endl;
		money -= amountbet;
		std::cout << "Press enter to continue..." << std::endl;
		system("read");
		Init();
	}
	else
	{
	int reward = (amountbet * ((sum - 14) / 3) * 0.5) / 5;
	
	money += reward;

	std::cout << "Reward : " << reward << std::endl;
	
	std::cout << "Press enter to continue..." << std::endl;

	system("read");

	Init();
	}}}}}
}

void Bet()
{
	int amountbet = AmountBet();
	
	int color;	
	std::string colorResponse;

	std::cout << "Black or Red?" << std::endl;
	std::cin >> colorResponse;

	if(colorResponse == "Black" || colorResponse == "black")
	{
		color = 1;
	}
	else if(colorResponse == "Red" || colorResponse == "red")
	{
		color = 2;
	}
	
	int number;
	std::string numberResponse;

	std::cout << "Choose a number between 1-10" << std::endl;
	std::cin >> number;

	int numberTwo;
	std::string numberTwoResponse;
	
	std::cout << "Choose another number between 1-10" << std::endl;
	std::cin >> numberTwo;
	
	srand(time(NULL));

	int numberResult;	

	numberResult = rand() % 10 + 1;
	
	srand(time(NULL));

	int colorResult = rand() % 2 + 1;

	std::string colorString;

	if(colorResult == 1)
	{
		colorString = "Black";
	}
	else
	{
		colorString = "Red";
	}

	std::cout << "Color : " << colorString << ", Number : " << numberResult << std::endl;

	int reward;

	if(color == colorResult)
	{
		reward += (amountbet / 3);
	}
	if(number == numberResult)
	{
		reward += (amountbet / 3);
	}
	if(numberTwo == numberResult)
	{
		reward += (amountbet / 3);
	}
	if(color != colorResult && number != numberResult && numberTwo != numberResult)
	{
		std::cout << "You lose." << std::endl;
		money -= amountbet;
		std::cout << "Press enter to continue..." << std::endl;
		system("read");
		Init();
	}
	else
	{
		money += reward;
		std::cout << "Reward : " << reward << "." << std::endl;
		std::cout << "Press enter to continue..." << std::endl;
		system("read");
		Init();
	}
}

int AmountBet()
{
	system("clear");

	int amountbet;

	std::cout << "How much will you bet?" << std::endl;
	std::cin >> amountbet;

	if(amountbet > money)
	{
		std::cout << "You do not have enough." << std::endl;
		std::cout << "Press enter to continue..." << std::endl;
		system("read");
		AmountBet();
	}	

	return amountbet;
}


bool DoubleDown()
{
	std::string response;	

	std::cout << "Double down? y/n" << std::endl;
	std::cin >> response;

	if(response == "y")
	{
		return true;
	}
	else if(response == "n")
	{
		return false;
	}
	else
	{
		DoubleDown();
	}
}

int RandomNumber()
{
	srand(time(NULL));	

	int result = rand() % 11 + 1;

	return result;	
}
