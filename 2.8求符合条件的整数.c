/*
  任意给定一个正整数N,求一个最小的正整数M(M>1),使得N*M的十进制表示形式里只含有0和1
  
  问题转化：求一个最小的正整数X,使得X的十进制表示形式里面只有1和0,并且X被N整除
*/
/*
  BigInt[i]表示模N等于i的十进制表示形式里只含1和0的最小整数.
  由于BigInt[i]可能很大,又因为它只有0和1,所以,只需要记下1的位置即可.
  比如：1001,记为(0,3) = 10^0 + 10^3.即BigInt里面每个元素是一个变长数组
  对于模N等于i的最小X,BigInt的每个元素将存储最小X在十进制中表示"1"的位置
  我们的目标就是求BigInt[0]
*/
//初始化
for(i = 0; i < N; i++)
  BigInt[i].clear();
BigInt[1].push_back(0);

for(i=1, j = 1o % N; ; i++, j = (j * 10) % N)
{
  int NoUpdate = 0;
  bool flag = false;
  if(BigInt[j].size() == 0)
  {
    BigInt[j].clear();
    BigInt[j].push_back(i);
  }
  for(k=1; k < N; k++)
  {
    if((BigInt[k].size() > 0)
        && (i > BigInt[k].size() - 1)
        && (BigInt[(k+j)%N].size()==0))
      {
        flag = true;
        BigInt[(k+j) % N] = BigInt(k);
        BigInt[(k+j) % N].push_back[i];
      }
  }
  if(flag == false)
    NoUpdate++;
  // 如果经过一个循环节都没能对BigInt进行更新,就是无解,跳出
  // 或者BigInt[0] != NULL ,已经找到解,也跳出.
  if(NoUpdate == N || BigInt[0].size > 0)
    break;
}
if(BigInt[0].size()== 0)
{
  // M not exist
}
else
{
  // Find N*M = BigInt[0];
}
