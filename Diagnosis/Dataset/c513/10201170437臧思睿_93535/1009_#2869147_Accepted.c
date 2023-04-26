#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long int ll;

int gcd(int a,int b)
{
    if(a>b)
    {
        int temp=a;
        a=b;
        b=temp;//keep a<b
    }
    if(b%a==0){return a;}
    else{return(gcd(a,b%a));}
}

int operate(char x)
{
    int r=0;
    for(int i=0;i<8;i++)
    {
        if(x&1==1){r++;}
        x>>=1;
    }
    return r;
}

int main()
{
    int i=0,j,t=0,T;
    scanf("%d",&T);
    char c=getchar();//read '\n'
    while(t++<T)
    {
        char s[130];
        memset(s,0,sizeof(char));
        while((s[i++]=getchar())!='\n');
        s[i-1]='\0';
        int sum=0;
        for(i=0;i<strlen(s);i++)
        {
            sum+=operate(s[i]);
        }
        j=gcd(sum,strlen(s)*8);
        printf("%d/%d\n",sum/j,strlen(s)*8/j);
        i=0;
    }
}
