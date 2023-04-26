#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct{char s[100001];int zong;int len;char s1[100001];int s2[100001];}chuan;



int main()
{
    int n,flag=0,p;
    scanf("%d\n",&n);
    chuan*a;
    a=(chuan*)malloc(n*sizeof(chuan));
     int k,l,j,mid[100001]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i].s);
        a[i].len=strlen(a[i].s);
        a[i].s1[0]=a[i].s[0];
        for(int t=0;t<100001;t++)
        a[i].s2[t]=1;//初始化
       
        for(k=1,l=1,j=0;k<a[i].len;k++)
       { 
          
           if(a[i].s[k]!=a[i].s[k-1]) {a[i].s1[l]=a[i].s[k];l++;j++;}
           else a[i].s2[j]++;
           
       }
    }//输入,l为不同字母个数
    for(int w=0;w<l;w++)
    {
        for(int q=0;q<n;q++)
        mid[w]+=a[q].s2[w];
        mid[w]/=n;
       
    }
    
        
    for(p=1;p<n;p++)
    if(strcmp(a[p].s1,a[p-1].s1)!=0) break;
    if(p==n) flag=1;//flag=1代表可以实现
    if(flag==0) printf("-1");
    if(flag==1)
    {
       int min1=1000000,min2=0,min;
      for(int r=0;r<n;r++)
        {for(int f=0;f<n;f++)
          for(int e=0;e<l;e++)
          a[r].zong+=abs(a[r].s2[e]-a[f].s2[e]);
          min1=(min1>a[r].zong)?a[r].zong:min1;}
      
      for(int f=0;f<l;f++)
      for(int e=0;e>n;e++)
      min2+=abs(mid[f]-a[e].s2[f]);
      min=(min1>min2)?min2:min1;
      
          
       printf("%d",min);   
    }
       
       
    
    
    return 0;
}