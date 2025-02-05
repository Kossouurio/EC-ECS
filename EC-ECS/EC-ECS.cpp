#include <iostream>
#include "Entity.h"

int main()
{
	Entity* Player = new Entity();
	Player->AddComoponent<Transform>(Player, 0.0f, 0.0f, 0.0f);
	Player->AddComoponent<Mesh>(Player);
	Player->AddComoponent<Stats>(Player, 10.0f, 100.0f, 5.0f, 10.0f);

	std::cout << "Player ID: " << Player->GetID() << std::endl;
	std::cout << "Player Transform: " << (int) Player->GetComponent<Transform>()->GetType() << std::endl;
	std::cout << "Player Mesh: " << (int) Player->GetComponent<Mesh>()->GetType() << std::endl;
	std::cout << "Player Stats: " << (int) Player->GetComponent<Stats>()->GetType() << std::endl;

	delete Player;

	return 0;
}
