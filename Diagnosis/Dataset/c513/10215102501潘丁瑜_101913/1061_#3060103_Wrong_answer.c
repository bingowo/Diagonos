#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct random
{
    char str[20];
    int num[10000];
    int sum;
};

int cmp(const void*a, const void *b)
{
    struct random *m = (struct random *)a;
    struct random *n = (struct random *)b;
    if(m->sum != n->sum)
        return m->sum-n->sum;
    else
        return strcmp(m->str,n->str);
}

int main()
{
    int n,i,j,k;
    int len;
    int bit;
    scanf("%d",&n);
    struct random R[n];
    for(i=0;i<n;i++)
    {
        scanf("%s",R[i].str);
        int exist[200]={0};
        memset(R[i].num, 0, sizeof(char) * 10000);
        R[i].sum=0;
        len=strlen(R[i].str);
        //to smallR
        int ch;
        bit=1;
        k=1;
        for(j=0;j<len;j++)
        {
            ch=R[i].str[j];
            if(k>=2)
            {
                if(exist[ch] == 0)
                {
                    k++;
                    bit++;
                }
            }
            if(k==0 && j>0)
            {
                if(exist[ch]==0)
                {
                    k=2;
                    bit++;
                }
            }
            else if(k==1 && j>0)
            {
                if(exist[ch]==0)
                {
                    k=0;
                    bit++;
                }
            }
            exist[ch]=1;
            R[i].num[j]=k;
        }
        //to sum
        //int temp;
        //temp = atoi(R[i].num);
        for(j=0;j<len-1;j++)
        {
            R[i].sum += R[i].num[j];
            R[i].sum *= bit;
        }
        R[i].sum+=R[i].num[j];
    }
    //sort
    qsort(R,n,sizeof(R[0]),cmp);
    for(j=0;j<n;j++)
    {
        printf("%s",R[j].str);
        printf("\n");
    }
    return 0;
}
