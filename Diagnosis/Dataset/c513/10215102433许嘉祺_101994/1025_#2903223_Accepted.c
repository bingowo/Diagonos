#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct string
{
    char s[21];
    int n;
} a[100];
int cmp(const void*a,const void*b){
    int n1=((struct string*)a)->n,n2=((struct string*)b)->n;
    char*p1=((struct string*)a)->s,*p2=((struct string*)b)->s;
    if (n1!=n2) return n2-n1;
    else {return strcmp(p1,p2);}
}
int main()
{
    int t,t1;
    scanf("%d",&t);
    char s1[21];
    int num=0;
    int s2[255];
    for(int i=0; i<t; i++)
    {
        scanf("%d",&t1);
        for (int k=0; k<t1; k++)
        {
            memset(s2,0,sizeof(s2));
            scanf("%s",s1);
            strcpy(a[num++].s,s1);
            int count=0;
            for (int j=0; j<strlen(s1); j++)
            {
                if (s2[s1[j]]==0)
                {
                    s2[s1[j]]++;
                    count++;
                }
            }
            a[num-1].n=count;
        }
        qsort(a,t1,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for (int j=0;j<t1;j++)
            printf("%s\n",a[j].s);
        num=0;
    }
    return 0;
}