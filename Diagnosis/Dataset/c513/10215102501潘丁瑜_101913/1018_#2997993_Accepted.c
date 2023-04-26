#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
int dex[1000];

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

void carry(int *t)
{
	int len;
	for(len=999;len>0;len--)
	{
		t[len-1] += t[len] /10;
		t[len] %= 10;
	}
}

void mult(int *t, int p)
{
	int len;
	for(len=999;len>=0;len--)
		t[len] = t[len]*p;
	carry(t);

}

void add(int *dex,int *N)
{
	int len;
	for(len=999;len>=0;len--)
		dex[len] += N[len];
	carry(dex);
}


int main()
{
    char number[1000]={0};
    int N[26]={0};
    //unsigned long long int r=0;
    scanf("%s",number);
    Readnumber(number,N);
    int i=25,j;
    int t[1000]={0};
    int t_N[1000]={0};
    //unsigned long long int t;
    while(i>0)
    {
        if(i+1>25)
        	//t=1;
        	t[999] =1;
        else //t=t*prime[i+1];
        	mult(t,prime[i+1]);
        for(j=999;j>=0;j--)
            t_N[j]=t[j];
        mult(t_N,N[i]);
        add(dex,t_N);
        //r=r+(N[i] * t);
        i--;
    }
    i=0;
    while(dex[i] == 0 && i<999) i++;
    for(i;i<=999;i++)
    {
    	printf("%d",dex[i]);
	}

    return 0;
}