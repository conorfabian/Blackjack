#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>


#include "../header/Cards.h"

using namespace std;

// Default Constructor
Card::Card(string a, int b)
{
	value = a;
	points = b;
	x = true;
}

// Default Constructor
Deck::Deck()
{
	for (int i = 1; i <= 13; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (i == 1)
			{
				deck.push_back(Card("A", 1));
			}
			else if (i == 10)
			{
				deck.push_back(Card("10", 10));
			}
			else if (i == 11)
			{
				deck.push_back(Card("J", 10));
			}
			else if (i == 12)
			{
				deck.push_back(Card("Q", 10));
			}
			else if (i == 13)
			{
				deck.push_back(Card("K", 10));
			}
			else
			{
				string c = to_string(i);
				deck.push_back(Card(c, i));
			}
		}
	}
}

void Deck::Print()
{
	for (int i = 0; i < deck.size(); ++i)
	{
		cout << deck.at(i).value << " ";
		cout << deck.at(i).points << endl;
	}
}

Card Deck::HitD()
{
	srand(time(NULL));

	while (true)
	{
		int y = rand() % 52;

		if (deck.at(y).x)
		{
			deck.at(y).x = false;
			return deck.at(y);
		}
	}
}