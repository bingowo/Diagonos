#include <stdio.h>
#include <stdlib.h>

int read()
{
    char s[10];
    scanf("%s",s);
    int re=0;
    if(!strcmp(s,"A")) re=1;
    else if(!strcmp(s,"AB")) re=2;
    else if(!strcmp(s,"B")) re=3;
    else if(!strcmp(s,"O")) re=4;
    else if(!strcmp(s,"?")) re=0;
    else printf("wrong input\n");
    return re;
}

void print(int x,int type)
{
    if(type==1) printf("{");
    else if(type>1) printf(",");
    if(x==1) printf("A");
    if(x==2) printf("AB");
    if(x==3) printf("B");
    if(x==4) printf("O");

}

void write(int ans[])
{
    int abo=0,i;
    for(i=0;i<4;i++)
    {
        abo+=ans[i];
    }
    if(abo==0) printf("impossible");
    else
    {
        int co=0;
        for(i=0;i<4;i++)
        {
            if(ans[i])
            {
                co++;
                print(i+1,co);
            }

        }
        printf("}");
    }
}

int main()
{
    int ABO[4][4][4]={1,0,0,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1};
    int dad,mom,kid;
    dad=read();
    mom=read();
    kid=read();
    int f,m,c,ans[4]={0},i;
    if(dad==0)
    {
        m=mom-1;
        c=kid-1;
        for(i=0;i<4;i++)
        {
            ans[i]=ABO[i][m][c];
        }
    }

    if(mom==0)
    {
        f=dad-1;
        c=kid-1;
        for(i=0;i<4;i++)
        {
            ans[i]=ABO[f][i][c];
        }
    }

    if(kid==0)
    {
        f=dad-1;
        m=mom-1;
        for(i=0;i<4;i++)
        {
            ans[i]=ABO[f][m][i];
        }
    }

    if(!dad) write(ans);
    else print(dad,0);
    printf(" ");
    if(!mom) write(ans);
    else print(mom,0);
    printf(" ");
    if(!kid) write(ans);
    else print(kid,0);
    printf("\n");

    return  0;
}
