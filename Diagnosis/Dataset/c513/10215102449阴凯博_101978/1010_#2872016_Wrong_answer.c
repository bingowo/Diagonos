#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 570
 const char s1[11]="0000000000";

void reverse(char* s)
{
    int i,j;
    char tmp;
    for (i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
    }
}

typedef struct
{
    char str[4];
    char bin[11];
    int num;
} TRI;

int ctoi (char* s)
{
    int i,r=0;
    for (i=0;i<strlen(s);i++)
    {
        r=r*10+s[i]-'0';
    }
    return r;
}


int main()
{
    char s[MAX];
    scanf("%s",s);
    int len=strlen(s),n=strlen(s)/3,r=strlen(s)%3;
    int i=0,j=0,m;
    TRI* arr1=(TRI*)calloc(n,sizeof(TRI));
    while (i<len-r)
    {
        if (i!=0 && i%3==0)
            j++;
        arr1[j].str[i%3]=s[i];
        i++;
    }
    for (i=0;i<n;i++)
    {
        arr1[i].num=ctoi(arr1[i].str);
        for (j=0;j<10;j++)
        {

            arr1[i].bin[j]=s1[j];
            if (arr1[i].num)
            {
                arr1[i].num/=2;
                arr1[i].bin[j]=arr1[i].num%2+'0';
            }

        }
        reverse(arr1[i].bin);
    }
    if (r==1)
    {
        char s2[5]="0000";
        char s3[4]={0};
        char s4[11]="0000000000";
        for (i=3*n,j=0;i<len;i++,j++)
        s3[j]=s[i];
        int a=ctoi(s3);
        for (i=0;a;i++)
        {
            s2[i]=a%2+'0';
            a/=2;
        }
        for (i=0;len;i++)
        {
            s4[i]=len%2+'0';
            len/=2;
        }
        reverse(s2);
        reverse(s4);
        printf("0001");
        printf("%s",s4);
        for (i=0;i<n;i++)
        {
            printf("%s",arr1[i].bin);
        }
        printf("%s\n",s2);
    }
    if (r==2)
    {
        char s2[8]="0000000";
        char s3[4]={0};
        char s4[11]="0000000000";
        for (i=3*n,j=0;i<len;i++,j++)
        s3[j]=s[i];
        int a=ctoi(s3);
        for (i=0;a;i++)
        {
            s2[i]=a%2+'0';
            a/=2;
        }
        for (i=0;len;i++)
        {
            s4[i]=len%2+'0';
            len/=2;
        }
        reverse(s4);
        reverse(s2);
        printf("0001");
        printf("%s",s4);
        for (i=0;i<n;i++)
        {
            printf("%s",arr1[i].bin);
        }
        printf("%s\n",s2);
    }
    if (r==0)
    {
        printf("0001");
        char s4[11]="0000000000";
        for (i=0;len;i++)
        {
            s4[i]=len%2+'0';
            len/=2;
        }
        reverse(s4);
        for (i=0;i<n;i++)
        {
            printf("%s",arr1[i].bin);
        }
        printf("\n");
    }

    return 0;
}
