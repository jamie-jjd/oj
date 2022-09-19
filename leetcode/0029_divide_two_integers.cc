class Solution
{
public:
  int divide (int dividend, int divisor)
  {
    int quotient {};
    if (divisor == (1 << 31))
    {
      return (dividend == (1 << 31));
    }
    if (dividend == (1 << 31))
    {
      if (divisor == -1)
      {
        return 0x7FFF'FFFF;
      }
      if (divisor < 0)
      {
        dividend -= divisor;
        ++quotient;
      }
      else
      {
        dividend += divisor;
        --quotient;
      }
    }
    if (dividend)
    {
      int sign {(dividend < 0) ^ (divisor < 0)};
      if (dividend < 0)
      {
        dividend = (dividend ^ 0xFFFF'FFFF) + 1;
      }
      if (divisor < 0)
      {
        divisor = (divisor ^ 0xFFFF'FFFF) + 1;
      }
      while (dividend >= divisor)
      {
        int shift {};
        while ((divisor << shift) > 0 && (divisor << shift) <= dividend)
        {
          ++shift;
        }
        --shift;
        if (sign)
        {
          quotient -= (1 << shift);
        }
        else
        {
          quotient += (1 << shift);
        }
        dividend -= (divisor << shift);
      }
    }
    return quotient;
  }
};
