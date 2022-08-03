#pragma once
#include "PlacableActor.h"
#include "Player.h"
class Key : public PlacableActor
{
public:
	Key(int x, int y, ActorColor color)
		: PlacableActor(x, y, color)
	{

	}

	virtual ActorType GetType() override { return ActorType::Key; }
	virtual void Draw() override;
	void HandleCollision(PlacableActor* player, bool* isGameDone) override;
};

