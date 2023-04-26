#include <stdio.h>
#include <string.h>
const int ABO[4][4][4]={1,0,0,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,1,1,0,0,1,1,1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1};
int ans[4];
int r()
{
    char s[10];
    int f=0;
    scanf("%s",s);
    if(strcmp(s,"A")==0)
        f=1;
    else if(strcmp(s,"B")==0)
        f=3;
    else if(strcmp(s,"AB")==0)
        f=2;
    else if(strcmp(s,"O")==0)
        f=4;
    else if(strcmp(s,"?")==0)
        f=0;
    return f;
}
void p1(int x,int t)
{
    if(t==1)
        printf("{");
    else if(t>1)
        printf(",");
    if(x==1)
        printf("A");
    else if(x==2)
        printf("AB");
    else if(x==3)
        printf("B");
    else if(x==4)
        printf("O");
}
void p2()
{
    int x,i,s;
    x=0;
    for(i=0;i<4;i++)
        x=x+ans[i];
    if(x==0)
        printf("impossible");
    else{
        s=0;
        for(i=0;i<4;i++)
            if(ans[i]==1){
                s++;
                p1(i+1,s);
            }
        printf("}");
    }
}
int main()
{
    int f,m,c,x,y,i;
    f=r();
    m=r();
    c=r();
    if(f==0){
        x=m-1;
        y=c-1;
        for(i=0;i<4;i++)
            ans[i]=ABO[i][x][y];
    }
    else if(m==0){
        x=f-1;
        y=c-1;
        for(i=0;i<4;i++)
            ans[i]=ABO[x][i][y];
    }
    else if(c==0){
        x=f-1;
        y=m-1;
        for(i=0;i<4;i++)
            ans[i]=ABO[x][y][i];
    }
    if(f!=0)
        p1(f,0);
    else p2();
    printf(" ");
    if(m!=0)
        p1(m,0);
    else p2();
    printf(" ");
    if(c!=0)
        p1(c,0);
    else p2();
    printf("\n");
    return 0;
}