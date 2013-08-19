/*
* 查找一个byte中存在1的个数
*/
#include <stdio.h>

/*
* 解法1，整除求余法
* 每次对2求余,如果有余数，说明有一位1，然后除2，继续进行对2求余操作，直至 n < 0.
* 时间复杂度为O(N),空间复杂度为O(1).
*/
int count_1_1(int v)
{
	int num = 0;

	while(v)
	{
		if (v % 2 == 1)
		{
			num++;
		}
		v >>= 1;
	}
	return num;
}

/*
* 解法2
* 与1 法
* 通过不断的把1 左移,这样只需移动8次就可以了，时间复杂度降到了常数级别，空间复杂度为O(1).
*/
int count_1_2(int n)  
{
	int num = 0;
	int mask = 1;
	int count = 0;
	while(count < 8)
	{
		if((n & mask) == mask)
			num++;
		mask <<= 1;
		count++; 
	}

	return num;
}
/*
* 解法3,每次剔除一个1，将时间复杂度降到O(1的个数)
* 000100  &
* 000011 
* ------
* 000000
*  
*/
int count_1_3(int v)
{
	int num = 0;
	while(v)
	{
		v &= (v-1);
		num++;
	}
	return num;
}

//解法4
/*
* 查表法，将时间复杂度降到O(1),以空间换时间
*/

int count_1_4(int n)
{
	int countTable[256] = {
		0~255，每个数字含有1的个数
	};

	return a[n];
}
int main()
{  
	int n = 12;
	//int num = count_1_1(n);
	//int num = count_1_2(n);
	int num = count_1_3(n);
	printf("%d 中 1 的个数 为 %d \n",n,num);
	return 0;
}
