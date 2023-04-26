#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Abo;
    int Rh;
}xuexing;

xuexing read()
{
    char s[10];
    scanf("%s",s);
    xuexing re;
    if(!strcmp(s,"A+")) {re.Abo=1;re.Rh=1;}
    else if(!strcmp(s,"A-")) {re.Abo=1;re.Rh=0;}
    else if(!strcmp(s,"AB-")) {re.Abo=2;re.Rh=0;}
    else if(!strcmp(s,"AB+")) {re.Abo=2;re.Rh=1;}
    else if(!strcmp(s,"B+")) {re.Abo=3;re.Rh=1;}
    else if(!strcmp(s,"B-")) {re.Abo=3;re.Rh=0;}
    else if(!strcmp(s,"O-")) {re.Abo=4;re.Rh=0;}
    else if(!strcmp(s,"O+")) {re.Abo=4;re.Rh=1;}
    else if(!strcmp(s,"?"))  {re.Abo=0;re.Rh=0;}
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

void write(int ans[],int zhengfu[])
{
    int abo=0,i,sum;
    for(i=0;i<4;i++)
    {
        abo+=ans[i];
    }
    sum=zhengfu[0]+zhengfu[1];
    if(abo==0) printf("impossible");
    else if((abo==1)&&(sum==1))
    {
        //printf("sum=1\n");
        for(i=0;i<4;i++)
        {
            if(ans[i])
            {
                if(zhengfu[0])
                {
                    print(i+1,0);
                    printf("+");
                }
                if(zhengfu[1])
                {
                    print(i+1,0);
                    printf("-");
                }
            }
        }
    }
    else
    {
        //printf("sum!=1\n");
        int co=0;
        for(i=0;i<4;i++)
        {
            if(ans[i])
            {
                if(zhengfu[0])
                {
                    co++;
                    print(i+1,co);
                    printf("+");
                }
                if(zhengfu[1])
                {
                    co++;
                    print(i+1,co);
                    printf("-");
                }
            }
        }
        printf("}");
    }
}

int main()
{
    int ABO[4][4][4]={1,0,0,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1};
    int RH[2][2][2]={1,1,1,1,1,1,0,1};
    int N,j;
    scanf("%d",&N);
    for(j=0;j<N;j++)
    {
        xuexing dad,mom,kid;
        int zhengfu[2]={0},ans[4]={0},i;
        dad=read();
        mom=read();
        kid=read();
        xuexing f,m,c;
        //printf("test:\ndad=%d  %d\nmom=%d  %d\nkid=%d  %d\n",dad.Abo,dad.Rh,mom.Abo,mom.Rh,kid.Abo,kid.Rh);
        if(dad.Abo==0)
        {
            m.Abo=mom.Abo-1;
            c.Abo=kid.Abo-1;
            m.Rh=1-mom.Rh;
            c.Rh=1-kid.Rh;
            for(i=0;i<4;i++)
            {
                ans[i]=ABO[i][m.Abo][c.Abo];
            }
            for(i=0;i<2;i++)
            {
                zhengfu[i]=RH[i][m.Rh][c.Rh];
            }
        }

        if(mom.Abo==0)
        {
            f.Abo=dad.Abo-1;
            c.Abo=kid.Abo-1;
            f.Rh=1-dad.Rh;
            c.Rh=1-kid.Rh;
            for(i=0;i<4;i++)
            {
                ans[i]=ABO[f.Abo][i][c.Abo];
            }
            for(i=0;i<2;i++)
            {
                zhengfu[i]=RH[f.Rh][i][c.Rh];
            }
        }

        if(kid.Abo==0)
        {
            f.Abo=dad.Abo-1;
            m.Abo=mom.Abo-1;
            m.Rh=1-mom.Rh;
            f.Rh=1-dad.Rh;
            for(i=0;i<4;i++)
            {
                ans[i]=ABO[f.Abo][m.Abo][i];
            }
            for(i=0;i<2;i++)
            {
                zhengfu[i]=RH[f.Rh][m.Rh][i];
            }
        }

        /*printf("test2:\nans=");
        printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
        printf("zhengfu=%d %d\n",zhengfu[0],zhengfu[1]);*/

        if(!dad.Abo) write(ans,zhengfu);
        else {print(dad.Abo,0); if(dad.Rh) printf("+");else printf("-");}
        printf(" ");
        if(!mom.Abo) write(ans,zhengfu);
        else {print(mom.Abo,0); if(mom.Rh) printf("+");else printf("-");}
        printf(" ");
        if(!kid.Abo) write(ans,zhengfu);
        else {print(kid.Abo,0); if(kid.Rh) printf("+");else printf("-");}
        printf("\n");

    }


    return  0;
}
