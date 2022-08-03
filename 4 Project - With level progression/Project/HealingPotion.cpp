#include <iostream>
#include <windows.h>
#include "HealingPotion.h"
#include "AudioManager.h"

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

void HealingPotion::HandleCollision(PlacableActor* player, bool* isGameDone)
{
	Player* collidedPlayer = dynamic_cast<Player*>(player);
	AudioManager::GetInstance()->PlayHPSound();
	this->Remove();
	collidedPlayer->AddHP(this->GetHealthIncrease());
	//This breakpoint was to help me see if the player collision with the healing potion is working.
	//Also from looking at the local variables, I can see that the healing potion worked by incrementing the player's lives.
	collidedPlayer->SetPosition(this->GetXPosition(), this->GetYPosition());
}