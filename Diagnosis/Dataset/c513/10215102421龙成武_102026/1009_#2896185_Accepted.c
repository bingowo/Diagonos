#include <stdio.h>
#include <string.h>

int numberof1(char a)
{
    int res,j;
    char i;
    res=0;
    j=1;
    for(i=0;i<8;i++)
    {
        if((a&j)!=0)
            res=res+1;
        j=j<<1;
    }
    return res;
}
int gcd(int a,int b)    //a>b
{
    int res;
    if(a%b==0)
        res=b;
    else
        res=gcd(b,a%b);
    return res;
}
void myPrint(int res)
{
    static int tim=0;
    printf("case #%d:\n", tim);
    //printf("0.");
    printf("%d\n",res);
    tim++;
}
int main()
{
    int i,j,T,sum,num1,temp;
    char a[121];
    scanf("%d",&T);
    getchar();
    for(i=0;i<T;i++)
    {
        num1=0;
        //scanf("%s",a);
        gets(a);
        sum=strlen(a)*8;
        for(j=0;j<strlen(a);j++)
        {
            num1+=numberof1(a[j]);
        }

        temp=gcd(sum,num1);
        sum/=temp;
        num1/=temp;

        if(i<T-1)
            printf("%d/%d\n", num1,sum);
        else
            printf("%d/%d",num1,sum);
    }

    return 0;
}
