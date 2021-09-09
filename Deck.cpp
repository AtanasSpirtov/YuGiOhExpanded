#include "Deck.h"
#include <iostream>
Deck::Deck()
{
	deckName = "";
}
Deck::Deck(string name)
{
	deckName = name;
}
void Deck::setDeckname(string newName)
{
	deckName = newName;
}
//Deck::~Deck()
//{
//	for (int i = 0; i < allCards.size(); i++)
//	{
//		delete allCards[i];
//	}
//}
//We dont need destructor because the vector AllCards[i] manages the storage alone
Deck Deck::operator=(const Deck& newDeck)
{
	for (int i = 0; i < allCards.size(); i++)
	{
		this->allCards[i] = newDeck.allCards[i];
	}
	return *this;
}
Card* Deck::returnCard(int index)
{
	return allCards[index];
}
int Deck::returnMonsterCardsCount()
{
	int monsterCardsCounter = 0;
	for (int i = 0; i < allCards.size(); i++)
	{
		if (MonsterCard* mag = dynamic_cast<MonsterCard*>(allCards[i]))
		{
			if (PendulumCard* pend = dynamic_cast<PendulumCard*>(allCards[i]))
			{
			}
			else monsterCardsCounter++;
		}
	}
	return monsterCardsCounter;
}

int Deck::returnMagicCardsCount()
{
	int magicCardsCounter = 0;
	for (int i = 0; i < allCards.size(); i++)
	{
		if (MagicCard* mag = dynamic_cast<MagicCard*>(allCards[i]))
		{
			if (PendulumCard* pend = dynamic_cast<PendulumCard*>(allCards[i]))
			{
			}
			else magicCardsCounter++;
		}
	}
	return magicCardsCounter;
}

int Deck::returnPendulumCardsCount()
{
	int pendulumCardsCounter = 0;
	for (int i = 0; i < allCards.size(); i++)
	{
		if (PendulumCard* pend = dynamic_cast<PendulumCard*>(allCards[i]))
		{
			pendulumCardsCounter++;
		}
	}
	return pendulumCardsCounter;
}

int Deck::returnAllCardsCount()
{
	return allCards.size();
}

string Deck::TypeToString(CardType convertedType)
{
	if (convertedType == CardType::BUFF)
	{
		return "BUFF";
	}
	else if (convertedType == CardType::SPELL)
	{
		return "SPELL";
	}
	else
	{
		return "TRAP";
	}
}

void Deck::addCard(Card* newCard)
{
	allCards.push_back(newCard);
}
void Deck::addCard(PendulumCard* newCard)
{
	allCards.push_back(dynamic_cast<MonsterCard*>(newCard));
}

void Deck::setCard(unsigned int position, Card* setCard)
{
	if (position > allCards.size())
	{
		cout << "no card at this position";
	}
	else {
		allCards[position] = setCard;
	}
}
void Deck::setCard(unsigned int position, PendulumCard* setCard)
{
	if (position > allCards.size())
	{
		cout << "no card at this position";
	}
	else {
		allCards[position] = dynamic_cast<MonsterCard*>(setCard);
	}
}

void Deck::shuffle()
{
	for (int i = 0; i < allCards.size(); i++)
	{
		int randomPosition = rand() % allCards.size();
		Card* temp = allCards[i];
		allCards[i] = allCards[randomPosition];
		allCards[randomPosition] = temp;
	}
}

void Deck::deleteDeck()
{
	for (int i = 0; i < allCards.size(); i++)
	{
		allCards[i] = nullptr;
	}
}
