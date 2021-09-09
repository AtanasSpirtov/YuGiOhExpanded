#pragma once
#include <iostream>
#include "Card.h"
using namespace std;
enum class CardType {
	TRAP,
	BUFF,
	SPELL
};
class MagicCard : public Card
{
private:
	CardType cardType;
public:
	MagicCard();
	MagicCard(CardType cType);
	MagicCard(std::string n, std::string eff,unsigned int rar, CardType type);
	MagicCard operator=(const MagicCard& newMagic);
	bool operator>(Card& secondCard);
	bool operator>(MagicCard& secondCard);
	bool operator<(Card& secondCard);
	bool operator<(MagicCard& secondCard);
	void setName(string n);
	void setEffect(string eff);
	void setRarity(unsigned int rar);
	void setCardType(CardType type);
	string getName();
	string getEffect();
	unsigned int getRarity();
	CardType getCardType() const;
};