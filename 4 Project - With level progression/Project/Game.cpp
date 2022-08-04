#include "Game.h"

Game::Game()
	: m_pStateMachine(nullptr)
{

}

void Game::Initialize(GameStateMachine* pStateMachine)
{
	if (pStateMachine != nullptr)
	{
		pStateMachine->Init();
		m_pStateMachine = pStateMachine;
	}
}

void Game::RunGameLoop()
{
	bool isGameOver = false;

	while (!isGameOver)
	{
		// update with no input
		Update(false);
		// Draw
		Draw();
		// Update with input
		isGameOver = ProcessInput();
	}

	Draw();
}

void Game::UpdateActorsAutomatically()
{
	m_pStateMachine->UpdateActors();
	Draw();
}

void Game::Deinitialize()
{
	if (m_pStateMachine != nullptr)
		m_pStateMachine->Cleanup();
}

bool Game::Update(bool processInput)
{
	return m_pStateMachine->UpdateCurrentState(processInput);
}

bool Game::ProcessInput()
{
	return m_pStateMachine->ProcessInput();
}

void Game::Draw()
{
	m_pStateMachine->DrawCurrentState();
}
