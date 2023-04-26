#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 60
double pwr(int n)
{
    double result=1.0;
    for (int i=0;i<n;i++)
    {
        result=result/8;
    }
    return result;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int arr[MAX]={0};
        char s[MAX]={0};
        scanf("%s",s);
        int j,k;
        for (j=0;s[j]!='.';j++); j++;
        for (j,k=0;j<strlen(s);j++,k++)
        {
            arr[k]=s[j]-'0';
        }
        double result=0.0;
        for (j=0;j<k;j++)
        {
            result=result+arr[j]*pwr(j+1);
        }
        printf("%.45g\n",result);
    }

    return 0;
}