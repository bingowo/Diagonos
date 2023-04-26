#include <stdio.h>
#include <stdlib.h>

int cmpA(const void*a,const void*b,char c)
{
    int ia=*(int *)a,ib=*(int *)b;
    if(ia>=ib) return 1;
    else if(ia<ib) return -1;
}
int cmpB(const void*a,const void*b,char c)
{
    int ia=*(int *)a,ib=*(int *)b;
    if(ia>=ib) return -1;
    else if(ia<ib) return 1;
    return 0;
}
void re(int *s,int i)
{
    for(int j=0;j<i-1;j++)
    {
        if(s[j]==s[j-1]||s[j]==s[j+1]) s[j]=-1;
    }
}
int main()
{
    char c;
    scanf("%c",&c);
    int s[200]={[0 ... 199]=-1};
    int i=0;
    do{
        scanf("%d",&s[i++]);
    }while(getchar()==' ');
    if(c=='A') qsort(s,i,sizeof(int),cmpA);
    if(c=='D') qsort(s,i,sizeof(int),cmpB);
    re(s,i);
    for(int j=0;j<i;j++)
    {
        if(s[j]>=0)
        {
            if(j<i-1) printf("%d ",s[j]);
            else if(j==i-1) printf("%d",s[j]);
        }
    }
    return 0;
}
