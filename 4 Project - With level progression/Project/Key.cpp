#include <iostream>
#include <windows.h>
#include "AudioManager.h"
#include "Key.h"

void Key::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, (int)m_color);

	std::cout << "+";
	SetConsoleTextAttribute(console, (int)ActorColor::Regular);
}


void Key::HandleCollision(PlacableActor* player, bool* isGameDone)
{
	Player* collidedPlayer = dynamic_cast<Player*>(player);
	if (!collidedPlayer->HasKey())
	{
		collidedPlayer->PickupKey(this);
		this->Remove();
		collidedPlayer->SetPosition(this->GetXPosition(), this->GetYPosition());
		AudioManager::GetInstance()->PlayKeyPickupSound();
	}
}