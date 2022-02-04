
#include<iostream>
#include<vector>
#include <numeric>
#include<functional>

using std::cout;
using std::endl;
using std::vector;
using std::iota;
using std::function;



constexpr float exp(float x, int n)
{
	return n == 0 ? 1 :
		n % 2 == 0 ? exp(x * x, n / 2) :
		exp(x * x, (n - 1) / 2) * x;
}

#define Indention  cout << endl;

int main(void)
{
	//initializer_list
	for (auto i : { 1,2,3,4,5 }) {
		cout << i ;
	}

	Indention;

	//iota
	vector<int> v(10);
	iota(v.begin(), v.end(), 0); //++�����@�^�O�t�����ɖ𗧂� // 1.�擪 2.���� 3.�����l
	for (const auto& i : v) {
		cout << i ;
	}

	Indention;

	//�萔
	struct X { int n; };
	constexpr X x = { 10 };//�v�f��
	int a[x.n] = { 1,2,3 };//������

	for (auto v : a)
	{
		cout << v;
	}

	Indention;


	//�����_
	vector<int> n(10);
	for (auto v : n)
	{
		int a = 0;
		std::function<int()> func = [a]() {  return a + 1; }; // �����_
		v = func();//�R�s�[
		cout << v;
	}

	Indention;

	//�R���p�C����������
	constexpr float z = exp(2, 4);
	//���s��
	cout << z;

	return 1;
}


