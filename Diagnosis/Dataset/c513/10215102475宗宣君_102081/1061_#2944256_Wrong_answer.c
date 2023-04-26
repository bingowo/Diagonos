#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
int digit;
char m[16];
}record;
int num(char *a)
{
    int b[123] = {0},c[123] = {0},p,n = 0,i,j =0,res = 0;
    for(i = 0;i<strlen(a);i++)
        {
            p = a[i];
            if(b[p]==0)
            {
            n++;b[p]=1;
            if(i==0) c[p] = 1;
            else if(i==1) c[p] = 0;
            else c[p] = i;
            }
        }
    while(a[j]!='\0')
    {
       p = a[j];
       res = res * n+ c[p];
       j++;
    }
    return res;

}
int cmp(const void *a,const void *b)
{
    if((*(record *)a).digit!=(*(record *)b).digit) return (*(record *)a).digit-(*(record *)b).digit;
    else return strcmp((*(record *)a).m,(*(record *)b).m);
}
int main()
{
    int N,i;
    scanf("%d",&N);
    record s[N];
    for(i = 0;i<N;i++)
        {scanf("%s",s[i].m);
        s[i].digit = num(s[i].m);}
    qsort(s,N,sizeof(record),cmp);
    for(i = 0;i<N;i++)
        printf("%s\n",s[i].m);
    return 0;


}
