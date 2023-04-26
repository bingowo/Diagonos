#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define C 1000
typedef struct{char c;int col;int row;} REC;
int cmp(const void* a,const void* b)
{
    REC p1=*(REC*)a,p2=*(REC*)b;
    return p1.c-p2.c;
}
int main()
{
    char s[C];int n,i,j;
    while (~scanf("%s",s))
    {
        REC arr[C];n=strlen(s);
        for(i=0;i<n;++i)arr[i].c=s[i];
        qsort(arr,n,sizeof(arr[0]),cmp);
        int cnt=1;
        for(i=1;i<n;++i)if(arr[i].c!=arr[i-1].c)cnt++;
        arr[0].col=1;arr[0].row=cnt;
        for(i=1;i<n;++i)
        {
            if(arr[i].c==arr[i-1].c)arr[i].row=arr[i-1].row;
            else arr[i].row=arr[i-1].row-1;
            arr[i].col=arr[i-1].col+1;
        }
        char ans[C][C]={' '};
        for(i=0;i<n;++i)ans[arr[i].row][arr[i].col]=arr[i].c;
        for(i=1;i<=cnt;++i)
        {
            for(j=1;j<=arr[n-1].col;++j)putchar(ans[i][j]);
            putchar('\n');
        }
    }
    return 0;
    
}