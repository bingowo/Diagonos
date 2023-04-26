#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct{char s[100001];int zong;int len;char s1[100001];int s2[100001];}chuan;

int cmp(const void*a1,const void*a2)
{
    chuan a=*(chuan*)a1;
    chuan b=*(chuan*)a2;
    return a.len-b.len;
    
}

int main()
{
    int n,flag=0,p;
    scanf("%d\n",&n);
    chuan*a;
    a=(chuan*)malloc(n*sizeof(chuan));
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i].s);
        a[i].len=strlen(a[i].s);
        a[i].s1[0]=a[i].s[0];
        for(int t=0;t<100001;t++)
        a[i].s2[t]=1;//初始化
        int k,l,j;
        for(k=1,l=1,j=0;k<a[i].len;k++)
       { 
          
           if(a[i].s[k]!=a[i].s[k-1]) {a[i].s1[l]=a[i].s[k];l++;j++;}
           else a[i].s2[j]++;
           
       }
    }//输入,l为不同字母个数
    for(p=1;p<n;p++)
    if(strcmp(a[p].s1,a[p-1].s1)!=0) break;
    if(p==n) flag=1;//flag=1代表可以实现
    if(flag==0) printf("-1");
    if(flag==1)
    {
       int min=1000000;
      for(int r=0;r<n;r++)
        {for(int f=0;f<n;f++)
          for(int e=0;e<l;e++)
          a[r].zong+=abs(a[r].s2[e]-a[f].s2[e];
          min=(min>a[r].zong)?a[r].zong:min;}
          
       printf("%d",min);   
    }
       
       
    
    
    return 0;
}