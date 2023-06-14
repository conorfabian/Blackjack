#include <iostream>

#include "../header/Cards.h"
#include "../header/Player.h"

using namespace std;

int player_wins = 0;
int dealer_wins = 0;

void printCards(Player, Player);
void playerChoices(Player&, Player, Deck&);
void dealerChoices(Player&, Deck&);

int main()
{
	cout << "\tWELCOME TO BLACKJACK BUILT BY CONOR FABIAN!" << endl;
	cout << endl;

	//Intro menu
	char c = 'a';
	while (c != 'x' && c != 'q')
	{
		cout << "Press x to continue or q to quit: ";
		cin >> c;
	}
	cout << endl;

	//Game
	while (c == 'x')
	{
		//Declaring new deck and players
		Deck deck = Deck();
		Player player = Player();
		Player dealer = Player();

		//Other variables
		bool player_won = false;
		bool dealer_won = false;
		bool tie = false;

		//Setting up game
		for (int i = 0; i < 2; ++i)
		{
			player.HitP(deck.HitD());
		}

		dealer.HitP(deck.HitD());
		dealer.player_deck.push_back(Card("?", 0));

		printCards(dealer, player);

		//Player's actions
		playerChoices(player, dealer, deck);
		if (player.GetPoints() > 21)
		{
			dealer_won = true;
		}

		//Dealer's actions
		if (!dealer_won)
		{
			dealerChoices(dealer, deck);
			printCards(dealer, player);
			if (dealer.GetPoints() > 21)
			{
				player_won = true;
			}
		}


		//Finding winner
		if (!player_won && !dealer_won)
		{
			if (player.GetPoints() > dealer.GetPoints())
			{
				player_won = true;
			}
			else if (player.GetPoints() < dealer.GetPoints())
			{
				dealer_won = true;
			}
			else
			{
				tie = true;
			}
		}

		//Display + effects of winner
		if (player_won)
		{
			cout << "You win!" << endl << endl;
			++player_wins;
		}
		else if (dealer_won)
		{
			cout << "Dealer wins!" << endl << endl;
			++dealer_wins;
		}
		else if (tie)
		{
			cout << "Tie!" << endl << endl;
		}
		else
		{
			cout << "Something went wrong with displaying winner!" << endl;
		}

		cout << "Dealer wins: " << dealer_wins << endl;
		cout << "Your wins: " << player_wins << endl << endl;

		//Asking player if they want to play again
		c = 'a';
		while (c != 'x' && c != 'q')
		{
			cout << "Press x to continue or q to quit: ";
			cin >> c;
		}
		cout << endl;
	}

	return 0;
}

void printCards(Player dealer, Player player)
{
	bool hidden = false;

	cout << "---------- Cards ----------" << endl;
	cout << endl;
	cout << "Dealer's cards: ";
	for (int i = 0; i < dealer.player_deck.size(); ++i)
	{
		cout << dealer.player_deck.at(i).value << " ";
		if (dealer.player_deck.at(i).value == "?")
		{
			hidden = true;
		}
	}
	cout << endl;
	if (hidden)
	{
		cout << "Points: ?";
	}
	else
	{
		cout << "Points: " << dealer.GetPoints();
	}
	cout << endl << endl;

	cout << "Your Cards: ";
	for (int i = 0; i < player.player_deck.size(); ++i)
	{
		cout << player.player_deck.at(i).value << " ";
	}
	cout << endl;
	cout << "Points: " << player.GetPoints();
	cout << endl << endl;

	cout << "---------------------------" << endl;
	cout << endl;
}

void playerChoices(Player & player,Player dealer, Deck & deck)
{
	char a = ' ';
	while (a != 's' && player.GetPoints() <= 21)
	{
		bool ace = false;
		int j;
		a = ' ';

		while (a != 's' && a != 'h' && a != 'a')
		{
			cout << "Player choices:" << endl;
			cout << "s) Stay" << endl;
			cout << "h) Hit" << endl;
			for (int i = 0; i < player.player_deck.size(); ++i)
			{
				if (player.player_deck.at(i).value == "A")
				{
					ace = true;
					j = i;
				}
			}

			if (ace)
			{
				cout << "a) Change Ace" << endl;
			}

			cin >> a;
			cout << endl;
		}

		if (a == 'h')
		{
			player.HitP(deck.HitD());
		}
		else if (a == 'a' && ace)
		{
			if (player.player_deck.at(j).points == 1)
			{
				player.player_deck.at(j).points = 11;
			}
			else
			{
				player.player_deck.at(j).points = 1;
			}
		}

		if (a != 's')
		{
			printCards(dealer, player);
		}
	}
	return;
}

void dealerChoices(Player& dealer, Deck& deck)
{
	//Replace ? with a second card
	dealer.player_deck.pop_back();
	dealer.HitP(deck.HitD());

	//Checking for ace
	int x;
	bool ace = false;
	for (int i = 0; i < dealer.player_deck.size(); ++i)
	{
		if (dealer.player_deck.at(i).value == "A")
		{
			x = i;
			ace = true;
		}
	}
	//If there is an ace, change points
	if (ace)
	{
		dealer.player_deck.at(x).points = 11;
	}

	//Hitting until points are greater than 17
	while (dealer.GetPoints() < 17)
	{
		dealer.HitP(deck.HitD());
	}
	return;
}