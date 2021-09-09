#pragma once
#include <string>
class Card
{
protected:
	std::string name;
	std::string effect;
	unsigned int rarity;
public:
	Card() : name(""), effect(""), rarity(0) {}
	Card(std::string n, std::string eff, unsigned int rar) :name(n), effect(eff), rarity(rar) {}
	virtual bool operator >(Card& secondCard)
	{
		if (this->rarity > secondCard.rarity)
		{
			return true;
		}
		else return false;
	}
	virtual bool operator <(Card& secondCard)
	{
		if (this->rarity < secondCard.rarity)
		{
			return true;
		}
		else return false;
	}
	virtual std::string getName() = 0;
	virtual std::string getEffect() = 0;
	virtual unsigned int getRarity() = 0;
	virtual void setName(std::string n) = 0;
	virtual void setEffect(std::string eff) = 0;
	virtual void setRarity(unsigned int rar) = 0;
};
