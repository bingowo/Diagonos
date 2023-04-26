#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int pow(int x,int y)
{
    int i,pai;
    pai=1;
    for(i=0;i<y;i++)
    {
        pai=pai*x;
    }
    return pai;
}
int main()
{
    char numm[64]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};
    int sum,num,len,y[808],T,i,k,m;
    char x[101];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",x);
        m=0;
        len=strlen(x);
        for(int j=0;j<len;j++)
        {
            num=x[j];
            k=7;
            while(k>=0)
            {
                y[k+m]=num%2;
                num=num/2;
                k--;
            }
            m=m+8;
        }
        int j=(8*len)%6;
        k=0;
        if(j!=0)
        {
            for(j;j<6;j++)
            {
                y[8*len+k]=0;
                k++;
            }
        }
        int flag=0,n=0;
        sum=0;
        printf("case #%d:\n",i);
        for(j=0;j<8*len+k;j++)
        {
            sum=sum+y[j]*pow(2,5-n);
            n++;
            if(n==6)
            {
                printf("%c",numm[sum]);
                sum=0;
                n=0;
                flag++;
            }
        }
        while(flag%4!=0)
        {
            printf("=");
            flag++;
        }
        printf("\n");
    }
    return 0;
}
