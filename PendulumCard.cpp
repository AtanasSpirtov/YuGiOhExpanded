#include "PendulumCard.h"

PendulumCard::PendulumCard() :MonsterCard(), MagicCard(), pendulumLevel(0)
{
}

PendulumCard::PendulumCard(string name, string effect,unsigned int rarity, 
	unsigned int attackingPoints, unsigned int defendingPoints,short int pendLevel, CardType typeOfC)
	: MonsterCard(name, effect,rarity, attackingPoints, defendingPoints), 
	  MagicCard(name,effect,rarity ,typeOfC), 
	  pendulumLevel(pendLevel)
{
}

PendulumCard PendulumCard::operator=(const PendulumCard& newPendulumCard)
{
	PendulumCard pendulumCardToReturn;
	pendulumCardToReturn.setName(newPendulumCard.getName());
	pendulumCardToReturn.setEffect(newPendulumCard.getEffect());
	pendulumCardToReturn.setRarity(newPendulumCard.getRarity());
	pendulumCardToReturn.setAtackingPoints(newPendulumCard.getAtackingPoints());
	pendulumCardToReturn.setDefendingPoints(newPendulumCard.getDefendingPoints());
	pendulumCardToReturn.setCardType(newPendulumCard.getCardType());
	pendulumCardToReturn.setPendlevel(newPendulumCard.getPendLevel());
	this->setName(newPendulumCard.getName());
	this->setEffect(newPendulumCard.getEffect());
	this->setRarity(newPendulumCard.getRarity());
	this->setAtackingPoints(newPendulumCard.getAtackingPoints());
	this->setDefendingPoints(newPendulumCard.getDefendingPoints());
	this->setCardType(newPendulumCard.getCardType());
	this->pendulumLevel = newPendulumCard.pendulumLevel;
	return pendulumCardToReturn;
}
bool PendulumCard::operator>(MonsterCard& secondCard)
{
	return Card::operator>(secondCard);
}
bool PendulumCard::operator>(Card& secondCard)
{
	return Card::operator>(secondCard);
}

bool PendulumCard::operator<(Card& secondCard)
{
	return Card::operator<(secondCard);
}
bool PendulumCard::operator<(MonsterCard& secondCard)
{
	return Card::operator<(secondCard);
}

void PendulumCard::setPendlevel(short int newPendulumLevel)
{
	pendulumLevel = newPendulumLevel;
}

void PendulumCard::setName(string n)
{
	Card::name = n;
}

void PendulumCard::setEffect(string eff)
{
	Card::effect = eff;
}

void PendulumCard::setRarity(unsigned int rar)
{
	Card::rarity = rar;
}

short int PendulumCard::getPendLevel() const
{
	return pendulumLevel;
}

string PendulumCard::getName() const
{
	return Card::name;
}

string PendulumCard::getEffect() const
{
	return Card::effect;
}

unsigned int PendulumCard::getRarity() const
{
	return Card::rarity;
}
