/*
   写一个程序，求出两个数字的最大公约数，如果两个数都很大，有什么简单的算法吗？
*/

/*
  解法1：辗转相除法
  f(x,y) = f(y,y%x)
*/

int gcd(int x, int y)
{
  return (!y) ? x : gcd(y,x%y);
}

/*
  上述解法1，虽然简单，但是对于大数据的处理性能上不行，
  如果一个数能同时整除x和y，则比能够同时整除x-y和y;而同时能整除x-y和y的数也必能同时整除x和y，
  即x和y的公约数与x-y和y的公约数相同，其最大公约数也是相同的，即f(x,y) = f(x-y,y),那么就可以不在需要进行
  大整数的取模运算；而转换成简单的多大整数的减法
  f(42,30) = f(30,f12) = f(12,18) = f(18,12) = f(12,6) = f(6,6)= f(6,0)=  6
  具体代码如下：
*/

BigInt gcd(BigInt x, BigInt y)
{
  if(x < y)
    return gcd(y,x);
  if(y == 0)
    return x;
  return gcd(x - y, y);
}


/*
   解法3：取p=2，
   若x,y均为偶数，f(x,y) = 2*f(x/2,y/2) = 2*f(x>>1,y>>1)
   若x为偶数,y为奇数，f(x,y) = f(x/2,y) = f(x>>1,y)
   若x为奇数，y为偶数，f(x,y) = f(x,y/2) = f(x,y>>1)
   若x,y均为奇数，f(x,y) = f(x,x-y)
   那么在f(x,y)=f(x.x-y)之后，x-y一定是偶数，下一步一定会有除以2的操作
*/
BigInt gcd(BigInt x, BigInt y)
{
   if(x < y)
      return gcd(y,x);
   if(y == 0)
      return x;
   else
   {
      if(IsEven(x))
      {
         if(IsEven(y))
            return (gcd(x>>1,y>>1)<<1);
         else
            return gcd(x>>1,y);
      }
      else 
      {
         if(IsEven(y))
            return gcd(x,y>>1);
         else
            return gcd(y,x-y);
      }
   }
}

