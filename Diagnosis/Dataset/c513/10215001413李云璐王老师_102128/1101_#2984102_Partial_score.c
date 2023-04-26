#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int read()
{
    char s[20];
    scanf("%s",s);
    int flag=0;
    if(strcmp(s,"A+")==0) flag=1;
    else if(strcmp(s,"A-")==0) flag=2;
    else if(strcmp(s,"AB+")==0) flag=3;
    else if(strcmp(s,"AB-")==0) flag=4;
    else if(strcmp(s,"B+")==0) flag=5;
    else if(strcmp(s,"B-")==0) flag=6;
    else if(strcmp(s,"O+")==0) flag=7;
    else if(strcmp(s,"O-")==0) flag=8;
    else if(strcmp(s,"?")==0) flag=0;
    return flag;

}

void print(int x,int type)
{
    if(type==1) printf("{");
    else if(type>1) printf(",");
    if(x==1) printf("A+");
    if(x==2) printf("A-");
    if(x==3) printf("AB+");
    if(x==4) printf("AB-");
    if(x==5) printf("B+");
    if(x==6) printf("B-");
    if(x==7) printf("O+");
    if(x==8) printf("O-");

}

void write(int*ans)
{
    int abo=0;
    for(int i=0;i<8;i++)
        abo+=ans[i];
    if(abo==0) printf("impossible");
    else if(abo==1)
    {
        for(int i=0;i<8;i++)
        {
            if(ans[i]!=0)
            {
                if(i==0) printf("A+");
                if(i==1) printf("A-");
                if(i==2) printf("AB+");
                if(i==3) printf("AB-");
                if(i==4) printf("B+");
                if(i==5) printf("B-");
                if(i==6) printf("O+");
                if(i==7) printf("O-");
                break;
            }
        }
    }
    else
    {
        int cnt=0;
        for(int i=0;i<8;i++)
            if(ans[i]!=0)
        {
            cnt++;
            print(i+1,cnt);

        }
        printf("}");
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    const int a[8][8][8]=
    {
        1,1,0,0,0,0,1,1, 1,1,0,0,0,0,1,1, 1,1,1,1,1,1,0,0, 1,1,1,1,1,1,0,0, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,0,0,0,0,1,1, 1,1,0,0,0,0,1,1,//妈妈是A+
        1,1,0,0,0,0,1,1, 0,1,0,0,0,0,0,1, 1,1,1,1,1,1,0,0, 0,1,0,1,0,1,0,0, 1,1,1,1,1,1,1,1, 0,1,0,1,0,1,0,1, 1,1,0,0,0,0,1,1, 0,1,0,0,0,0,0,1,//妈妈是A-
        1,1,1,1,1,1,0,0, 1,1,1,1,1,1,0,0, 1,1,1,1,1,1,0,0, 1,1,1,1,1,1,0,0, 1,1,1,1,1,1,0,0, 1,1,1,1,1,1,0,0, 1,1,1,1,0,0,0,0, 1,1,1,1,0,0,0,0,//妈妈是AB+
        1,1,1,1,1,1,0,0, 0,1,0,1,0,1,0,0, 1,1,1,1,1,1,0,0, 0,1,0,1,0,1,0,0, 1,1,1,1,1,1,0,0, 0,1,0,1,0,1,0,0, 1,1,1,1,0,0,0,0, 0,1,0,1,0,0,0,0,//妈妈是AB-
        1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1, 1,1,1,1,1,1,0,0, 1,1,1,1,1,1,0,0, 0,0,1,1,0,0,1,1, 0,0,1,1,0,0,1,1, 0,0,1,1,0,0,1,1, 0,0,1,1,0,0,1,1,//妈妈是B+
        1,1,1,1,1,1,1,1, 0,1,0,1,0,1,0,1, 1,1,1,1,1,1,0,0, 0,1,0,1,0,1,0,0, 0,0,1,1,0,0,1,1, 0,0,0,1,0,0,0,1, 0,0,1,1,0,0,1,1, 0,0,0,1,0,0,0,1,//妈妈是B-
        1,1,0,0,0,0,1,1, 1,1,0,0,0,0,1,1, 0,0,1,1,0,0,1,1, 0,0,1,1,0,0,1,1, 1,1,1,1,0,0,0,0, 1,1,1,1,0,0,0,0, 0,0,0,0,0,0,1,1, 0,0,0,0,0,0,1,1,//妈妈是O+
        1,1,0,0,0,0,1,1, 0,1,0,0,0,0,0,1, 0,0,1,1,0,0,1,1, 0,0,0,1,0,0,0,1, 1,1,1,1,0,0,0,0, 0,1,0,1,0,0,0,0, 0,0,0,0,0,0,1,1, 0,0,0,0,0,0,0,1};//妈妈是O-


    int ans[8];
    for(int i=0;i<n;i++)
    {
        int father,mother,child;
        mother=read();father=read();child=read();
        if(father==0)
        {
           int m1,c1;
           m1=mother-1;
           c1=child-1;
           for(int i=0;i<8;i++)
                {ans[i]=a[m1][i][c1];}
        }
        if(mother==0)
        {
            int f1,c1;
            f1=father-1;
            c1=child-1;
            for(int i=0;i<8;i++)
                ans[i]=a[i][f1][c1];
        }
        if(child==0)
        {
            int f1,m1;
            f1=father-1;
            m1=mother-1;
            for(int i=0;i<8;i++)
                {ans[i]=a[m1][f1][i];}
        }
        if(mother!=0) print(mother,0);
        else write(ans);
        printf(" ");
        if(father!=0) print(father,0);
        else write(ans);
        printf(" ");
        if(child!=0) print(child,0);
        else write(ans);
        printf("\n");


    }
    return 0;
}
