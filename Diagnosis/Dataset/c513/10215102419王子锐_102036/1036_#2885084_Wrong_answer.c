#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef long long LL;
typedef unsigned long long ULL;

typedef struct { long long int x, y; } Point;

int cmp(const void *a,const void *b)
{ Point p1=*(Point*)a,p2=*(Point*)b; 
ULL disgit1=(ULL)llabs(p1.x)+(ULL)llabs(p1.y),disgit2=(ULL)llabs(p2.x)+(ULL)llabs(p2.y);
if (disgit1>disgit2) return -1; 
else if (disgit1<disgit2) return 1; 
else if (p1.x>p2.x) return 1; 
else if (p1.x<p2.x) return -1; 
else if (p1.y>p2.y) return 1; 
else if (p1.y<p2.y) return -1; 
else return 0;
}


int main()
{Point a[N]; int n,i; scanf("%d",&n);
for (i=0;i<n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
qsort(a,n,sizeof(a[0]),cmp);
int ax=abs(a[0].x-a[1].x);
int ay=abs(a[0].y-a[1].y);
printf("%d",ax+ay); printf("\n");
return 0;
    
}