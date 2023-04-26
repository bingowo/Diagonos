#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
const int ABO[4][4][4]=

{1,0,0,1,  1,1,1,0,  1,1,1,1,  1,0,0,1,

1,1,1,0,   1,1,1,0,   1,1,1,0,  1,0,1,0,

 1,1,1,1,  1,1,1,0,    0,0,1,1,  0,0,1,1,

1,0,0,1,   1,0,1,0,    0,0,1,1,  0,0,0,1};
const int Rh[2][2][2]=

{ 1,1,  1,1,

  1,1,  0,1};
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
int main()
{
    int ans_ABO[4];
    int ans_Rh[2];
    int father,mother,child;
    int T;
    scanf("%d",&T);
    for(int w=0;w<T;w++)
    {
        char sf[10];
        char sm[10];
        char sc[10];
    scanf("%s",sf);
    if(!strcmp(sf,"A+")) father=1;
    else if(!strcmp(sf,"B+")) father=3;
    else if(!strcmp(sf,"B-")) father=-3;
    else if(!strcmp(sf,"AB+")) father=2;
    else if(!strcmp(sf,"AB-")) father=-2;
    else if(!strcmp(sf,"O+")) father=4;
    else if(!strcmp(sf,"O-")) father=-4;
    else if(!strcmp(sf,"?")) father=0;
    scanf("%s",sm);
    if(!strcmp(sm,"A+")) mother=1;
    else if(!strcmp(sm,"B+")) mother=3;
    else if(!strcmp(sm,"B-")) mother=-3;
    else if(!strcmp(sm,"AB+")) mother=2;
    else if(!strcmp(sm,"AB-")) mother=-2;
    else if(!strcmp(sm,"O+")) mother=4;
    else if(!strcmp(sm,"O-")) mother=-4;
    else if(!strcmp(sm,"?")) mother=0;
    scanf("%s",sc);
    if(!strcmp(sc,"A+")) child=1;
    else if(!strcmp(sc,"B+")) child=3;
    else if(!strcmp(sc,"B-")) child=-3;
    else if(!strcmp(sc,"AB+")) child=2;
    else if(!strcmp(sc,"AB-")) child=-2;
    else if(!strcmp(sc,"O+")) child=4;
    else if(!strcmp(sc,"O-")) child=-4;
    else if(!strcmp(sc,"?")) child=0;
        if(father==0)
        {
            int m1,c1,m2,c2;
            if(mother>0)
            {
                m1=mother-1;
                m2=0;
            }
            else
            {
                m1=-mother-1;
                m2=1;
            }
            if(child>0)
            {
                c1=child-1;
                c2=0;
            }
            else
            {
                c1=-child-1;
                c2=1;
            }
            for(int i=0;i<4;i++)
            {
                ans_ABO[i]=ABO[i][m1][c1];
            }
            for(int i=0;i<2;i++)
            {
                ans_Rh[i]=Rh[i][m2][c2];
            }
        }
        if(mother==0)
        {
            int f1,c1,f2,c2;
            if(father>0)
            {
                f1=father-1;
                f2=0;
            }
            else
            {
                f1=-father-1;
                f2=1;
            }
            if(child>0)
            {
                c1=child-1;
                c2=0;
            }
            else
            {
                c1=-child-1;
                c2=1;
            }
            for(int i=0;i<4;i++)
            {
                ans_ABO[i]=ABO[f1][i][c1];
            }
            for(int i=0;i<2;i++)
            {
                ans_Rh[i]=Rh[f2][i][c2];
            }
        }
        if(child==0)
        {
            int m1,f1,m2,f2;
            if(mother>0)
            {
                m1=mother-1;
                m2=0;
            }
            else
            {
                m1=-mother-1;
                m2=1;
            }
            if(father>0)
            {
                f1=father-1;
                f2=0;
            }
            else
            {
                f1=-father-1;
                f2=1;
            }
            for(int i=0;i<4;i++)
            {
                ans_ABO[i]=ABO[f1][m1][i];
            }
            for(int i=0;i<2;i++)
            {
                ans_Rh[i]=Rh[f2][m2][i];
            }
        }
        void write()
{
    int ABO=0,Rh=0;
        for(int i=0;i<4;i++)
            ABO+=ans_ABO[i];
        for(int i=0;i<2;i++)
            Rh+=ans_Rh[i];
        if(ABO*Rh==0) printf("impossible");
        if(ABO*Rh==1)
        {
            for(int i=0;i<4;i++)
                if(ans_ABO[i])
                   for(int j=0;j<2;j++)
                      if(ans_Rh[j])
                       {
                        if(j==0) print(i+1,0);
                        else print(-i-1,0);
                       }
        }
        if(ABO*Rh>1)
        {
            int cnt=0;
            for(int i=0; i<4; i++)
                if(ans_ABO[i])
                    for(int j=0; j<2; j++)
                        if(ans_Rh[j])
                        {
                            cnt++;
                            if(j==0) print(i+1,cnt);
                            else print(-i-1,cnt);
                        }
            printf("}");
        }
        printf(" ");
}
if(father==0)
{
    write();
    printf("%s ",sm);
    printf("%s ",sc);
}
if(mother==0)
{
    printf("%s ",sf);
    write();
    printf("%s ",sc);
}
if(child==0)
{
    printf("%s ",sf);
    printf("%s ",sm);
    write();
}
        printf("\n");
    }
}
