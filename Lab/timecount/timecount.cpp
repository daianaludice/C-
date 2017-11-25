/***********************************************************
*					 problem : 시간 계산				    *
************************************************************/

/***********************************************************
* 국민대학교 전자정보통신대학 컴퓨터공학부 20153208 이소영 *
************************************************************/
#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

int main()
{
	ifstream inp;
	int t, n, H, M, S, h, m, s;
	int totalsecST;
	int totalsecFI;
	int person[99];
	int totalsec=0;
	int i, ii,j, jj, k, k;

	inp.open("input.txt");
	
	inp >> t;
	for (int i = 0; i < t; i++) {
		inp >> n;
		for (int j = 0; j < n; j++) {
			inp >> H;
			inp >> M;
			inp >> S;
			inp >> h;
			inp >> m;
			inp >> s;

			totalsecST = H * 3600 + M * 60 + S;
			totalsecFI = h * 3600 + m * 60 + s;
			person[j] = totalsecFI - totalsecST;

			totalsec = totalsec + person[j];

			if (totalsec < 0)
			{
				totalsec = 86400 + totalsec;
			}

		}
		i = totalsec / 86400;
		ii = totalsec - 86400 * i;
		j = jj / 3600;
		jj = ii - 3600 * j;
		k = jj / 60;
		g = jj % 60;

		cout<< i<<" " <<j<<" "<< k<<" "<< g<<"\n";
		totalsec = 0;
	}
	inp.close();
		return 0;
	}
