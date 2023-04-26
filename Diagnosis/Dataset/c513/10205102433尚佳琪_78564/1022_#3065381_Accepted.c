#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char *s,*s2;
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
    node *email;
    email=(node *)malloc(sizeof(node)*n);
    for(int i=0;i<n;i++)
    {
        char *p1;
        char q1[1000001];
        scanf("%s",q1);
        int len=strlen(q1);
        p1=(char *)malloc(sizeof(char)*(len+1));
        strcpy(p1,q1);
        email[i].s=p1;

        char *p2;
        p2=(char *)malloc(sizeof(char)*(len+1));

        char q2[1000001];
        int j=0;
        while(q1[j]!='@')j++;
        j++;
        int k=0;
        for(;j<len;j++)
        {
            q2[k++]=q1[j];
        }
        q2[k]='\0';
        strcpy(p2,q2);
        email[i].s2=p2;
    }
    qsort(email,n,sizeof(email[0]),cmp);
    for(int i=0;i<n;i++)
        printf("%s\n",email[i].s);
    return 0;
}
