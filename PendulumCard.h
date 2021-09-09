#pragma once
#include "MonsterCard.h"
#include "MagicCard.h"
class PendulumCard :virtual public MonsterCard, virtual public MagicCard
{
private:
	short int pendulumLevel;
public:
	PendulumCard();
	PendulumCard(string name, string effect,unsigned int rarity, unsigned int attackingPoints, unsigned int defendingPoints, short int pendLevel, CardType typeOfC);
	PendulumCard operator=(const PendulumCard& newPendulumCard);
	bool operator>(MonsterCard& secondCard);
	bool operator>(Card& secondCard);
	bool operator<(Card& secondCard);
	bool operator<(MonsterCard& secondCard);
	void setPendlevel(short int newPendulumLevel);
	void setName(string n);
	void setEffect(string eff);
	void setRarity(unsigned int rar);
	short int getPendLevel() const;
	string getName() const;
	string getEffect() const;
	unsigned int getRarity() const;
};

