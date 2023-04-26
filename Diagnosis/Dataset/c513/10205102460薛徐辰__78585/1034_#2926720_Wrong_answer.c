#include<stdio.h>
#include<stdlib.h>

double num[26];

int cmp(const void* a,const void* b)
{
    char x=*(char*)a;
    char y=*(char*)b;
    int p,q;
    if(x>='a'&&x<='z')p=x-'a';
    else p=x-'A';
    if(y>='a'&&y<='z')q=y-'a';
    else q=y-'A';
    if(num[p]>num[q])return -1;
    else if(num[p]==num[q])
    {
        if(p==q){
            if(x>y)return -1;
            else return 1;
        }
        else {if(p<q)return -1;else return 1;}
    }
    else return 1;
}

void solve(int k)
{
    char c[100];int m;
    for(int i=0;i<26;i++)scanf("%lf",&num[i]);
    getchar();
    while(scanf("%c",&c[m]))
    {
        if(c[m]=='\n')break;
        else m++;
    }
    qsort(c,m,sizeof(char),cmp);
    printf("case#%d:\n",k);
    for(int i=0;i<m;i++)printf("%c",c[i]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)solve(i);
}
