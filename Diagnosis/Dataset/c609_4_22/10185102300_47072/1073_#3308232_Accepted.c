#include <stdio.h>
#include <math.h>
#define N 41

char* Path(long long x,long long y,char *s,int r)
{ long long d=1LL<<(r-1); const char* direction[]={"E","W","N","S"};
  if (r)
    return llabs(x)>llabs(y) ?
                     (x>0 ? strcat(Path(x-d,y,s,r-1),direction[0]) : strcat(Path(x+d,y,s,r-1),direction[1]))
                   : (y>0 ? strcat(Path(x,y-d,s,r-1),direction[2]) : strcat(Path(x,y+d,s,r-1),direction[3]));
  return s;
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