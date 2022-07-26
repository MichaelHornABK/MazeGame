#pragma once
#include "PlacableActor.h"
class HealingPotion : public PlacableActor
{
public:
	HealingPotion(int x, int y, int healingAmount, ActorColor color);

	int GetHealthIncrease() const { return m_healthIncrease; }

	virtual ActorType GetType() override { return ActorType::HealingPotion; }
	virtual void Draw() override;
private:
	int m_healthIncrease;
};