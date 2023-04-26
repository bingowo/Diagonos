#include <stdio.h>
#include <string.h>

const int primes[26] = {97,91,89,83,79,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};

void readnumber(char s[],int num[])
{
    char *p=s;
    int temp=0,index=0;
    while (*p) {
        if(*p==','){
            num[index++] = temp;
            temp=0;
        }
        else{
            temp=temp*10+(*p - '0');
        }
        p++;
    }
    num[index++] = temp;
    memmove(num+(26-index), num, sizeof(int)*index);
    memset(num, -1, sizeof(int)*(26-index));
}

void add(int num1[],int num2[],int sum[])
{
    for (int i=25; num1[i]!=-1||num2[i]!=-1||sum[i]!=-1; i--) {
        if(num1[i]==-1){
            num1[i]=0;
        }
        if(num2[i]==-1){
            num2[i]=0;
        }
        if(sum[i]==-1){
            sum[i]=0;
        }
        sum[i]=num1[i]+num2[i]+sum[i];
        if(sum[i]>=primes[i]){
            sum[i]-=primes[i];
            sum[i-1]= 1;
        }
    }
}

void printsum(int s[])
{
    for (int i=0;i<26;i++) {
        if(s[i]!=-1){
            printf("%d%c",s[i],i==25?'\n':',');
        }
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        char s1[100],s2[100];
        int num1[26],num2[26],sum[26];
        memset(num1, -1, sizeof(sum));
        memset(num2, -1, sizeof(sum));
        memset(sum, -1, sizeof(sum));
        scanf("%s %s",s1,s2);
        readnumber(s1, num1);
        readnumber(s2, num2);
        add(num1,num2,sum);
        printf("case #%d:\n",i);
        printsum(sum);
    }
    return 0;
}
