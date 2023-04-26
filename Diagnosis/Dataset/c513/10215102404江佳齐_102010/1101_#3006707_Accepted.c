#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ans_ABO[4];//A-0;AB-1;B-2;O-3
int ans_Rh[2];//Rh+:0;Rh-:1
int read()
{
    //A-1;AB-2;B-3;O-4;
    char s[10];
    scanf("%s",s);
    int flag=0;
    if(!strcmp(s,"A+")) flag=1;
    else if(!strcmp(s,"A-")) flag=-1;
    else if(!strcmp(s,"B+")) flag=3;
    else if(!strcmp(s,"B-")) flag=-3;
    else if(!strcmp(s,"AB+")) flag=2;
    else if(!strcmp(s,"AB-")) flag=-2;
    else if(!strcmp(s,"O+")) flag=4;
    else if(!strcmp(s,"O-")) flag=-4;
    else if(!strcmp(s,"?")) flag=0;
    return flag;
}

void print(int x,int type)
{
    if(type==1) printf("{");
    else if(type>1) printf(",");
    if(x==1||x==-1) printf("A");
    if(x==2||x==-2) printf("AB");
    if(x==3||x==-3) printf("B");
    if(x==4||x==-4) printf("O");
    if(x>0) printf("+");
    else printf("-");
}

void write()
{
    int ABO=0,Rh=0,i,j;
    for(i=0;i<4;i++) ABO+=ans_ABO[i];
    for(i=0;i<2;i++) Rh+=ans_Rh[i];
    if(ABO*Rh==0) printf("impossible");
    if(ABO*Rh==1)
    {
        for(i=0;i<4;i++)
        {
            if(ans_ABO[i])
            {
                for(j=0;j<2;j++)
                {
                    if(ans_Rh[j])
                    {
                        if(j==0) print(i+1,0);
                        else print(-i-1,0);
                    }
                }
            }
        }
    }
    if(ABO*Rh>1)
    {
        int cnt=0;
        for(i=0;i<4;i++)
        {
            if(ans_ABO[i])
            {
                for(j=0;j<2;j++)
                {
                    if(ans_Rh[j])
                    {
                        cnt++;
                        if(j==0) print(i+1,cnt);
                        else print(-i-1,cnt);
                    }
                }
            }
        }
        printf("}");
    }
}

int main()
{
    //血型列表
    const int ABO[4][4][4]={1,0,0,1, 1,1,1,0, 1,1,1,1, 1,0,0,1,\
                        1,1,1,0, 1,1,1,0, 1,1,1,0, 1,0,1,0,\
                        1,1,1,1, 1,1,1,0, 0,0,1,1, 0,0,1,1,\
                        1,0,0,1, 1,0,1,0, 0,0,1,1, 0,0,0,1};
    //Rh列表
    const int Rh[2][2][2]={1,1, 1,1, 1,1, 0,1};
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int dad,mom,child;
        dad=read();mom=read();child=read();
        if(dad==0)
        {
            int m1,m2,c1,c2;
            if(mom>0)
            {
                m1=mom-1;m2=0;
            }
            else
            {
                m1=-1-mom;m2=1;
            }
            if(child>0)
            {
                c1=child-1;c2=0;
            }
            else
            {
                c1=-1-child;c2=1;
            }
            for(int j=0;j<4;j++) ans_ABO[j]=ABO[j][m1][c1];
            for(int j=0;j<2;j++) ans_Rh[j]=Rh[j][m2][c2];
        }
        if(mom==0)
        {
            int d1,d2,c1,c2;
            if(dad>0)
            {
                d1=dad-1;d2=0;
            }
            else
            {
                d1=-1-dad;d2=1;
            }
            if(child>0)
            {
                c1=child-1;c2=0;
            }
            else
            {
                c1=-1-child;c2=1;
            }
            for(int j=0;j<4;j++) ans_ABO[j]=ABO[d1][j][c1];
            for(int j=0;j<2;j++) ans_Rh[j]=Rh[d2][j][c2];
        }
        if(child==0)
        {
            int d1,d2,m1,m2;
            if(dad>0)
            {
                d1=dad-1;d2=0;
            }
            else
            {
                d1=-1-dad;d2=1;
            }
            if(mom>0)
            {
                m1=mom-1;m2=0;
            }
            else
            {
                m1=-1-mom;m2=1;
            }
            for(int j=0;j<4;j++) ans_ABO[j]=ABO[d1][m1][j];
            for(int j=0;j<2;j++) ans_Rh[j]=Rh[d2][m2][j];
        }
        if(dad!=0) print(dad,0);
        else write();
        printf(" ");
        if(mom!=0) print(mom,0);
        else write();
        printf(" ");
        if(child!=0) print(child,0);
        else write();
        printf("\n");
    }
    return 0;
}
