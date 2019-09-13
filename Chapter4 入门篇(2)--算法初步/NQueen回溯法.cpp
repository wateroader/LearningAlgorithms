#include <cstdio>
#include <cstdlib>
const int maxn = 11;
// P 为当前排列，hashTable记录整数x是否已经在P中
int n, P[maxn], hashTable[maxn] = {false};
int count = 0;
void generateP(int index)
{
    if (index == n + 1)
    {            //递归边界，生成一个排列
        count++; //能到达这里的一定合法
        return;
    }
    else
    {
        for (int x = 1; x <= n; x++)
        {
            if (hashTable[x] == false)
            {
                bool flag = true;
                for (int pre = 0; pre < index; pre++)
                {
                    if (abs(index - pre) == abs(x - P[pre]))
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    P[index] = x;
                    hashTable[x] = true;
                    generateP(index + 1);
                    hashTable[x] = false;
                }
            }
        }
    }
}
int main()
{
    n = 8;
    generateP(1);
    printf("%d\n", count);
    system("pause");
}