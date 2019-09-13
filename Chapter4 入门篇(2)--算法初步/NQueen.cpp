#include <cstdio>
#include <cstdlib>
const int maxn = 11;
// P 为当前排列，hashTable记录整数x是否已经在P中
int n, P[maxn], hashTable[maxn] = {false};
int count = 0; 
void generateP(int index){
	if (index == n + 1){  //递归边界，生成一个排列
		bool flag = true;  //flag为true表示当前排列为一个合法方案
		for(int i=1; i<=n;i++){
			for (int j = i+1; j <= n; j++){
				if(abs(i-j) == abs(P[i]-P[j])){  //如果在一条对角线上
					flag = false; //不合法
				}
			}
		}
		if (flag) count++;
		return;
	}
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
int main()
{
	n = 8;
	generateP(1);
    printf("%d\n",count);
	system("pause");
}