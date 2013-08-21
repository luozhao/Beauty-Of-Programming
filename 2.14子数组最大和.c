/*
  1.最直接的解法.
  记Sum[i...j]为数组A中第i个元素到第j个元素的和(其中0<=i<=j<n),
  遍历所有的可能的Sum[i...j],那么时间复杂度为O(N^3)
*/
int MaxSum(int *A, int n)
{
  int maximum = -INF;
  int sum;
  for(int i = 0; i < n; i++)
  {
    for(int j = i; j < n; j++)
    {
      for(int k = i; k <= j; k++)
      {
        sum += A[k];
      }
      if(sum > maximum)
        maximum = sum;
    }
  }
  return maximum;
}

/*
  如果注意到Sum[i...j] = Sum[i...j-1] + A[j]
  则可以将上述算法的最后一个for循环省略,避免重复计算,从而使得算法得以改进,改进后的算法如下,这时负责度为O(N^2)
*/
int MaxSum(int *A, int n)
{
  int maximum  = -INF;
  int sum;
  for(int i = 0; i < n; i++)
  {
    sum = 0;
    for(j = i; j < n; j++)
    {
      sum += A[j];
      if(sum >　maximum)
        maximum = sum;
    }
  }
  return maximum;
}

