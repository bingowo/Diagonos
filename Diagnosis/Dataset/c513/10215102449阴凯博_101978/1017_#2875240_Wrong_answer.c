#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int value;
    int sign;
} NUM;

int main()
{
    int i,m,j;
    int a[128]; for (i=0;i<128;i++) a[i]=-1;
    a['I']=1; a['V']=5; a['X']=10; a['L']=50; a['C']=100; a['D']=500; a['M']=1000;
    char s[100]; long long b=1;
    scanf("%s",s);
    for (i=0;s[i]=='(';i++) b*=1000;
    long long result=0;
    NUM *arr=(NUM*)malloc(strlen(s)*sizeof(NUM));
    for (m=i,j=0;m<strlen(s)-i;m++,j++)
    {
        arr[j].value=a[s[m]];
        if (j==0)
        {
            if (a[s[m+1]]>a[s[m]] && (s[m]=='I' || s[m]=='C' || s[m]=='X')&& a[s[m+1]]/a[s[m]]<=10)
                arr[j].sign=-1;
            else arr[j].sign=1;
        }
        else
        {
            if (a[s[m]]>a[s[m-1]] &&( s[m-1]=='I' || s[m-1]=='C' || s[m-1]=='X' )&& a[s[m]]/a[s[m-1]]<=10)
                {arr[j-1].sign=-1;arr[j].sign=1;}
            else {arr[j-1].sign=1;arr[j].sign=1;}
            if (a[s[m]]<=a[s[m-1]])
                arr[j].sign=1;
        }
    }
    for (m=i,j=0;m<strlen(s)-i;m++,j++)
        result+=arr[j].value*arr[j].sign;
    result*=b;

    printf("%lld\n",result);
    return 0;
}
