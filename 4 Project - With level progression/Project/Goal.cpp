#include <iostream>
#include "Goal.h"

Goal::Goal(int x, int y)
	: PlacableActor(x, y)
{
	
}

void Goal::Draw()
{
	std::cout << "X";
}

void Goal::HandleCollision(PlacableActor* player, bool* isGameDone)
{
	Player* collidedPlayer = dynamic_cast<Player*>(player);
	this->Remove();
	collidedPlayer->SetPosition(this->GetXPosition(), this->GetYPosition());
	*isGameDone = true;
}