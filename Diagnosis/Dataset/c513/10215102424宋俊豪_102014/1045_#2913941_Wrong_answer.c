#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char s[101];
} list;
int slo(char s[],char t[])
{
    int l1,l2,i=0,j=0;
    l1=strlen(s);
    l2=strlen(t);
    if(s[0]!=t[0]||s[l1-1]!=t[l2-1])
        return -1;
    while(i<l1&&j<l2)
    {
        if(s[i]!=t[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    if(i<l1)
        return -1;
    else
        return l2;


}
int cmp(const void *a,const void *b)
{
    list*x=(list*)a;
    list*y=(list*)b;
    return strlen(x->s)-strlen(y->s);
}
int main()
{
    int n,cnt,num=0,shu,len;
    scanf("%d",&n);
    list *t=(list*)malloc(sizeof(list)*n);
    for(int i=0; i<n; i++)
    {
        scanf("%s",t[i].s);
    }
    qsort(t,n,sizeof(list),cmp);
    if(n%2==1)
        cnt=(n+1)/2;
    else
        cnt=n/2;
    len=strlen(t[cnt-1].s);
    for(int i=1; i<n; i++)
    {
        shu=slo(t[0].s,t[i].s);
        if(shu==-1)
        {
            num=-1;
            break;
        }
        else
            num+=abs(len-shu);
        if(i==cnt-1)
            num+=len-strlen(t[0].s);
    }
    printf("%d",num);
    free(t);
}
