#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int num_1;
int num_0;
int set[8];
void binary(char x){
    char m=x;
    for(int i=0;i<8;i++)
        {
            set[i]=(bool)(x&0x80);
            x=x<<1;
        }
    for(int i=0;i<8;i++)
    {
        if(set[i]==1) num_1++;
        else num_0++;
    }
}
int gcd(int a,int b)
{
    return a?gcd(b%a,a):b;
}
int main(){

    int n;
    scanf("%d",&n);
    char jk;
    jk=getchar();
    for(int i=0;i<n;i++)
    {
        num_1=0;
        num_0=0;
        char s[150];
        gets(s);
        for(int J=0;J<strlen(s);J++)
        {
            binary(s[J]);

        }
        int x=gcd(num_1,num_0+num_1);
        printf("%d/%d\n",num_1/x,(num_0+num_1)/x);
    }
    return 0;
}