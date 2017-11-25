/*********************************************************
*			problem : 삼각형의 종류2					 *
*********************************************************/
/*********************************************************
*국민대학교 전자정보통신대학 컴퓨터공학부 20153208 이소영*
*********************************************************/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<math.h>
using namespace std;

int main()
{
	ifstream inp;
	int x;
	int a, b, c, d, e, f;
	double A1, B1, C1;
	int arr[3];
	int k;
	inp.open("input.txt");

	inp >> x;
	for (int i = 0; i < x; i++) {
		inp >> a;
		inp >> b;
		inp >> c;
		inp >> d;
		inp >> e;
		inp >> f;
		arr[0] = (c - a)*(c - a) + (d - b)*(d - b);
		arr[1] = (f - b)*(f - b) + (e - a)*(e - a);
		arr[2] = (f - d)*(f - d) + (e - c)*(e - c);

		for (int j = 0; j < 2; j++) {
			if (arr[j] > arr[j + 1])
			{
				k = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = k;
			}
		}
		A1 = sqrt(arr[0]);
		B1 = sqrt(arr[1]);
		C1 = sqrt(arr[2]);


		if (A1 + B1 <= C1)
		{
			std::cout << "0" << endl;
		}


		else if (A1 + B1 > C1) {

			if (arr[0] + arr[1] == arr[2])
			{
				std::cout << "1" << endl;
			}

			else if (arr[0] + arr[1] < arr[2])
			{
				std::cout << "2" << endl;
			}

			else if (arr[0] + arr[1] > arr[2])
			{
				std::cout << "3" << endl;
			}
		}
	}

	inp.close();
	return 0;
}