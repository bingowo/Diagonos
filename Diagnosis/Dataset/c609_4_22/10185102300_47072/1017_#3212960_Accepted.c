#include <stdio.h>
#include <stdlib.h>

//int find(int *a, int n,int b){  int i; for(i=0;i<n;i++) if (a[i]==b) return 1; return 0; }
int cmpA(const void* e1,const void* e2) { return *(int*)e1-*(int*)e2; }
int cmpD(const void* e1,const void* e2) { return -1*cmpA(e1,e2); }
int main()
{ char AD;  int a[1000],i,n=0,b; scanf("%c",&AD);
   while (scanf("%d",a+n)!=EOF) n++;
   qsort(a,n,sizeof(a[0]),AD=='A'?cmpA:cmpD);
   for(i=0;i<n;i++)
       if (i==n-1) printf("%d\n",a[i]);
       else if (a[i]!=a[i+1]) printf("%d ",a[i]);

   return 0;
}