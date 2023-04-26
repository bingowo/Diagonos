#include <stdio.h>
#include <stdlib.h>
int m,A[500];
int ord(int n)
{  int i;
    for(i=0;i<m;i++) if (A[i]==n) return i;
    return m;
}

int cmp(const void* e1,const void* e2)
{ int n1 = *(int*)e1, n2 = *(int*)e2, delta;
   if (ord(n1)==m&&ord(n2)==m) return n1-n2;
   return ord(n1)-ord(n2);
}

int main()
{  int n,B[500],i;
    for (scanf("%d",&m),i=0;i<m;i++) scanf("%d",A+i);
    for (scanf("%d",&n),i=0;i<n;i++) scanf("%d",B+i);
    qsort(B,n,sizeof(B[0]),cmp);
    for (i=0;i<n;i++) printf("%d%c",B[i],i<n-1?' ':'\n');

    return 0;
}