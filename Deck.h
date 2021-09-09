#pragma once
#include <iostream>
#include <vector>
#include "MonsterCard.h"
#include "MagicCard.h"
#include "PendulumCard.h"
using namespace std;
class Deck
{
private:
	string deckName;
	vector<Card*> allCards;
public:
	Deck();
	Deck(string name);
	//~Deck();
	void setDeckname(string newName);
	Deck operator=(const Deck& newDeck);
	Card* returnCard(int index);
	int returnMonsterCardsCount();
	int returnMagicCardsCount();
	int returnPendulumCardsCount();
	int returnAllCardsCount();
	string TypeToString(CardType convertedType);
	void addCard(Card* newCard);
	void addCard(PendulumCard* newCard);
	void setCard(unsigned int position, Card* setCard);
	void setCard(unsigned int position, PendulumCard* setCard);
	void shuffle();
	void deleteDeck();
};