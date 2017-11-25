/***********************************************************
*            Problem : 수직,수평 선분의 교차               *
***********************************************************/

/***********************************************************
* 국민대학교 전자정보통신대학 컴퓨터공학부 20153208 이소영 *
***********************************************************/
#include<iostream>
#include<fstream>
using namespace std;

void hv(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

int main(){

	ifstream inStream;

	int in;
	int x1, x2, x3, x4, y1, y2, y3, y4;
	int a;

	inStream.open("input.txt");

	inStream >> in;

	for (int i = 0; i < in; i++)
	{
		inStream >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		a = 0;

		if (x1 > x2)
		{
			a = x1;
			x1 = x2;
			x2 = a;
		}
		if (x3 > x4)
		{
			a = x3;
			x3 = x4;
			x4 = a;
		}
		if (y1 > y2)
		{
			a = y1;
			y1 = y2;
			y2 = a;
		}
		if (y3 > y4)
		{
			a = y3;
			y3 = y4;
			y4 = a;
		}
		hv(x1, y1, x2, y2, x3, y3, x4, y4);
	}
}

void hv(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{

	if (x1 == x2)
	{
		if (y3 == y4)
		{
			if ((!((x3 <= x1) && (x1 <= x4))) || (!((y1 <= y3) && (y3 <= y2))))
			{
				cout << "0";
			}
			else if (((x3 < x1) && (x1 < x4)) && ((y1 < y3) && (y3 < y2)))
			{
				cout << "1";
			}
			else
			{
				cout << "2";
			}
		}
	}
	else if (y1 == y2)
	{
		if (x3 == x4)
		{
			if ((!((x1 <= x3) && (x3 <= x2))) || (!((y3 <= y1) && (y1 <= y4))))
			{
				cout << "0";
			}
			else if (((x1 < x3) && (x3 < x2)) && ((y3 < y1) && (y1 < y4)))
			{
				cout << "1";
			}
			else
			{
				cout << "2";
			}

		}
	}
	cout << "\n";
}

