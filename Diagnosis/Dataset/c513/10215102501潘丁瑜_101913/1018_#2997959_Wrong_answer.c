#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};

void Readnumber(char number[],int N[])
{
    int l;
    l=strlen(number)-1;
    int i =25;
    while(l >= 0)
    {
        int temp=1;
        while(l >= 0 && number[l] != ',')
        {
            N[i] += (number[l] - '0')*temp;
            temp*=10;
            l--;
        }
        i--,l--;
    }
}


int main()
{
    char number[1000]={0};
    int N[26]={0};
    unsigned long long int r=0;
    scanf("%s",number);
    Readnumber(number,N);
    int i=25;
    unsigned long long int t;
    while(i>0)
    {
        if(i+1>25)
        	t=1;
        else t=t*prime[i+1];
        r=r+(N[i] * t);
        i--;
    }
    printf("%lld",r);
    return 0;
}