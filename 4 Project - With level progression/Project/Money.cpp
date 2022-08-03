#include <iostream>
#include "Money.h"
#include "AudioManager.h"

Money::Money(int x, int y, int worth)
	: PlacableActor(x, y)
	, m_worth(worth)
{

}

void Money::Draw()
{
	std::cout << "$";
}

void Money::HandleCollision(PlacableActor* player, bool* isGameDone)
{
	Player* collidedPlayer = dynamic_cast<Player*>(player);
	AudioManager::GetInstance()->PlayMoneySound();
	this->Remove();
	collidedPlayer->AddMoney(this->GetWorth());
	collidedPlayer->SetPosition(this->GetXPosition(), this->GetYPosition());
}
