#include "MagicCard.h"
MagicCard::MagicCard() : Card(),cardType(CardType::SPELL)
{
}
MagicCard::MagicCard(CardType cType) : cardType(cType)
{
}
MagicCard::MagicCard(string n, string eff, unsigned int rar, CardType type)
	: Card(n, eff, rar), cardType(type)
{
}
MagicCard MagicCard::operator=(const MagicCard& newMagic)
{
	MagicCard magicToReturn;
	magicToReturn.setName(newMagic.name);
	magicToReturn.setEffect(newMagic.effect);
	magicToReturn.setRarity(newMagic.rarity);
	magicToReturn.setCardType(newMagic.cardType);
	this->name = newMagic.name;
	this->effect = newMagic.effect;
	this->rarity = newMagic.rarity;
	this->cardType = newMagic.cardType;
	return magicToReturn;
}

bool MagicCard::operator>(Card& secondCard)
{
	return Card::operator>(secondCard);
}
bool MagicCard::operator>(MagicCard& secondCard)
{
	return Card::operator>(secondCard);
}
bool MagicCard::operator<(Card& secondCard)
{
	return Card::operator<(secondCard);
}
bool MagicCard::operator<(MagicCard& secondCard)
{
	return Card::operator<(secondCard);
}
void MagicCard::setName(string n)
{
	name = n;
}

void MagicCard::setEffect(string eff)
{
	effect = eff;
}

void MagicCard::setRarity(unsigned int rar)
{
	rarity = rar;
}

void MagicCard::setCardType(CardType type)
{
	cardType = type;
}

string MagicCard::getName()
{
	return name;
}

string MagicCard::getEffect()
{
	return effect;
}

unsigned int MagicCard::getRarity()
{
	return rarity;
}

CardType MagicCard::getCardType() const
{
	return cardType;
}
