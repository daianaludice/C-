/***********************************************************
*           Problem : ���̾Ƹ�� ��� ����ϱ�             *
***********************************************************/

/***********************************************************
* ���δ��б� ����������Ŵ��� ��ǻ�Ͱ��к� 20153208 �̼ҿ� *
***********************************************************/

#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

void makdiamond(int n)
{
	for (int i = n / 2; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
			cout<<"*";
		for (int k = 0; k < n - (i * 2); k++)
			cout<<"+";
		for (int h = 0; h < i; h++)
			cout<<"*";
			cout<<"\n";
	}
	for (int i = 1; i <= n / 2; i++)
	{
		for (int j = 0; j < i; j++)
			cout << "*";
		for (int k = 0; k < n - (i * 2); k++)
			cout << "+";
		for (int h = 0; h < i; h++)
			cout << "*";
			cout << "\n";

	}

}

int main()
{
	ifstream in;
	int inn, ds;
	in.open("input.txt");
	if (in.fail())
	{
		cerr << "input file open fail\n";
		exit(1);
	}

	in >> inn;
	for (int i = 0; i < inn; i++)
	{
		in >> ds;
		makdiamond(ds);
	}
	in.close();
	
	return 0;
}