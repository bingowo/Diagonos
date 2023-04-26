#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 100000

struct Mail
{
    char name[L];
    char adr[L];
};

int cmp(const void*A,const void*B)
{
    struct Mail a=*(struct Mail*)A,b=*(struct Mail*)B;
    int C=strcmp(a.adr,b.adr);
    if(C==0)C=-1*strcmp(a.name,b.name);
    return C;
}

int main()
{
    int n;scanf("%d",&n);
    char c=getchar();//'\n'
    struct Mail mail[n];

    for(int i=0;i<n;i++)
    {
        c=getchar();
        int j=0,k=0;
        while(c!='@')
        {
            mail[i].name[j]=c;j++;mail[i].name[j]=0;
            c=getchar();
        }
        c=getchar();
        while(c!='\n')
        {

            mail[i].adr[k]=c;k++;mail[i].adr[k]=0;
            c=getchar();
        }
    }

    qsort(mail,n,sizeof(struct Mail),cmp);

    for(int i=0;i<n;i++)
    {
        printf("%s@%s\n",mail[i].name,mail[i].adr);
    }
    return 0;
}
