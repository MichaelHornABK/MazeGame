#include <iostream>
#include <windows.h>
#include "HealingPotion.h"

HealingPotion::HealingPotion(int x, int y, int healingAmount, ActorColor color)
	: PlacableActor(x, y, color)
	,m_healthIncrease(healingAmount)
{

}

void HealingPotion::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)m_color);

	std::cout << "^";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}
