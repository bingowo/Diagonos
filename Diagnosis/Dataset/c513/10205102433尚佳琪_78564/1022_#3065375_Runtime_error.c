#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char s[1000001],s2[1000001];
}node;
int cmp(const void *a,const void *b)
{
    node m=*(node*)a;
    node n=*(node*)b;
    if(strcmp(m.s2,n.s2)!=0)
        return strcmp(m.s2,n.s2);
    else
        return strcmp(n.s,m.s);
}

int main()
{

    int n;
    scanf("%d",&n);
    node email[n];
    for(int i=0;i<n;i++)
    {
        scanf("%s",email[i].s);
        int len=strlen(email[i].s);
        int j=0;
        while(email[i].s[j]!='@')
        {
           // email[i].s1[j]=email[i].s[j];
            j++;
        }
       // email[i].s1[j]='\0';
        j++;
        int k=0;
        for(;j<len;j++)
        {
            email[i].s2[k++]=email[i].s[j];
        }
        email[i].s2[k]='\0';
    }
    qsort(email,n,sizeof(email[0]),cmp);
    for(int i=0;i<n;i++)
        printf("%s\n",email[i].s);
    return 0;
}
