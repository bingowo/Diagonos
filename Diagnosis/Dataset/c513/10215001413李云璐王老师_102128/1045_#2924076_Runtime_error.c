#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct{char s[100001];int len;int zong;char s1[100001]}chuan;

int cmp(const void*a1,const void*a2)
{
    chuan a=*(chuan*)a1;
    chuan b=*(chuan*)a2;
    return a.zong-b.zong;
}

int main()
{
    int n,flag=0,p;
    scanf("%d\n",&n);
    chuan*a;
    a=(chuan*)malloc(sizeof(chuan));
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i].s);
        a[i].len=strlen(a[i].s);
        a[i].s1[0]=a[i].s[0];
        for(int k=1,l=1;k<a[i].len;k++)
        if(a[i].s[k]!=a[i].s[k-1]) {a[i].s1[l]=a[i].s[k];l++;}
    }//输入
    for(p=1;p<n;p++)
    if(strcmp(a[p].s1,a[p-1].s1)!=0) break;
    if(p==n) flag=1;//flag=1代表可以实现
    if(flag==0) printf("-1");
    if(flag==1)
    {
       int min=10000000;
       for(int k=0;k<n;k++)
       {
           
           for(int o=0;o<n;o++)
           a[k].zong+=abs(a[k].len-a[o].len);
           min=(min>a[k].zong)?a[k].zong:min;
       }
       printf("%d",min);
    }
    
    return 0;
}