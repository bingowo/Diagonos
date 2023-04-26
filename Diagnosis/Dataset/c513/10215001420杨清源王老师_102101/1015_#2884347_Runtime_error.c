#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ADD(int a[], int b[], int c[]);
void output(int a[]);
void Readnumber(char s[], int a[]);

int main()
{
    int n;
    scanf("%d",&n);
    for( int i = 0 ; i < n ; i++)
    {
        char s[100];
        int a[26] = {0}, b[26] = {0}, c[26] = {0};
        scanf("%s",s);
        Readnumber(s,a);
        scanf("%s",s);
        Readnumber(s,b);
        ADD(a, b, c);
        printf("case #%d:\n", i);
        output(c);
    }
}

void output(int a[])
{
    int i = 0;
    for(; i < 26 ; i++)
        if(a[i] != 0)
            break;
    for(; i < 25 ; i++)
        printf("%d,",a[i]);
    printf("%d",a[25]);
}

void Readnumber(char s[], int a[])
{
    int i =  0, j = 0;
    int len = strlen(s);
    for(; i < (len + 1)/2 ; i++)
        a[25 - i] = s[2 * i] - '0';
}

void ADD(int a[], int b[], int c[])
{
    int prime[26]=
    {97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    int tmp = 0;
    for( int i = 24 ; i >=1 ; i--)
    {
        tmp = c[ i + 1 ] / prime[ i + 1];
        c[i] = ( a[i] + b[i] ) % prime[i] + tmp;
    }
    c[25] = ( a[25] + b[25] ) % prime[25];
}
