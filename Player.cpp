#include <iostream>
#include <vector>

#include "../header/Player.h"
#include "../header/Cards.h"

using namespace std;

Player::Player()
{
	player_deck = {};
	points = 0;
}

int Player::GetPoints()
{
	int points = 0;

	for (int i = 0; i < player_deck.size(); ++i)
	{
		points += player_deck.at(i).points;
	}

	return points;
}

string Player::GetCard(int i)
{
	return player_deck.at(i).value;
}

void Player::HitP(Card x)
{
	player_deck.push_back(x);
}

void Player::ace()
{
	for (int i = 0; i < player_deck.size(); ++i)
	{
		if (player_deck.at(i).value == "A")
		{
			player_deck.at(i).points = 11;
		}
	}
}