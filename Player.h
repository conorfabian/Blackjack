#pragma once
#include <iostream>
#include <vector>

#include "header/Cards.h"

using namespace std;

class Player
{
private:
	int points;

public:
	vector<Card> player_deck;
	Player();
	int GetPoints();
	string GetCard(int);
	void HitP(Card);
	void ace();
};