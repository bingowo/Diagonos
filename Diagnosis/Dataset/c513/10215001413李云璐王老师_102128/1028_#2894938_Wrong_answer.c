#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void sort(int*s,int count)
    {
        int compare(const void*a1,const void*a2)
        {
            int a=*(int*)a1;
            int b=*(int*)a2;
            return a-b;
        }
        qsort(s,count,sizeof(int),compare);
    }
int main()
{
    char c;
    scanf("%c",&c);
    int a[1001]={0};
    int b,count=0;
    while(scanf("%d",&b)!=EOF)
    {   
        if(a[b]==0) {a[b]=1;count++;}
    }
    int d[count+1];
    for(int k=0,i=0;k<1001;k++)
    {
        if(a[k]!=0) {d[i]=k;i++;}
    }
    sort(d,count);
    for(int l=0;l<count;l++)
    printf("%d",d[l]);
    return 0;
    
}