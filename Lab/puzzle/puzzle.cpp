#include<iostream>
#include<fstream>
#include<cstdlib>

const int max_size = 100;



int main(int argc, char argv[])
{
	std::ifstream inStream;
	int numCases;

	inStream.open("input.txt");
	if (inStream.fail()) { std::cerr << "opening failed" << std::endl; }

	inStream >> numCases;
	for (int i = 0; i < numCases; i++)
	{
		char board[max_size][max_size] = { NULL };
		char word[max_size][max_size] = { NULL };
		int row, col, w_num;
		
		inStream >> row >> col;
		for (int j = 0; j < row; j++)
			inStream >> board[j];

		inStream >> w_num;
		for (int j = 0; j < w_num; j++)
			inStream >> word[j];
		///////////////////////////////////////////////


		for (int j = 0; j < w_num; j++)
		{
			int k = 0, wcnt = 0;
			while (word[j][k] != NULL)
				wcnt++;
			int ans;


			for (int a = 0; a < row; a++)
			{
				for (int b = 0; b < col; b++)
				{
					if (word[j][0] == board[a][b])//같은 한글자 찾음
					{
						int cnt = 1;
						for (int c = 1; c < wcnt; c++)
						{//아래
							if ((a <= a - wcnt)&&word[j][c] == board[a + c][b]) cnt++;
							if (cnt == wcnt) ans = 4;
						}

						int cnt = 1;
						for (int c = 1; c < wcnt; c++)
						{//오른쪽
							if (( <= wcnt) && word[j][c] == board[a][b + c]) cnt++;
							if (cnt == wcnt) ans = 2;
						}

					}
				}



			} 
		}




		std::cout << board[0] << std::endl;
	/////////////////////////////////////////
	}

	inStream.close();
	return 0;
}

