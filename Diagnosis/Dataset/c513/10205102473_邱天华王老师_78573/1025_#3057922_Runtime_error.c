#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct string0
{
    char num[101];
    int dft;
}string;
int count(string p)
{
    int s[128]={0};
    int c=0;
    for(int i=0;i<strlen(p.num);i++)
    {
        if (p.num[i] >= 0 && p.num[i] <= 127)
		{
			s[p.num[i]]++;
		}
    }
    for(int i=0;i<127;i++)
    {
        if(s[i]!=0) c++;
    }
    return c;
}
int cmp(const void* q1,const void* q2)
{
    string* p1=(string* )q1;
    string* p2=(string* )q2;
    if(p1->dft!=p2->dft)
        return (p2->dft-p1->dft);
    else  
        return (strcmp(p1->num,p2->num));
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        string str[n];
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
            scanf("%s",str[j].num);
            str[j].dft=count(str[j]);
        }
        qsort(str,n,sizeof(string),cmp);
        printf("case #%d: \n",i);
        for(int j=0;j<n;j++)
            printf("%s\n",str[j].num);
    }
    return 0;
}