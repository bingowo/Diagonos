#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int main()
{
    int T;
    scanf("%d",&T);
    char s[50];
    for(int i=0;i<T;i++)
    {
        scanf("%s",&s);
        int n=strlen(s);
        //printf("%d\n",n);
        double res=0;
        double flag=1;
        for(int j=2;j<n;j++)
        {
            flag*=0.125;
            res=(s[j]-'0')*flag+res;
            //printf("%lf %lf\n",flag,res);
            //printf("%lf\n",res);
        }
        int num=3*n;
        printf("case #%d:\n",i);
        printf("%.f\n",res);
    }
    return 0;
}*/

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char Octal[55],Decimal[155];
        scanf("%s",Octal);
        int num=0;
        int n=strlen(Octal)-1;
        for(;n!=1;--n)
        {
            int digit=Octal[n]-'0';
            int j=0;
            int temp=0;
            while(digit || j<num)
            {
                if(j<num)
                    temp=digit*10+Decimal[j]-'0';
                else
                    temp=digit*10;
                Decimal[j++]=temp/8+'0';
                digit=temp%8;
            }
            num=j;
        }
        Decimal[num]='/0';
        printf("case #%d:\n",i);
        printf("0.");
        for(int k=0;k<num;k++)
            printf("%c",Decimal[k]);
        printf("\n");
    }
    return 0;
}
