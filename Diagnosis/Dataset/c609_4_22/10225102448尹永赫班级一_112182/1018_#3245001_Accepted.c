#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int main(){
int s[100001];
int n,i=0;
scanf ("%d",&n);
for (;i<n;)
{   int K;
    scanf("%d",&K);
     s[i++]=K;
}
int sz=sizeof(s)/sizeof(s[0]);
qsort(s,n,sizeof(s[0]),cmp);
int j=0;
int addup=0;
for (;j<n;)
{  
    addup=addup+s[j+1]-s[j];
    j+=2;
}
   printf ("%d",addup);
       return 0;
}

