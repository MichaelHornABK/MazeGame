#include <iostream>
#include "Game.h"
#include "AudioManager.h"
#include "StateMachineExampleGame.h"
#include <thread>

using namespace std;

void UpdateActorWithoutInput(Game* myGame);

int main()
{
	Game myGame;

	StateMachineExampleGame gameStateMachine(&myGame);

	myGame.Initialize(&gameStateMachine);

	std::thread UpdateThread(UpdateActorWithoutInput, &myGame);


	myGame.RunGameLoop();

	myGame.Deinitialize();

	AudioManager::DestroyInstance();

	return 0;
}

void UpdateActorWithoutInput(Game* myGame)
{
	while (true)
	{
		this_thread::sleep_for(chrono::milliseconds(1000));
		myGame->UpdateActorsAutomatically();
	}
}