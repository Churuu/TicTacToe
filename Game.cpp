#include "Game.h";

int main()
{
	Game g;
	while (!gameEnded)
	{
		g.Loop();
	}
}


Game::Game()
{
	for (int i = 0; i < 9; i++)
	{
		board[i].ChangeBrick(Brick::Q);
	}
}


void Game::Loop()
{

	GetPlayerTurn();
	UpdateBoard();
	SetBrickOnBoard();
	CheckWinner();

}

void Game::UpdateBoard()
{

	system("CLS");
	cout << "Current player is " << (playerTurn == 1 ? "X" : "O") << "\n\n";

	for (int i = 1; i <= 9; i++)
	{
		if (board[i - 1].GetBrick().GetBrickType() == 0)
			cout << i;
		else if (board[i - 1].GetBrick().GetBrickType() == 1)
			cout << "X";
		else 
			cout << "O";

		if (i % 3 == 0)
			cout << endl;
		else cout << " || ";

	}
}

void Game::CheckWinner()
{
	for (int i = 0; i < 9; i += 3)
	{
		if (board[i].GetBrick().GetBrickType() == playerTurn && board[i + 1].GetBrick().GetBrickType() == playerTurn && board[i + 2].GetBrick().GetBrickType() == playerTurn)
		{
			GameEnded(playerTurn);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (board[i].GetBrick().GetBrickType() == playerTurn && board[i + 3].GetBrick().GetBrickType() == playerTurn && board[i + 6].GetBrick().GetBrickType() == playerTurn)
		{
			GameEnded(playerTurn);
		}
	}
	if (board[0].GetBrick().GetBrickType() == playerTurn && board[4].GetBrick().GetBrickType() == playerTurn && board[8].GetBrick().GetBrickType() == playerTurn)
	{
		GameEnded(playerTurn);
	}
	if (board[2].GetBrick().GetBrickType() == playerTurn && board[4].GetBrick().GetBrickType() == playerTurn && board[6].GetBrick().GetBrickType() == playerTurn)
	{
		GameEnded(playerTurn);
	}
}

void Game::GetPlayerTurn()
{
	if (playerTurn == 1)
		playerTurn = 2;
	else
		playerTurn = 1;
}

void Game::GameEnded(int winner)
{
	UpdateBoard();
	gameEnded = true;
	cout << "Winner is " << (winner == 1 ? "X" : "O") << endl;
}

void Game::SetBrickOnBoard()
{
	int playerInput;
	do
	{
		cin >> playerInput;
		playerInput--;
	} while (playerInput < 0 && playerInput > 10 || board[playerInput].locked);


	if (playerTurn == 1)
		board[playerInput].ChangeBrick(Brick::X);
	else if (playerTurn == 2)
		board[playerInput].ChangeBrick(Brick::O);

	board[playerInput].locked = true;
}


