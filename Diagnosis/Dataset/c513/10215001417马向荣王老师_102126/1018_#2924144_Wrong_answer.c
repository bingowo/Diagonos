#include<stdio.h>
#include<string.h>
int main(void)
{
    int sushu[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    char s[100];
    scanf("%s",s);
    int arr[26]={0};
    int j=0,p=1;
    int len=strlen(s);
    for(int i=len-1;i>=0;i--)
    {
        if(s[i]==',')
        {
            p=1;
            j++;
        }
        else
        {
            arr[j]+=(s[i])*p;
            p*=10;
        }
    }
    long long int sum=0;
    int lens=strlen(arr);
    int di=1;
    for(int i=0;i<lens;i++)
    {
        sum+=arr[i]*di;
        di*=10;
    }
    printf("%lld",sum);
    return 0;
}