#include<stdio.h>
#include<string.h>

int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int res[50]={0};
int tmpw[50]={0};
int weight[50]={0};

void addres()
{
    int i,carry=0;
    for(i=0;i<50;i++)
    {
        res[i]+=(weight[i]+carry);
        if(res[i]>9)
        {
            res[i]-=10;
            carry=1;
        }
        else carry=0;
    }
}

void addweight()
{
    int i,carry=0,tmp[50];
    for(i=0;i<50;i++)
    {
        weight[i]+=(tmpw[i]+carry);
        if(weight[i]>9)
        {
            weight[i]-=10;
            carry=1;
        }
        else carry=0;
    }
}

int main()
{
    char input[1000]={'\0'};
    scanf("%s",input);
    int tmp,cnt,i,num[100]={0};
    for(i=strlen(input)-1,tmp=1,cnt=0;i>=0;i--)
    {
        if(input[i]==',')
        {
            tmp=1;
            cnt++;
        }
        else
        {
            num[cnt]+=tmp*(input[i]-'0');
            tmp*=10;
        }
    }
    weight[0]=1;

    for(i=0;i<=cnt;i++)
    {
        int j;
        for(j=0;j<num[i];j++) addres();
        for(j=0;j<50;j++) tmpw[j]=weight[j];
        for(j=0;j<prime[i]-1;j++) addweight();   
    }

    for(i=49;res[i]==0;i--);
    for(;i>=0;i--) printf("%d",res[i]);
    return 0;
}