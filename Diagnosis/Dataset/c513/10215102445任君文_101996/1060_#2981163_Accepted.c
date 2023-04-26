#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define M 100
int is_number(char x)
{
    if((x>='0')&&(x<='9'))
    {
        return 1;
    }
    else 
     return 0;
}
int main()
{
    int i,j,k;
    int n=0,L=0,MAX=0;
    int temp;
    char str[M]={0};
    scanf("%s",&str);
    L=strlen(str);
    for(i=0;i<L;i++)
    {
        if(is_number(str[i])==1)
        {
            temp=str[i]-'0';
            if(temp==0)
            {
                if(n!=0)
                {
                    n++;
                }
            }
            else if(temp!=0)
            {
                n++;
            }
            if(i==L-1)
            {
                if(n>MAX)
                {
                    MAX=n;
                    n=0;
                }
            }
        }
        else if(is_number(str[i])==0)
        {
            if(n>MAX)
            {
                MAX=n;
            }
            n=0;
        }
    }
    printf("%d\n",MAX);
    return 0;   
}