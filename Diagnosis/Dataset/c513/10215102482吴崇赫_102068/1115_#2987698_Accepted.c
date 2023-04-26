#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 25

int cmp(const void* a,const void* b){return *(int*)a-*(int*)b;}

int main()
{
    int T,x=0;
    scanf("%d\n",&T);
    while(x<T){
        char num[N]={0};
        scanf("%s",num);
        int a[N]={0};
        for(int i=0;i<strlen(num);++i)a[i+1]=num[i]-'0';
        int min,m,len=strlen(num);
        for(int i=len-1;i>-1;--i){
            if(a[i]<a[i+1]){min=i;break;}
        }
        m=min+1;
        for(int i=len;i>=min;--i){
            if(a[i]>a[min]&&a[i]<=a[m])m=i;
        }
        int temp=a[m];a[m]=a[min];a[min]=temp;
        qsort(a+min+1,len-min,sizeof(int),cmp);
        int k=0;
        if(a[k]==0)k++;
        printf("case #%d:\n",x++);
        for(;k<=len;++k)printf("%d",a[k]);
        printf("\n");
    }
}