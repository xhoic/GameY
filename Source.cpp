//Xhoi Caveli
#include <iostream>
#include <map>
#include <set>	

int main()
{
	int diceNum;
	std::map<int, int> diceRoll;
	std::set<int> roll;

	std::cout << "Enter 5 numbers in range 1 to 6." << std::endl;
	for (int i = 1; i <= 5; i++)
	{
		std::cout << i << ". ";
		std::cin >> diceNum;
		while (diceNum < 1 or diceNum >6)
		{
			std::cout << "Invalid enty! Reenter a number in range 1 to 6." << std::endl;
			std::cout << i << ". ";
			std::cin >> diceNum;
		}
		++diceRoll[diceNum];
	}

	for (const std::pair<int, int>& dice : diceRoll)
	{
		roll.insert(dice.first);
	}

	if (roll.size() == 1)
	{
		std::cout << "Congrats! You have YATHZEE!!!" << std::endl;
	}
	else if (roll.size() == 2)
	{
		std::map<int, int>::reverse_iterator riter = diceRoll.rbegin();
		if (diceRoll.begin()->second == 4 or riter->second == 4)
		{
			std::cout << "Congrats! You have 4 of a kind." << std::endl;
		}
		else
		{
			std::cout << "Congrats! You have a full house." << std::endl;
		}
	}
	else if (roll.size() == 3)
	{
		std::map<int, int>::iterator iter = diceRoll.begin();
		while (iter != diceRoll.end())
		{
			if (iter->second == 3)
			{
				std::cout << "Congrats! You have 3 of a kind!" << std::endl;
			}
			else if (iter->second == 2)
			{
				std::cout << "Oops! There is nothing!" << std::endl;
				break;
			}
			iter++;
		}
	}
	else if (roll.size() == 4)
	{
		bool flag = true;
		std::map<int, int>::iterator iter = diceRoll.begin();
		iter++;
		std::map<int, int>::iterator iter1 = diceRoll.begin();
		while (iter != diceRoll.end())
		{
			if (iter->first != iter1->first + 1)
			{
				flag = false;
			}
			iter++;
			iter1++;
		}
		if (flag == true)
		{
			std::cout << "Congrats! You have a small straight!" << std::endl;
		}
		else
		{
			std::cout << "Oops! There is nothing!" << std::endl;
		}
		
	}
	else
	{
		bool flag = true;
		std::map<int, int>::iterator iter = diceRoll.begin();
		iter++;
		std::map<int, int>::iterator iter1 = diceRoll.begin();
		while (iter != diceRoll.end())
		{
			if (iter->first != iter1->first + 1)
			{
				flag = false;
			}
			iter++;
			iter1++;
		}
		if (flag == true)
		{
			std::cout << "Congrats! You have a large straight!" << std::endl;
		}
		else
		{
			flag = true;
			iter = diceRoll.begin();
			iter++;
			iter1 = diceRoll.begin();
			for (int i = 0; i < 3; i++)
			{
				if (iter->first != iter1->first + 1)
				{
					flag = false;
				}
				iter++;
				iter1++;
			}
			if (flag == true)
			{
				std::cout << "Congrats! You have a small straight!" << std::endl;
			}
			else
			{
				std::cout << "Oops! There is nothing!" << std::endl;
			}

		}
		
	}
	system("PAUSE");
	return 0;
}