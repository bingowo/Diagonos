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
    int i,j,T,sum,num1;
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
        if(strlen(a)*8%num1==0)
        {
            sum=strlen(a)*8/num1;
            num1=1;
        }
        printf("%d/%d", num1,sum);
    }

    return 0;
}
