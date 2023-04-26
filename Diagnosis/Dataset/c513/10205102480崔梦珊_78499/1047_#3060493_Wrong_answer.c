#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        int alpha[400]={0};
        printf("case #%d:\n",i);
        char c;
        int temp=0;
        char rem='\0';
        while((c=getchar())!='\n')
        {
            if(rem=='\0')
            {
                alpha[c]=1;
                temp=1;
            }
            if(alpha[c]==0&&rem!='\0')
            {
                if(temp<=255)
                {
                    printf("%d%c",temp,rem);
                }
                else
                {
                    printf("255%c",rem);
                    printf("%d%c",temp-255,rem);
                }
                alpha[rem]=0;
                alpha[c]=1;
                temp=1;
            }
            if(alpha[c]==1&&rem==c)
            {
                temp++;
            }
            rem=c;

        }
        printf("%d%c",temp,rem);
        printf("\n");
    }
}
