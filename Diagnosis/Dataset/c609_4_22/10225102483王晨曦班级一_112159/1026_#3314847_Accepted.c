#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char a[30];
    int dif;
} literal;

int getdif(literal m)
{
    int cnt=0,alpha[26]={0};
    for(int i=0;i<strlen(m.a);i++)
    {
        if(alpha[m.a[i]-'A']==0) cnt++;
        alpha[m.a[i]-'A']++;
    }
    return cnt;
}

int cmp(const void *q1,const void *q2)
{
    literal *p1=(literal *)q1;
    literal *p2=(literal *)q2;

    if(p1->dif==p2->dif)
        return strcmp(p1->a,p2->a);
    else return p2->dif-p1->dif;
}

int main()
{
    int T;
    scanf("%d",&T);

    int cnt;
    for(cnt=0; cnt<T; cnt++)
    {
        literal str[108]= {0};

        int n;
        scanf("%d",&n);

        for(int j=1; j<n+1; j++)
            scanf("%s",str[j].a);

        for(int i=1;i<n+1;i++)
            str[i].dif=getdif(str[i]);

        qsort(str+1,n,sizeof(str[1]),cmp);

        printf("case #%d:\n",cnt);
        for(int i=1;i<n+1;i++)
            printf("%s\n",str[i].a);
        }
    return 0;
}
