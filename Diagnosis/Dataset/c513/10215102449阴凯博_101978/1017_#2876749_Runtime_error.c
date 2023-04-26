#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[128]={0};



typedef struct
{
    int value;
    int sign;
} NUM;

NUM* trans (char* s)
{
    a['I']=1; a['V']=5; a['X']=10; a['L']=50; a['C']=100; a['D']=500; a['M']=1000;
    NUM *arr=(NUM*)malloc(strlen(s)*sizeof(NUM));
    int m,j;
    for (m=0,j=0;m<strlen(s);m++,j++)
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
    return arr;
}



int main()
{
    int i,m,j;
    int a[128]; for (i=0;i<128;i++) a[i]=-1;
    a['I']=1; a['V']=5; a['X']=10; a['L']=50; a['C']=100; a['D']=500; a['M']=1000;
    char s[100]; long long b=1;
    long long result=0,result1=0;
    scanf("%s",s);
    char s1[100]={0},s2[100]={0};
    if (s[0]!='(')
    {
        for (i=0;s[i]!='(';i++) s1[i]=s[i];
        if (i<strlen(s))
        {
            for (i;s[i]=='(';i++) b*=1000;
            for (i,j=0;s[i]!=')';i++,j++) s2[j]=s[i];
        }
        NUM *arr1=NULL;    arr1=trans(s1);
        NUM *arr2=NULL;    arr2=trans(s2);
        for (j=0;j<strlen(s1);j++)
            result+=arr1[j].value*arr1[j].sign;
        for (j=0;j<strlen(s2);j++)
            result1+=arr2[j].value*arr2[j].sign;
        free(arr1);free(arr2);

        printf("%lld\n",result<result1*b?result1*b-result:result1*b+result);

    }
    else
    {
        for (i=0;s[i]=='(';i++) b*=1000;
        for (i,j=0;s[i]!=')';i++,j++) s1[j]=s[i];
        for (i;s[i]==')';i++) ;
        if (i<strlen(s))
        {
            for (i,j=0;i<strlen(s);i++,j++) s2[j]=s[i];
        }
        NUM *arr1=NULL;    arr1=trans(s1);
        NUM *arr2=NULL;    arr2=trans(s2);
        for (j=0;j<strlen(s1);j++)
            result+=arr1[j].value*arr1[j].sign;
        for (j=0;j<strlen(s2);j++)
            result1+=arr2[j].value*arr2[j].sign;
        free(arr1);free(arr2);
        printf("%lld\n",result*b<result1?result1-result*b:result1+result*b);

    }

    return 0;
}
