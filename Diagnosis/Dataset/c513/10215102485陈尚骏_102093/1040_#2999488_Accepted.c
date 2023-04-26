#include <stdio.h>
#include <stdlib.h>
#include<string.h>

const int ABO[4][4][4]=
{1,0,0,1,  1,1,1,0,  1,1,1,1,  1,0,0,1,
1,1,1,0,   1,1,1,0,   1,1,1,0,  1,0,1,0,
 1,1,1,1,  1,1,1,0,    0,0,1,1,  0,0,1,1,
1,0,0,1,   1,0,1,0,    0,0,1,1,  0,0,0,1};

int ans_ABO[4]={0};

int read()
{
    char s[10]={};
    scanf("%s",s);
    int flag=0;
    if(!strcmp(s,"?")) flag=0;
    else if(!strcmp(s,"A")) flag=1;
    else if(!strcmp(s,"AB")) flag=2;
    else if(!strcmp(s,"B")) flag=3;
    else if(!strcmp(s,"O")) flag=4;
    return flag;
}

void print(int x,int t)
{
    if(t==1) printf("{");
    else if(t>1) printf(",");
    if(x==1) printf("A");
    else if(x==2) printf("AB");
    else if(x==3) printf("B");
    else if(x==4) printf("O");
}

void write()
{
    int ABO=0;
    for(int i=0;i<4;i++)
    {
        ABO=ABO+ans_ABO[i];
    }
    if(ABO==0) printf("impossible");
    else
    {
        int cnt=0;
        for(int i=0;i<4;i++)
        {
            if(ans_ABO[i])
            {
                cnt++;
                print(i+1,cnt);
            }
        }
        printf("}");
    }
    return ;
}

int main()
{
    int dad,mom,kid;
    dad=read();
    mom=read();
    kid=read();
    if(dad==0)
    {
        int m1,k1;
        m1=mom-1;
        k1=kid-1;
        for(int i=0;i<4;i++)
        {
            ans_ABO[i]=ABO[i][m1][k1];
        }
    }
    else if(mom==0)
    {
        int d1,k1;
        d1=dad-1;
        k1=kid-1;
        for(int i=0;i<4;i++)
        {
            ans_ABO[i]=ABO[d1][i][k1];
        }
    }
    else if(kid==0)
    {
        int d1,m1;
        d1=dad-1;
        m1=mom-1;
        for(int i=0;i<4;i++)
        {
            ans_ABO[i]=ABO[d1][m1][i];
        }
    }
    if(dad!=0) print(dad,0);
    else write();
    printf(" ");
    if(mom!=0) print(mom,0);
    else write();
    printf(" ");
    if(kid!=0) print(kid,0);
    else write();
    printf("\n");
    return 0;
}
