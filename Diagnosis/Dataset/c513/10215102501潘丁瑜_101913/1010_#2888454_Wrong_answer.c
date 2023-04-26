#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void division(int x,int n);
int main()
{
    char num[501]={0};
    char temp[5];
    int i=0, j, n=10;
    long long int len;
    scanf("%s",num);
    printf("0001");
    len = strlen(num);
    division(len,n);
    while(num[i] != 0 )
    {
        for(j=0;j<3;j++)
        {
            temp[j] = num[i++];
            if(num[i] == 0) break;
        }
        if(len == 2) n = 7;
        else if (len == 1) n = 4;
        division(atoi(temp),n);
    }
    return 0;
}
void division(int x,int n)
{
    int i=0;
    if(n-- > 0)
    {
        division(x/2,n);
        printf("%d",x%2);
    }
}