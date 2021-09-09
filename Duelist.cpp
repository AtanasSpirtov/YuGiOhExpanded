#include "Duelist.h"
#include <sstream>
Duelist::Duelist()
{
	this->duelistDeck = Deck();
	name = "";
}

Duelist::Duelist(string n)
{
	this->duelistDeck = Deck();
	name = n;
}

Duelist::Duelist(string n, Deck d)
{
	this->duelistDeck = d;
	name = n;
}

Duelist::~Duelist()
{
	duelistDeck.~Deck();
}

Deck& Duelist::getDeck()
{
	return duelistDeck;
}

void Duelist::setName(string newName)
{
	name = newName;
}

bool Duelist::saveDeck(string file)
{
	ofstream nameOfFile;
	nameOfFile.open(file, ios::out);
	if (nameOfFile.is_open())
	{
		nameOfFile << name
			<< "|" << duelistDeck.returnAllCardsCount()
			<< "|" << duelistDeck.returnMonsterCardsCount()
			<< "|" << duelistDeck.returnMagicCardsCount()
			<< "|" << duelistDeck.returnPendulumCardsCount() << "\n";
		for (int i = 0; i < duelistDeck.returnAllCardsCount(); i++)
		{
			//check if the card is monster card
			if (MonsterCard* mag = dynamic_cast<MonsterCard*>(duelistDeck.returnCard(i)))
			{
				//check if the card is not pendulum card
				if (PendulumCard* pend = dynamic_cast<PendulumCard*>(duelistDeck.returnCard(i)))
				{
				}
				else {
					nameOfFile << duelistDeck.returnCard(i)->getName() << "|"
						<< duelistDeck.returnCard(i)->getEffect() << "|"
						<< duelistDeck.returnCard(i)->getRarity() << "|"
						<< dynamic_cast<MonsterCard*>(duelistDeck.returnCard(i))->getAtackingPoints() << "|"
						<< dynamic_cast<MonsterCard*>(duelistDeck.returnCard(i))->getDefendingPoints() << "\n";
				}
			}
		}
		for (int i = 0; i < duelistDeck.returnAllCardsCount(); i++)
		{
			//check if the card is magic card
			if (MagicCard* mag = dynamic_cast<MagicCard*>(duelistDeck.returnCard(i)))
			{
				//check if the card is not pendulum card
				if (PendulumCard* pend = dynamic_cast<PendulumCard*>(duelistDeck.returnCard(i)))
				{
				}
				else {
					nameOfFile << duelistDeck.returnCard(i)->getName() << "|"
						<< duelistDeck.returnCard(i)->getEffect() << "|"
						<< duelistDeck.returnCard(i)->getRarity() << "|"
						<< duelistDeck.TypeToString(dynamic_cast<MagicCard*>(duelistDeck.returnCard(i))->getCardType()) <<"\n";
					//call a function that converts Card type to string
				}
			}
		}
		for (int i = 0; i < duelistDeck.returnAllCardsCount(); i++)
		{
			//check if the card is pendulum card
			if (PendulumCard* pend = dynamic_cast<PendulumCard*>(duelistDeck.returnCard(i)))
			{
				nameOfFile << duelistDeck.returnCard(i)->getName() << "|"
					<< duelistDeck.returnCard(i)->getEffect() << "|"
					<< duelistDeck.returnCard(i)->getRarity() << "|"
					<< dynamic_cast<PendulumCard*>(duelistDeck.returnCard(i))->getAtackingPoints() << "|"
					<< dynamic_cast<PendulumCard*>(duelistDeck.returnCard(i))->getDefendingPoints() << "|"
					<< dynamic_cast<PendulumCard*>(duelistDeck.returnCard(i))->getPendLevel() << "|"
					<< duelistDeck.TypeToString(dynamic_cast<PendulumCard*>(duelistDeck.returnCard(i))->getCardType()) << "\n";
			}
		}
	}
	return true;
}

CardType fromStringToCardType(string setType)
{
	if (setType == "SPELL")
	{
		return CardType::SPELL;
	}
	else if (setType == "BUFF")
	{
		return CardType::BUFF;
	}
	else return CardType::TRAP;
}

bool Duelist::loadDeck(string file)
{
	duelistDeck.deleteDeck();
	string lines;
	int row = 0;
	ifstream fileToRead(file);
	if (fileToRead.is_open())
	{
		int monstersCount = 0;
		int magicCount = 0;
		int pendulumCount = 0;
		while (getline(fileToRead,lines))
		{
			if (row == 0)
			{
				duelistDeck.setDeckname(lines.substr(0, lines.find("|")));
				lines.erase(0, lines.find("|") + 1);
				lines.erase(0, lines.find("|") + 1);//Example: format is "Deck|5|2|2|1" and we erase 5 because we dont need it
				monstersCount = stoi(lines.substr(0, '|'));
				lines.erase(0, lines.find("|") + 1);
				magicCount = stoi(lines.substr(0, '|')) + monstersCount;
				lines.erase(0, lines.find("|") + 1);
				pendulumCount = stoi(lines.substr(0, '|')) + magicCount;
				lines.erase(0, lines.find("|") + 1);
			}
			else
			{
				if (row > 0 && row <= monstersCount)
				{
					MonsterCard* monsterToAdd = new MonsterCard();
					monsterToAdd->setName(lines.substr(0, lines.find("|")));
					lines.erase(0, lines.find("|") + 1);
					monsterToAdd->setEffect(lines.substr(0, lines.find("|")));
					lines.erase(0, lines.find("|") + 1);
					monsterToAdd->setRarity(stoi(lines.substr(0, lines.find("|"))));
					lines.erase(0, lines.find("|") + 1);
					monsterToAdd->setAtackingPoints(stoi(lines.substr(0, lines.find("|"))));
					lines.erase(0, lines.find("|") + 1);
					monsterToAdd->setDefendingPoints(stoi(lines.substr(0, lines.find("|"))));
					lines.erase(0, lines.find("|") + 1);
					duelistDeck.addCard(monsterToAdd);
					//delete monsterToAdd;
					//we dont delete monsterToAdd because when we add card to the deck the vector manages the memory

				}
				else if (row > monstersCount && row <= magicCount)
				{
					MagicCard* magicToAdd = new MagicCard();
					magicToAdd->setName(lines.substr(0, lines.find("|")));
					lines.erase(0, lines.find("|") + 1);
					magicToAdd->setEffect(lines.substr(0, lines.find("|")));
					lines.erase(0, lines.find("|") + 1);
					magicToAdd->setRarity(stoi(lines.substr(0, lines.find("|"))));
					lines.erase(0, lines.find("|") + 1);
					magicToAdd->setCardType(fromStringToCardType(lines.substr(0, lines.find("|"))));
					lines.erase(0, lines.find("|") + 1);
					duelistDeck.addCard(magicToAdd);
					//delete magicToAdd;
					//we dont delete magicToAdd because when we add card to the deck the vector manages the memory

				}
				else if (row > magicCount && row <= pendulumCount)
				{
					PendulumCard* pendulumToAdd = new PendulumCard();
					pendulumToAdd->setName(lines.substr(0, lines.find("|")));
					lines.erase(0, lines.find("|") + 1);
					pendulumToAdd->setEffect(lines.substr(0, lines.find("|")));
					lines.erase(0, lines.find("|") + 1);
					pendulumToAdd->setRarity(stoi(lines.substr(0, lines.find("|"))));
					lines.erase(0, lines.find("|") + 1);
					pendulumToAdd->setAtackingPoints(stoi(lines.substr(0, lines.find("|"))));
					lines.erase(0, lines.find("|") + 1);
					pendulumToAdd->setDefendingPoints(stoi(lines.substr(0, lines.find("|"))));
					lines.erase(0, lines.find("|") + 1);
					pendulumToAdd->setPendlevel(stoi(lines.substr(0, lines.find("|"))));
					lines.erase(0, lines.find("|") + 1);
					pendulumToAdd->setCardType(fromStringToCardType(lines.substr(0, lines.find("|"))));
					duelistDeck.addCard(pendulumToAdd);
					//delete pendulumToAdd;
					//we dont delete pendulumToAdd because when we add card to the deck the vector manages the memory
				}
			}
			row++;
		}
		fileToRead.close();
		return true;
	}
	else return false;

}

Duel Duelist::duel(Duelist secondDuelist)
{
	if (this->duelistDeck.returnAllCardsCount() != secondDuelist.duelistDeck.returnAllCardsCount())
	{
		return Duel::CannotStartDuel;
	}
	else
	{
		int player1Points = 0;
		int player2Points = 0;
		this->duelistDeck.shuffle();
		secondDuelist.duelistDeck.shuffle();
		for (int i = 0; i < this->duelistDeck.returnAllCardsCount(); i++)
		{
			(this->duelistDeck.returnCard(i)->operator>(*secondDuelist.duelistDeck.returnCard(i))) ? player1Points++ 
		   :(this->duelistDeck.returnCard(i)->operator<(*secondDuelist.duelistDeck.returnCard(i))) ? player2Points++ 
		   :player1Points+=0 , player2Points+=0;
		}
		return (player1Points > player2Points) ? Duel::Player1Wins :
			   (player1Points < player2Points) ? Duel::Player2Wins : Duel::Draw;

	}
}
