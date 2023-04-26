#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[1100];
int cmp(const void* p,const void* q)
{
    int* a=(int*)p;
    int* b=(int*)q;
    return(*a - *b);
}
int main()
{
    int n,s;
    scanf("%d %d",&n,&s);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int j=1;
    while(s>0)
    {
         while(s>=j && a[0]<a[j])
         {
                  for(int i=0;i<j;i++)
                {
                    a[i]++;s--;
                }
         }
         if(s==0) break;
         else if(s<j)
         {
             while(a[j]==a[j+1]) j++;
             j++;break;
         }
         j++;
    }
    if(s==0) printf("%d",a[j]);
    else if(s>0)
    {
        printf("%d+",a[0]);
        printf("%d/%d",s,j);
    }
    return 0;
}

