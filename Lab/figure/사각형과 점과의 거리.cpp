/*********************************************************
*			problem : 사각형과 점과의 거리				 *
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
	inp.open("input.txt");
	int count;
	int x1, y1, x2, y2;
	int p, q;

	inp >> count;

	for (int i = 0; i < count; i++) {
		inp >> x1 >> y1 >> x2 >> y2 >> p >> q;

		if (p >= x1 && p <= x2 && q >= y1 && q <= y2) {
			std::cout << "0" << " " << "0" << endl;
		}
		else if (p >= x1 && p <= x2) {
			if (q < y1) {
				std::cout <<(y1-q)*(y1-q)<<" "<< y1 - q<<endl;
			}
			else if (q>y2) {
				std::cout << (q - y2)*(q - y2)<<" " << q - y2<<endl;
			}
		}
		else if (q >= y1 && q <= y2) {
			if (p < x1) {
				std::cout << (x1 - p)*(x1 - p) << " " << x1 - p << endl;
			}
			else if (p>x2) {
				std::cout << (p - x2)*(p - x2) << " " << p - x2 << endl;
			}
		}
		else if (p > x2) {
			if (q > y2) {
				std::cout << (p - x2)*(p - x2) + (q - y2)*(q - y2) << " " << p - x2 + q - y2 << endl;
			}
			else if (q < y1) {
				std::cout << (p - x2)*(p - x2) + (y1 - q)*(y1 - q) << " " << p - x2 + y1 - q << endl;
			}
		}
		else if (p < x1) {
			if (q > y2) {
				std::cout << (x1 - p)*(x1 - p) + (q - y2)*(q - y2) << " " << x1 - p + q - y2 << endl;
			}
			else if (q < y1) {
				std::cout << (x1 - p)*(x1 - p) + (y1 - q)*(y1 - q) << " " << x1 - p + y1 - q << endl;
			}
		}
	}

	inp.close();
	return 0;
}