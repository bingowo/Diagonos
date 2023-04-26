#include <stdio.h>
#include <stdlib.h>
#include<string.h>

const int ABO[4][4][4]=
{1,0,0,1,  1,1,1,0,  1,1,1,1,  1,0,0,1,
1,1,1,0,   1,1,1,0,   1,1,1,0,  1,0,1,0,
 1,1,1,1,  1,1,1,0,    0,0,1,1,  0,0,1,1,
1,0,0,1,   1,0,1,0,    0,0,1,1,  0,0,0,1};

int ans_ABO[4];

int read()
{
    char s[10];
    scanf("%s",s);
    int flag=0;
    if(!strcmp(s,"?")) flag=0;
    else if(!strcmp(s,"A")) flag=1;
    else if(!strcmp(s,"AB")) flag=2;
    else if(!strcmp(s,"B")) flag=3;
    else if(!strcmp(s,"O")) flag=4;
    return flag;
}

void print(int t,int x)
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
}

int main()
{
    int dad,mom,kid;
    dad=read();
    mom=read();
    kid=read();
    if(dad!=0) print(0,dad);
    else write();
    printf(" ");
    if(mom!=0) print(0,mom);
    else write();
    printf(" ");
    if(kid!=0) print(0,kid);
    printf("\n");
    return 0;
}
