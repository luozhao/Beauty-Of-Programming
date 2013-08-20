/*
  1
*/

int Fibonacci(int i)
{
  if(n <= 0)
  {
    return 0;
  } 
  else if (n == 1)
  {
    return 1;     
  } 
  else
  {
    return Fibonnacci(n-1) + Fibonnacci(n-2);
  }        
}

/*
  有没有更加优化的解法呢
*/
