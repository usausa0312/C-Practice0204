
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
	iota(v.begin(), v.end(), 0); //++を代入　タグ付け等に役立つ // 1.先頭 2.末尾 3.初期値
	for (const auto& i : v) {
		cout << i ;
	}

	Indention;

	//定数
	struct X { int n; };
	constexpr X x = { 10 };//要素数
	int a[x.n] = { 1,2,3 };//初期化

	for (auto v : a)
	{
		cout << v;
	}

	Indention;


	//ラムダ
	vector<int> n(10);
	for (auto v : n)
	{
		int a = 0;
		std::function<int()> func = [a]() {  return a + 1; }; // ラムダ
		v = func();//コピー
		cout << v;
	}

	Indention;

	//コンパイル時初期化
	constexpr float z = exp(2, 4);
	//実行時
	cout << z;

	return 1;
}


