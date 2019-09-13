#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn = 11;
// P 为当前排列，hashTable记录整数x是否已经在P中
int n, P[maxn], hashTable[maxn] = {false};
void generateP(int index)
{
	if (index == n + 1)
	{ // 递归边界，已经处理完排列的1~n位
		for (int i = 1; i <= n; i++)
		{
			printf("%d", P[i]);
		}
		printf("\n");
		return;
	}
	else
	{
		for (int x = 1; x <= n; x++)
		{ // 枚举 1~n ，试图将  x 填入 P[index]位置
			if (hashTable[x] == false)
			{
				P[index] = x;
				hashTable[x] = true;  //记 x 已在 P 中
				generateP(index + 1); //处理排列的第 index+1 号位
				hashTable[x] = false; //已处理完P[index]为 x 的子问题，还原状态
			}
		}
	}
}

int main()
{
	n = 3;
	generateP(1);
	// return 0;
	system("pause");
}
