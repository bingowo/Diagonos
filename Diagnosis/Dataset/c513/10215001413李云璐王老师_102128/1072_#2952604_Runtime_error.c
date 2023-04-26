#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

long long int min(long long int a,long long int b)
{
    if(a>=b) return b;
    else return a;
}

long long int q(long long int x,long long int y)
{
    long long int a;
    a=fabs(x)+fabs(y);
    return a;
}

int cmp(const void*a1,const void*a2)
{
    long long int a=*(long long int*)a1;
    long long int b=*(long long int *)a2;
    if(a>=b) return 1;
    else return -1;

}
void chuli(long long x,long long y,int bu,char*a)
{
    long long int yi=pow(2,bu-1);
    long long int b[3]={0};
    b[0]=q(x-yi,y);
    b[1]=q(x+yi,y);
    b[2]=q(x,y+yi);
    b[3]=q(x,y-yi);
    qsort(b,4,sizeof(b[0]),cmp);
    long long int zmin=b[0];

    if(zmin==q(x-yi,y)) a[bu-1]='E';
    if(zmin==q(x+yi,y)) a[bu-1]='W';
    if(zmin==q(x,y+yi)) a[bu-1]='S';
    if(zmin==q(x,y-yi)) a[bu-1]='N';
}


int main()
{
    long long int x,y,bu;
    scanf("%lld%lld",&x,&y);
    if(q(x,y)==0) printf("0");
    else if(q(x,y)%2==0) printf("-1");
    else
    {
        for(int i=0;i<64;i++)
        if(q(x,y)>=pow(2,i)&&q(x,y)<=pow(2,i+1)) {bu=i+1;break;}
        printf("%lld\n",bu);
        char a[bu+1];
        a[bu]='\0';
        while(bu!=0)
        {
            chuli(x,y,bu,a);
            if(a[bu-1]=='E') x-=pow(2,bu-1);
            if(a[bu-1]=='W') x+=pow(2,bu-1);
            if(a[bu-1]=='S') y+=pow(2,bu-1);
            if(a[bu-1]=='N') y-=pow(2,bu-1);
            bu--;


        }
        printf("%s\n",a);
    }
    return 0;
}
