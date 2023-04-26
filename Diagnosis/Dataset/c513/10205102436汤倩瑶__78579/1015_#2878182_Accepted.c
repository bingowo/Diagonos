#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
int sush[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97};
  int T;
  scanf("%d",&T);
  char s1[100],s2[100];
  for(int i=0;i<T;i++)
  {
      scanf("%s%s",s1,s2);
      int l1=strlen(s1);
      int l2=strlen(s2);
   int a[30]={0};
   int b[30]={0};
   int cnt1=0,cnt2=0;
   int tmp=0;
for(int j=0;j<=l1;j++)
{

    if(s1[j]>='0'&&s1[j]<='9')tmp=tmp*10+s1[j]-'0';
    else{
        a[cnt1++]=tmp;tmp=0;
    }

}
for(int j=0;j<cnt1/2;j++){tmp=a[j];a[j]=a[cnt1-j-1];a[cnt1-j-1]=tmp;}
//for(int j=0;j<cnt1;j++)printf("%d ",a[j]);
tmp=0;
for(int j=0;j<=l2;j++)
{

    if(s2[j]>='0'&&s2[j]<='9')tmp=tmp*10+s2[j]-'0';
    else{
        b[cnt2++]=tmp;tmp=0;
    }

}
for(int j=0;j<cnt2/2;j++){tmp=b[j];b[j]=b[cnt2-j-1];b[cnt2-j-1]=tmp;}
//for(int j=0;j<cnt2;j++)printf("%d ",b[j]);
//  printf("%s\n%s\n",s1,s2);
int c[30]={0};
int cnt=0;
int carry=0;
int max=cnt1>cnt2?cnt1:cnt2;
for(int j=0;j<max;j++)
{
    c[cnt++]=(carry+a[j]+b[j])%sush[j];
    carry=(carry+a[j]+b[j])/sush[j];
}
if(carry>0)
{c[max]=carry;cnt=max+1;}
printf("case #%d:\n",i);
for(int j=cnt-1;j>0;j--)printf("%d,",c[j]);
printf("%d\n",c[0]);

  }

}
