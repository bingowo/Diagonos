/*
	分别读入实部和虚部：
	只有实部（实部有负数和正数）
	只有虚部（虚部正负）
	既有实部又有虚部 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
long long atoll(const char*str)
{
    long long flag=1;
    long long result=0;
    if(*str == '0'){
    	return 0;
	}
    if(*str=='-')
    {
        flag=-1;
        str++;
    }
    while(*str!='\0')
    {
        if(*str>='0' && *str<='9')
        {
            result=result*10+(*str-'0');
        }
        else
        {
            break;
        }
        str++;
    }
    

    return result*flag?result*flag:1*flag;
}
void solveinput(char *x,long long *y)
{
    long long qr=0;
    long long qi=0;
    if(strchr(x,'i')==0)
    {
        //只有实部
        qr=atoll(x);
        //printf("%lld",qr);
    }
    else
    {
        //有虚部
        if(strchr(x,'+')!='\0')
        {
            //有实部且虚部为正
            if(strchr(x,'-')!=0)
            {
                //实部为负；
                char *res=strchr(x,'+');
                res++;
                qr=atoll(x);
                qi=atoll(res);
            }
            else
            {
                //实部为正
                char *res=strchr(x,'+');
                qr=atoll(x);
                res++;
                qi=atoll(res);
            }
        }
        else
        {
            //没有实部或虚部为负
            if(strchr(x,'-')=='\0')
            {
                //没有实部且虚部为正
                qi=atoll(x);
            }
            else if(strchr(x,'-')==strrchr(x,'-'))
            {
                if(x[0]!='-')
                {
                    //有实部为正且虚部为负
                    char* res=strrchr(x,'-');
                    qr=atoll(x);
                    qi=atoll(res);
                }
                else qi=atoll(x);
            }
            else
            {
                //有虚部和实部且虚部为负.实部为正
                char* res=strrchr(x,'-');
                qr=atoll(x);
                qi=atoll(res);
            }

        }
    }
    y[0]=qr;
    y[1]=qi;
}
int jugr(long long a,long long b)
{
    int r;
    if(a%2==0 && b%2==0)
    {
        r=0;
    }
    else if((a%2==1 && b%2==1)||(a%2==-1 && b%2==-1)||(a%2==1 && b%2==-1)||(a%2==-1 && b%2==1))
    {
        r=0;
    }
    else
    {
        r=1;
    }
    return r;
}
int main()
{
    char input[1000]= {'\0'};
    scanf("%s",input);
    long long y[2];
    solveinput(input,y);
   // printf("%lld\n%lld\n",y[0],y[1]);
    int res[10000]= {'\0'};
    int i=0;
    long long a,b,qr,qi;
    a=y[0];
    b=y[1];
    qr=a,qi=b;
    int r=0;
    while(a!=0||b!=0)
    {
        r=jugr(a,b);
        res[i++]=r;
        qi=-(a+b-r)/2;
        qr=-(a-b-r)/2;
        a=qr;
        b=qi;
    }
    i=i-1;
    for(; i>-1; i--)
    {
        printf("%d",res[i]);
    }
}