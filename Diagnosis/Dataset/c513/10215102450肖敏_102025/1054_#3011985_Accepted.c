#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int split(char *buf,char **dst)
{
    int n=0;
    char *p=strtok(buf," ");
    while(p)
    {
        strcpy(*dst++,p);
        n++;
        p= strtok(NULL," ");
    }
    return n;
}

char **allocate(int n,int m)
{
    char **b=(char **) malloc(n*sizeof (char *));
    for(int i=0;i<n;i++)
    {
        b[i]=(char *) malloc(m*sizeof (char));
        memset(b[i],0,m);
    }
    return b;
}
void freen(char **p,int n)
{
    for(int i=0;i<n;i++)
        free(p[i]);
    free(p);
}

void printlank(int n)
{
    for(int i=0;i<n;i++)
    {
        printf(" ");
    }
}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int M;
        scanf("%d",&M);
        getchar();
        char line[10000];
        gets(line);
        char **dst= allocate(10000,10000);
        int w= split(line,dst);
        int p=0,c=0,l=0;
        printf("case #%d:\n",i);
        for(;c<w;c++)
        {
            int wc= strlen(dst[c]);
            int n_blk=c-p-1;
            if(l+wc+n_blk+1>M)
            {
                int t_blk=M-l;
                for(;p<c;p++)
                {
                    printf("%s",dst[p]);
                    if(p<c-1)
                    {
                        printlank(t_blk/(c-p-1));
                        t_blk-=t_blk/(c-p-1);
                    }
                    else
                        printf("\n");
                }
                l=0;
            }
            l+=wc;
        }
        for(;p<c;p++)
        {
            printf("%s",dst[p]);
            if(p!=c-1)
                printf(" ");
        }
        printf("\n");
        freen(dst,10000);
    }
    return 0;
}
