#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void atob(int a,int ret[])
{
    int i,b;
    for(i=0;i<10;i++) ret[i]=0;
    for(i=0;a!=0;i++)
    {
        b=a%2;
        ret[i]=b;
        a/=2;
    }
}
int main()
{
    char s[505];int sum[200][3],i,j,l,fl,flag=0; int ret[10];
    for(i=0;i<504;i++) s[i]='-1';
    scanf("%s",s);
    l=strlen(s);atob(l,ret);printf("0001");
    for(i=0;i<10;i++) printf("%d",ret[9-i]);
    for(i=0;i<200;i++) for(j=0;j<3;j++) sum[i][j]=-1;
    for(i=0,j=0;(s[i+3]!=EOF)&&s[i+3]!='-1';i+=3,j++)
    {
        sum[j][0]=s[i]-'0';
        sum[j][1]=s[i+1]-'0';
        sum[j][2]=s[i+2]-'0';
    }
    fl=j-1;
    for(i=3*fl;i<l;i++) {sum[j][i-3*fl]=s[3*fl-1+i-3*fl]-'0';flag+=1;}
    int SUM[200];
    for(i=0;i<fl;i++) SUM[i]=sum[i][2]+10*sum[i][1]+100*sum[i][0];
    if(flag==1) SUM[flag]=sum[fl][0];
    if(flag==2) SUM[flag]=sum[fl][0]*10+sum[fl][1];
    for(i=0;i<fl;i++)
    {
        atob(SUM[i],ret);
        for(j=0;j<10;j++) printf("%d",ret[9-j]);
    }
    if(flag==1)
    {
        atob(SUM[fl],ret);
        for(i=0;i<4;i++) printf("%d",ret[3-i]);
    }
    else if(flag==2)
   {
        atob(SUM[fl],ret);
        for(i=0;i<7;i++) printf("%d",ret[6-i]);
   }
   else if(flag==3)
    {
        atob(SUM[i],ret);
        for(j=0;j<10;j++) printf("%d",ret[9-j]);
   }
   else if(flag==0) {int W=(s[0]-'0')*100+(s[1]-'0')*10+(s[2]-'0');atob(W,ret);for(j=0;j<10;j++) printf("%d",ret[9-j]);}
   return 0;
}

