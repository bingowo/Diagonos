#include<stdio.h>
#include<string.h>
#include<stdlib.h>

float A[30];

float zhuanhuan(char p1)
{
    if(p1>='a')
    {
        return A[p1-97];
    }
    else
    {
        return A[p1-65];
    }
}

int cmp(const void*a,const void *b)
{
    char *p1=(char *)a;
    char *p2=(char *)b;
    if(zhuanhuan(*p1)<zhuanhuan(*p2))
    {
        return 1;
    }
    else if(zhuanhuan(*p1)>zhuanhuan(*p2))
    {
        return -1;
    }
    else if(*p1<*p2)
    {
        return 1;
    }
    else return -1;
}

int main()
{
    int count,count1;
    char S[101];
    int len;
    scanf("%d",&count);
    count1=count;
    while(count--)
    {

        for(int i=0;i<26;i++)
        {
            scanf("%f",&A[i]);
        }
        scanf("%s",S);
        len=strlen(S);
        qsort(S,len,sizeof(S[0]),cmp);
        printf("case #%d:\n",count1-count-1);
        printf("%s\n",S);
    }

}
