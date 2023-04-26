#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{int n;
scanf("%d",&n);
for(int i=0;i<n;i++)
{printf("case #%d:\n",i);
int c[10]={0};
char a['Z']={0};
char b[21];
scanf("%s",b);
for(int k=0;k<strlen(b);k++)
{a[b[k]]++;}
c[0]=a['Z'];
c[8]=a['G'];
c[4]=a['U'];
c[2]=a['W'];
c[6]=a['X'];
c[3]=a['H']-a['G'];
c[7]=a['S']-a['X'];
c[1]=a['O']-a['W']-a['U']-a['Z'];
c[9]=(a['N']-c[1]-c[7])/2;
c[5]=a['F']-c[4];
for(int j=0;j<10;j++)
{for(int m=0;m<c[j];m++)
{printf("%d",j);}}
printf("\n");
}
}
