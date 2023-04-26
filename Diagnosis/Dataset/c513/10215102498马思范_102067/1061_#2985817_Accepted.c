#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct A{char s[20];long long int number;}XX;

long long int zhuanhuan(char *p,int len)
{
    char *p1=p;
    int digit=0;
    int len1=len;
    int a[129];
    long long int sum=0;
    int o=1;
    for (int j=0;j<128;j++) {a[j]=-1;}
    while(len)
    {
        if(len==len1)
        {
            a[*p]=1;
        }
        else if(a[*p]==-1)
        {
            a[*p]=digit;
            digit++;
            o++;
        }
        if(digit==1)
        {
            digit++;
        }
        p++;
        len--;
    }
    if(o==1)
    {
        o++;
    }
    while(len1)
    {
        sum=sum*o+a[*p1];
        p1++;
        len1--;
    }
    return sum;
}

int cmp(const void* a,const void *b)
{
    XX*p1=(XX*)a;
    XX*p2=(XX*)b;
    if(p1->number<p2->number)
    {
        return -1;
    }
    else if(p1->number>p2->number)
    {
        return 1;
    }
    else
        return strcmp(p1->s,p2->s);
}

int main()
{
    int count;
    scanf("%d\n",&count);
    XX Z[10010];
    for(int i=0;i<count;i++)
    {
        char S[20];
        gets(S);
        strcpy(Z[i].s,S);
        char *p=S;
        int len=strlen(S);
        Z[i].number=zhuanhuan(p,len);
    }
    qsort(Z,count,sizeof(Z[0]),cmp);
    for(int i=0;i<count-1;i++)
    {
        printf("%s\n",Z[i].s);
    }
    printf("%s",Z[count-1].s);
}