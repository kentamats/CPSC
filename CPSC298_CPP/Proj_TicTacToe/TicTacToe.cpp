#include <iostream>

class TicTacToe
{
  public:
    TicTacToe();
    ~TicTacToe();
    void GetGrid();
    void StartGame();
    void UserTurn();
    void AiTurn();

  private:
    char grid[3][3];
    int row;
    int column;
};

TicTacToe::TicTacToe()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      grid[j][i] = '~';
    }
  }
}

TicTacToe::~TicTacToe()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      grid[j][i] = '~';
    }
  }
}

void TicTacToe::StartGame()
{
  for (int k = 0; k < 5; k++)
  {
    UserTurn();
    GetGrid();
    AiTurn();
    GetGrid();
  }
}

void TicTacToe::GetGrid()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      std::cout << grid[j][i] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void TicTacToe::UserTurn()
{
  std::cout << "Please enter grid row number:" << std::endl;
  std::cin >> row;
  std::cout << "Please enter grid column number:" << std::endl;
  std::cin >> column;
  grid[row][column] = 'X';
}

void TicTacToe::AiTurn()
{
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (grid[j][i] == '~')
      {
        grid[j][i] = 'O';
        return;
      }
    }
  }
}

int main()
{
  TicTacToe TTT;
  TTT.StartGame();

  return 0;
}
