#include <iostream>
using namespace std;
#include "PendulumCard.h"
#include "Deck.h"
#include "Duelist.h"
int main()
{
	PendulumCard pend("StanchoPend", "spec1", 3, 100, 200, 8, CardType::BUFF);
	MagicCard mag("StanchoMag", "pie grozdnaka", 4, CardType::SPELL);
	MonsterCard mon("StanchoMonster", "lolo", 6, 100, 200);
	Duelist d1("stancho");
	d1.loadDeck("text.txt");
	Duelist d2("Groza");
	d1.getDeck().setDeckname("stancho");
	MagicCard mag1("GrozaMag", "pie poveche grozdanka", 12, CardType::TRAP);
	MonsterCard mon1("GozaMon", "spec2", 20, 2000, 3000);
	PendulumCard pend1("GrozaPend", "spec3 opa", 12, 2000, 30000, 30, CardType::BUFF);
	d2.getDeck().addCard(&mag1);
	d2.getDeck().addCard(&mon1);
	d2.getDeck().addCard(&pend1);
	d1.duel(d2);
}