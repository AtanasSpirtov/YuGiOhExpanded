#pragma once
#include "Deck.h"
#include <fstream>
enum class Duel
{
	Player1Wins,
	Player2Wins,
	Draw,
	CannotStartDuel
};
class Duelist
{
private:
	string name;
	Deck duelistDeck;
public:
	Duelist();
	Duelist(string n);
	Duelist(string n, Deck d);
	~Duelist();
	Deck& getDeck();
	void setName(string newName);
	bool saveDeck(string file);
	bool loadDeck(string file);
	Duel duel(Duelist secondDuelist);
};
