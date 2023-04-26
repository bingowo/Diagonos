#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int shu(int n)
{
  if(n<3) return 0;
  if(n==3) return 1;
  if(n==4) return 4;
  return 2*shu(n-1)+pow(2,n-3)-((n-3)>=3)?shu(n-3):0;
  
  
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1) break;
        else printf("%d\n",pow(2,n)-shu(n));
    }
    return 0;
}