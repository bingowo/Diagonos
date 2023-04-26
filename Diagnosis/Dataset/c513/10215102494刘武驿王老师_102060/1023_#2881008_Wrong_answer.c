#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct str
{
    char ori[30];
    char alp[30];
    char num[30];
    int test;
};
int cmp(void*a,void*b)
{
    if (((struct str*)a)->test!=((struct str*)b)->test) return ((struct str*)a)->test-((struct str*)b)->test;
    if(((struct str*)a)->test==0&&((struct str*)b)->test==0) return strcmp(((struct str*)a)->ori,((struct str*)b)->ori);
    if(((struct str*)a)->test==1&&((struct str*)b)->test==1) return strcmp(((struct str*)a)->num,((struct str*)b)->num);
    return -strcmp(((struct str*)a)->ori,((struct str*)b)->ori);
}
int main()
{
    char c;
    struct str res[1000];
    for(int i=0;i<1000;i++) res[i].test=0;
    int i=0,j=0,m=0,n=0;
    while((c=getchar())!=EOF)
    {
        if(c!=' ')
        {
            res[n].ori[j++]=c;
            if(c-'0'>=0&&c-'0'<=9)
            {
                res[n].num[m++]=c;
                res[n].test=1;
            }
            else res[n].alp[i++]=c;
        }
        else
        {
            res[n].ori[j]='\0';
            res[n].num[m]='\0';
            res[n].alp[i]='\0';
            i=0;
            j=0;
            m=0;
            n++;
        }
    }
    res[n].ori[j-1]='\0';
    res[n].num[m]='\0';
    res[n].alp[i-1]='\0';
    n++;
    qsort(res,n,sizeof(struct str),cmp);
    for(i=0;i<n;i++) {printf("%s",res[i].ori);printf(" ");}

}