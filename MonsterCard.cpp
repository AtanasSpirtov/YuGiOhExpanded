#include "MonsterCard.h"
MonsterCard::MonsterCard() : Card()
{
	atackingPoints = 0;
	defendingPoints = 0;
}
MonsterCard::MonsterCard(unsigned int att, unsigned int def) : Card()
{
	atackingPoints = att;
	defendingPoints = def;
}
MonsterCard::MonsterCard(string n, string eff,unsigned int rar, unsigned int att, unsigned int def)
	: Card(n,eff,rar)
{
	atackingPoints = att;
	defendingPoints = def;
}

MonsterCard MonsterCard::operator=(const MonsterCard& newMonster)
{
	MonsterCard monsterToReturn;
	monsterToReturn.setName(newMonster.name);
	monsterToReturn.setEffect(newMonster.effect);
	monsterToReturn.setRarity(newMonster.rarity);
	monsterToReturn.setAtackingPoints(newMonster.atackingPoints);
	monsterToReturn.setDefendingPoints(newMonster.defendingPoints);
	this->name = newMonster.name;
	this->effect = newMonster.effect;
	this->rarity = newMonster.rarity;
	this->atackingPoints = newMonster.atackingPoints;
	this->defendingPoints = newMonster.defendingPoints;
	return monsterToReturn;
}

bool MonsterCard::operator>(Card& secondCard)
{
	return Card::operator>(secondCard);
}
bool MonsterCard::operator>(MonsterCard& secondCard)
{
	return Card::operator>(secondCard);
}
bool MonsterCard::operator<(Card& secondCard)
{
	return Card::operator<(secondCard);
}
bool MonsterCard::operator<(MonsterCard& secondCard)
{
	return Card::operator<(secondCard);
}

void MonsterCard::setName(string n)
{
	name = n;
}

void MonsterCard::setEffect(string eff)
{
	effect = eff;
}

void MonsterCard::setRarity(unsigned int rar)
{
	rarity = rar;
}

void MonsterCard::setAtackingPoints(unsigned int at)
{
	atackingPoints = at;
}

void MonsterCard::setDefendingPoints(unsigned int def)
{
	defendingPoints = def;
}

string MonsterCard::getName()
{
	return name;
}

string MonsterCard::getEffect()
{
	return effect;
}

unsigned int MonsterCard::getRarity()
{
	return rarity;
}

unsigned int MonsterCard::getAtackingPoints() const
{
	return atackingPoints;
}

unsigned int MonsterCard::getDefendingPoints() const
{
	return defendingPoints;
}
