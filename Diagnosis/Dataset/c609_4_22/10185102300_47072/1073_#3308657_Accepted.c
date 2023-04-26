#include <stdio.h>
#include <math.h>
#include <string.h>
#define N 41

char* Path(long long x,long long y,char *s,int r)
{ long long d=1LL<<(r-1); const char  *p="E\0W\0N\0S";
  return r ? ((llabs(x)>llabs(y) ? ((x>0) ? (x-=d) : (x+=d,p+=1*2)) :
                                ((y>0) ? (y-=d,p+=2*2):(y+=d,p+=3*2))),
                      strcat(Path(x,y,s,r-1),p))
         :s;
}
int Steps(long long x, long long y)
{ long long dist=llabs(x)+llabs(y);int r=log2(dist+1)+1;
  return (!dist)?0:(dist%2)?r-((1LL<<(r-1))>=dist+1):-1;
}
int main()
{ long long x,y; char s[N+1]={0};
  int steps=(scanf("%lld%lld",&x,&y),Steps(x,y));
  printf("%d\n",steps);
  if (steps>0) printf("%s\n",Path(x,y,s,steps));
  return 0;
}