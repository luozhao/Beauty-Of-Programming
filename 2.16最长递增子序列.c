/*
    写一个时间复杂度尽可能低的程序,求一个一维数组(N个元素)中
    最长递增子序列的长度
    例如：在序列,1，-1，2，-3，4，-5，6，-7,其中最长递增子序列是1,2,4,6
*/
int LIS(int[] array)
{
  int[] LIS = 1;  //   初始化默认长度
  for(int j = 0; j < i; j++)  //  找出前面最长的序列
  {
    if(array[i] > array[j] &&　LIS[j] + 1 > LIS[i])
    {
      LIS[i] = LIS[j] + 1;
    }
  }
  return MAX(LIS);  //  取LIS的最大值
}

-------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 1003
int A[MAXN];
int MaxV[MAXN];

// 动态规划算法O(nlogn)
int main()
{
	int n, i, j, k;
	cin >> n;
	for (i=1; i<=n; i++)
		cin >> A[i];
	MaxV[1] = A[1];
	int nmaxv = 1;	// 目前找到的最长递增子序列的长度
	// 有n个阶段，每个阶段有1个状态
	for (i=2; i<=n; i++)
	{
		// 每个状态有nmaxv种决策，以得出以元素i结尾的最长递归子序列的长度
		int u = 1, v = nmaxv;
		while (u<=v)
		{
			int mid = (u+v)>>1;
			if (MaxV[mid] < A[i])
				u = mid+1;
			else
				v = mid-1;
		}

		// 每个元素都会对数组MaxV中的某个元素产生影响
		// 使用二分搜索确定其在第v+1个位置
		nmaxv = max(nmaxv, v+1);
		MaxV[v+1] = A[i];
	}
	cout << nmaxv;
}
