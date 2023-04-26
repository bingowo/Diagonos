#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    return strcmp((char *)a,(char *)b);
}

int main()
{
    int n,N,i;
    scanf("%d\n",&N);
    for(n=0;n<N;n++)
    {
        printf("case #%d:\n",n);
        char st[201]={0},al[201]={0},ot[201]={0};
        gets(st);
        int lenst=strlen(st),j=0;
        for(i=0;i<lenst;i++)
        {
            if(st[i]<='Z'&&st[i]>='A')
            {
                al[j]=st[i];
                j++;
            }
            else
            {
                ot[i]=st[i];
            }
        }
        int lenal=strlen(al);
        if(lenal>1)
            qsort(al,lenal,sizeof(al[0]),cmp);
        for(i=0,j=0;i<lenst;i++)
        {
            if(ot[i]==0)
            {
                ot[i]=al[j];
                j++;
            }
        }
        for(i=0;i<lenst;i++)
        {
            printf("%c",ot[i]);
        }
        printf("\n");
    }
    return 0;
}
