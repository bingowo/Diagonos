#include <stdio.h>
int main()
{
   int T;
   scanf("%d", &T);
    for (int cas=0;cas<T;cas++)
    {
       unsigned int n;
       scanf("%u", &n);
       int maxLen = 1, len = 1;
       unsigned int bit = n & 1;
       n >>= 1;
       while (n > 0) 
       {
       unsigned int nextBit = n & 1;
       if (nextBit != bit) 
       {
           len++;
           if (len > maxLen) {maxLen = len;}
       }
        else {len = 1;}
       bit = nextBit;
       n >>= 1;
        }
    printf("case #%d:\n%d\n",cas,maxLen);
    }
   return 0;
}