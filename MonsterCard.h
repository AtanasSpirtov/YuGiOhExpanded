#pragma once

#include <iostream>
#include "Card.h"

using namespace std;
class MonsterCard : public Card
{
private:
	 unsigned int atackingPoints; 
	 unsigned int defendingPoints;
public:
	MonsterCard();
	MonsterCard(unsigned int att, unsigned int def);
	MonsterCard(string n, string eff,unsigned int rar, unsigned int att, unsigned int def);
	MonsterCard operator=(const MonsterCard& newMonster);
	bool operator>(Card& secondCard);
	bool operator>(MonsterCard& secondCard);
	bool operator<(Card& secondCard);
	bool operator<(MonsterCard& secondCard);
	void setName(string n);
	void setEffect(string eff);
	void setRarity(unsigned int rar);
	void setAtackingPoints(unsigned int at);
	void setDefendingPoints(unsigned int def);
	string getName();
	string getEffect();
	unsigned int getRarity();
	unsigned int getAtackingPoints() const;
	unsigned int getDefendingPoints() const;
};

