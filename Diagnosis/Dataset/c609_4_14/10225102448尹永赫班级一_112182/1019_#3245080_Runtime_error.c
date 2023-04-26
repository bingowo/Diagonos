#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a,const void*b)
{   int A=*(int*)a;
     int B=*(int*)b;
     int i=0,j=0;
     do{
       A=abs(A)/10;
       i+=1;
     }
     while (A!=0);
     do{
        B=abs(B)/10;
        j+=1;
     }
     while (B!=0);
     if (i!=j)
     {
         return j-i;
     }
     else
     {
         return *(int*)a-*(int*)b;
     }
}

int main(){
int k=0;
int n;
int s[100001];
while ((scanf("%d",&n))!=EOF)
{
    s[k]=n;
    k+=1;

}
qsort(s,k,sizeof(s[0]),cmp);
int q=0;
while (q<k)
{
    printf ("%d ",s[q++]);

}

       return 0;
}
