#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct{char s[1000001];int zong;int len;char s1[1000001];int s2[1000001];}chuan;



int main()
{
    int n,flag=0,p;
    scanf("%d\n",&n);
    chuan*a;
    a=(chuan*)malloc(n*sizeof(chuan));
     int k,l,j;
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i].s);
        a[i].len=strlen(a[i].s);
        a[i].s1[0]=a[i].s[0];
        for(int t=0;t<1000001;t++)
        a[i].s2[t]=1;//初始化
       
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
       int min1=1000000;
      for(int r=0;r<n;r++)
        {for(int f=0;f<n;f++)
          for(int e=0;e<l;e++)
          a[r].zong+=abs(a[r].s2[e]-a[f].s2[e]);
          min1=(min1>a[r].zong)?a[r].zong:min1;}
      
          
       printf("%d",min1);   
    }
       
       
    
    
    return 0;
}