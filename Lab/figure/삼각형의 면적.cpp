/*********************************************************
*				problem : �ﰢ���� ����					 *
*********************************************************/
/*********************************************************
*���δ��б� ����������Ŵ��� ��ǻ�Ͱ��к� 20153208 �̼ҿ�*
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