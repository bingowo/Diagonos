#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 128

int cmp(int *p,int n)
{
    for(int i=0;i<N-n;i++)
    {
        if(p[i]>0)return i;
        else return -1;
    }
}

void out(char*p,int point)
{
    for(int i =0;i<point;i++)
    {
        printf("%c",p[i]);
    }
    printf("\n");
}


void output(int *s,int *s_,char *p1,int point)//输出某个字母开头的所有情况
{
    while(*s == 0)s++;
    if(*s == -1)
    {
        return;
    }
    else
    {
    p1[point++] = s-s_;
    p1[point] = '\0';
    out(p1,point);
    s+=1;
    for(int *p2 = s;p2<s_+N;p2++)
    {
        while(*p2 == 0)p2++;
        char r[16];
        strcpy(r,p1);
        output(p2,s_,r,point);
    }

}
}
int main()
{

    int n;
    scanf("%d",&n);
    getchar();
    for(int i =0;i<n;i++)
    {
    int s[N];
    memset(s,0,N*sizeof(int));
    s[N-1] = -1;
    int *p1= s;

    char c;
    while((c = getchar())!='\n')
        {
            if(s[c]<='z'&&s[c]>='a')s[c]++;
            else s[c]++;
        }
        char p3[17];
        memset(p3,0,sizeof(p3));
    while(*p1 !=-1)
    {
    while(*p1==0)p1++;
    output(p1,s,p3,0);
    p1+=1;
    while(*p1 == 0)p1++;
    }
    }
    return 0;
}
