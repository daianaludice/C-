#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>


const int max_board_size = 100;

class LifeGame
{
public:
   typedef enum BoardStatus { ALIVE, DEAD };

   LifeGame();
   LifeGame(int rSize, int cSize, char gameCells[][max_board_size + 1]);

   void setBoard(int rSize, int cSize, char gameCells[][max_board_size + 1]);

   void runLifeGame(int time);
   void printBoard();

private:
   BoardStatus board[max_board_size][max_board_size];

   int rowSize, colSize;
   int numAliveCells;

   void getNextGeneration();
};

//생성자
LifeGame::LifeGame(){}

LifeGame::LifeGame(int rSize, int cSize, char gameCells[][max_board_size + 1])
{
   setBoard(rSize, cSize, gameCells);
}

//public function
void LifeGame::setBoard(int rSize, int cSize, char gameCells[][max_board_size + 1])
{
   rowSize = rSize;
   colSize = cSize;

   for (int i = 0; i < max_board_size; i++)
      for (int j = 0; j < max_board_size; j++)
         if (gameCells[i][j] == 'O')
            board[i][j] = ALIVE;
         else
            board[i][j] = DEAD;
}

void LifeGame::runLifeGame(int time)
{
   for (int i = 0; i < time; i++)
      getNextGeneration();
}

void LifeGame::printBoard()
{
   numAliveCells = 0;
   //살아있는 셀 개수 세리기
   for (int i = 0; i < rowSize; i++)
      for (int j = 0; j < colSize; j++)
         if (board[i][j] == ALIVE)
            numAliveCells++;

   std::cout << numAliveCells << std::endl;

   for (int i = 0; i < rowSize; i++)
   {
      for (int j = 0; j < colSize; j++)
      {//바꿔서 출력
         if (board[i][j] == ALIVE)
            std::cout << 'O';
         else
            std::cout << 'X';
      }
      std::cout << std::endl;
   }
}

void LifeGame::getNextGeneration()
{
   int temp[max_board_size][max_board_size] = { 0, };

   //temp에 presentGeneration의 각 좌표의 주변에 몇개 살아있는지 개수 저장
   for (int i = 0; i<rowSize; i++)
      for (int j = 0; j<colSize; j++)
      {
         if ((i-1>-1) && (j-1>-1))
            if (board[i - 1][j - 1] == ALIVE)
               temp[i][j]++;
         if (i-1>-1)
            if (board[i - 1][j] == ALIVE)
               temp[i][j]++;
         if ((i-1>-1) && (j+1<colSize))
            if (board[i - 1][j + 1] == ALIVE)
               temp[i][j]++;
         if (j-1>-1)
            if (board[i][j - 1] == ALIVE)
               temp[i][j]++;
         if (j+1<colSize)
            if (board[i][j + 1] == ALIVE)
               temp[i][j]++;
         if ((i+1<rowSize) && (j-1>-1))
            if (board[i + 1][j - 1] == ALIVE)
               temp[i][j]++;
         if (i+1<rowSize)
            if (board[i + 1][j] == ALIVE)
               temp[i][j]++;
         if ((i+1<rowSize) && (j+1<colSize))
            if (board[i + 1][j + 1] == ALIVE)
               temp[i][j]++;
      }

   //temp에 저장된 숫자로 조건에 맞는 다음 세대 구하기
   for (int i = 0; i<rowSize; i++)
      for (int j = 0; j<colSize; j++)
      {
         if (temp[i][j] <= 1)
            board[i][j] = DEAD;
         else if (temp[i][j] == 2 || temp[i][j] == 3)
         {
            if ((temp[i][j] == 3) && (board[i][j] == DEAD))
               board[i][j] = ALIVE;
            else if (board[i][j] == ALIVE)
               board[i][j] = ALIVE;
         }
         else if (temp[i][j] >= 4)
            board[i][j] = DEAD;
      }
}



int main(int argc, char argv[])
{
   std::ifstream inStream;
   int numCases;

   inStream.open("input.txt");
   if (inStream.fail()) { std::cerr << "opening failed" << std::endl; }

   inStream >> numCases;
   LifeGame lifeGame;

   for (int i = 0; i < numCases; i++)
   {
      int rows, cols;
      int timeToGo;
      char initBoard[max_board_size][max_board_size + 1];

      inStream >> rows >> cols;
      inStream >> timeToGo;


      for (int j = 0; j < rows; j++)
         inStream >> initBoard[j];

      lifeGame.setBoard(rows, cols, initBoard);
      lifeGame.runLifeGame(timeToGo);
      lifeGame.printBoard();
   }

   inStream.close();
   return 0;
}