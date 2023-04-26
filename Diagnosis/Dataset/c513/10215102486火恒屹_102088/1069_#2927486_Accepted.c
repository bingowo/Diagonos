#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void myitoa(long long num,char *str)
{
    int i=0;
    while(num)
    {
        str[i]=num%10+'0';
        i++;
        num=num/10;
    }
    for(int i=0;i<strlen(str)/2;i++)
    {
        char temp=str[i];
        str[i]=str[strlen(str)-i-1];
        str[strlen(str)-i-1]=temp;
    }
}

long long backnum(long long num)
{
    char nums[50]={'\0'};
    myitoa(num,nums);
    for(int i=0;i<strlen(nums)/2;i++)
    {
        char temp=nums[i];
        nums[i]=nums[strlen(nums)-i-1];
        nums[strlen(nums)-i-1]=temp;
    }
    long long z=atoll(nums);
    return z;
}

int isnotpa(long long num)
{
    char nums[50]={'\0'};
    myitoa(num,nums);
    for(int i=0;i<strlen(nums)/2;i++)
    {
        if(nums[i]!=nums[strlen(nums)-i-1])
            return 1;
    }
    return 0;
}

int main()
{
    long long num;
    scanf("%lld",&num);
    int k=0;
    while(isnotpa(num))
    {
        long long bnum=backnum(num);
        num=num+bnum;
        k++;
    }
    printf("%d %lld",k,num);

}
