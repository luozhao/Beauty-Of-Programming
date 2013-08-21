/*
  数组循环移位:
  1.逆序排列abcd: abcd1234 --> dcba1234
  2.逆序排列1234: dcba1234 --> dcba4321
  3.全部逆序:     dcba4321 --> 1234abcd
*/

void reverse(int *arr, int b, int e)
{
  for(; b < e; b++,e--)
  {
    int temp = arr[e];
    arr[e] = arr[b];
    arr[b] = temp;
  }
}

void right_shift(int *arr, int N, int k)
{ 
  int K %= N;
  reverse(arr, 0, N - K -1);
  reverse(arr, N - K,  N - 1);
  reverse(arr, 0, N - 1);
}
