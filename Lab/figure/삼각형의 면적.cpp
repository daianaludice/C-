/*********************************************************
*				problem : 삼각형의 면적					 *
*********************************************************/
/*********************************************************
*국민대학교 전자정보통신대학 컴퓨터공학부 20153208 이소영*
*********************************************************/
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main() {
	ifstream inp;
	int x;
	int a1, a2, b1, b2, c1, c2;
	int area;
	inp.open("input.txt");

	inp >> x;
	for (int i = 0; i < x; i++) {
		inp >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
		area = (b1 - a1)*(c2 - a2) - (c1 - a1)*(b2 - a2);

		if (area < 0) {
			cout << area*-1 << " -1" << endl;
		}
		else if (area>0) {
			cout << area << " 1" << endl;
		}

		else if (area == 0) {
			cout << area << " 0" << endl;
		}

	}


	inp.close();
	return 0;
}