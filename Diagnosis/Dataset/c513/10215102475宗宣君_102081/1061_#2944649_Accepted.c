#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
long long int digit;
char m[16];
}record;
long long int num(char *a)
{
    int b[123] = {0},p,n = 0,i,j =0;
    long long int res  = 0,c[123] = {0};
    for(i = 0;i<strlen(a);i++)
        {
            p = a[i];
            if(b[p]==0)
            {
            n++;b[p]=1;
            if(n==1) c[p] = 1LL;
            else if(n==2) c[p] = 0LL;
            else c[p] = n-1;
            }
        }
    while(a[j]!='\0')
    {
       p = a[j];
       res = res * ((n>2)?n:2)+ c[p];
       j++;
    }
    return res;

}
int cmp(const void *a,const void *b)
{
    record p = *(record *)a,q = *(record *)b;
    if(p.digit>q.digit) return 1;
    else if(p.digit==q.digit) return strcmp(p.m,q.m);
    else return -1;
}
int main()
{
    int N,i;
    scanf("%d",&N);
    record s[10000];
    for(i = 0;i<N;i++)
        {scanf("%s",s[i].m);
        s[i].digit = num(s[i].m);}
    qsort(s,N,sizeof(record),cmp);
    for(i = 0;i<N;i++)
        printf("%s\n",s[i].m);
    return 0;


}
