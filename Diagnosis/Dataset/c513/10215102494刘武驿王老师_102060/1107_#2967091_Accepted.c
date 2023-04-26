#include<stdio.h>
int main()
{
int light[4][4]={0};
int map[4][4]={0};
int i,j;
int t,k;
scanf("%d",&t);
for(k=0;k<t;k++){
printf("case #%d:\n",k);
for(i=1;i<=3;i++)
for(j=1;j<=3;j++)
scanf("%d",&map[i][j]);
for(i=1;i<=3;i++)
for(j=1;j<=3;j++)
light[i][j]=map[i][j]+map[i+1][j]+map[i][j+1]+map[i-1][j]+map[i][j-1];
for(i=1;i<=3;i++)
for(j=1;j<=3;j++){
if(light[i][j]%2==0)
printf("1%c",j==3?'\n':' ');
else printf("0%c",j==3?'\n':' ');
}
}
}
