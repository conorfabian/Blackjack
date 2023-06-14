#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Card
{
public:
	string value;
	int points;
	bool x;
	Card(string, int);
};

class Deck
{
private:
	vector<Card> deck;

public:
	Deck();
	Card HitD();


	// For testing
	void Print();
};