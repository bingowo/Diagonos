#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char radix[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
void changeit(int N,int R,char*res);
int main()
{
    int N,R;
    char res[40];
    memset(res,0,sizeof(res));
    scanf("%d %d",&N,&R);
    changeit(N,R,res);
    puts(res);
    return 0;
}
void changeit(int N,int R,char*res)
{
    int mod,i=0;
    char temp;
    while(!(N>0&&N<abs(R)))
    {
        if(N>0)
        {
            mod=N%R;
            N=N/R;
        }
        else
        {
            mod=N%R;
            if(mod<0)
                mod+=abs(R);
            N=(N-mod)/R;
        }
        res[i++]=radix[mod];
    }
    res[i++]=radix[N];
    res[i]=0;               //i=strlen(res)
    for(int j=0,k=i-1;j<k;j++,k--)
    {
        temp=res[j];
        res[j]=res[k];
        res[k]=temp;
    }
}
