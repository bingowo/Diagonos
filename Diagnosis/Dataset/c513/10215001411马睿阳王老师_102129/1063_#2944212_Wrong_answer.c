#include <stdio.h>



long long int min(long long int x,long long int y)
{ 
  if(x%y==0) return x*4;
  else return x*4+min(y,x%y);
}
int main()
{ long long int x,y,v;
  scanf("%lld %lld",&x,&y);
  v=min(x,y);
 printf("%lld",v);
 return 0;

}
