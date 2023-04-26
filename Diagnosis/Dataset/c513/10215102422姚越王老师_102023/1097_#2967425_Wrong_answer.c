#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define C 1000
typedef struct{char c;int x,y;} CHAR;
int main()
{
    char s[C];int i,j;
    while(~scanf("%s",s))
    {
        CHAR arr[C];arr[0].c=s[0];arr[0].x=arr[0].y=0;int n=strlen(s);
        for(i=1;i<n;++i)
        {
            arr[i].c=s[i];
            arr[i].x=arr[i-1].x+1;
            if(arr[i].c<arr[i-1].c)arr[i].y=arr[i-1].y-1;
            else if(arr[i].c==arr[i-1].c)arr[i].y=arr[i-1].y;
            else arr[i].y=arr[i-1].y+1;
        }
        int miny=0,maxy=0,row=arr[n-1].x+1,col;
        for(i=1;i<n;++i)
        {
            if(arr[i].y<miny){miny=arr[i].y;}
            if(arr[i].y>maxy){maxy=arr[i].y;}
        }
        col=maxy-miny+1;
        for(i=0;i<n;++i)arr[i].y-=miny;
        char ans[row][col];
        for(i=0;i<row;++i)
        {
            for(j=0;j<col;++j)ans[i][j]=' ';
        }
        for(i=0;i<n;++i)ans[arr[i].x][arr[i].y]=arr[i].c;
        for(i=row-1;i>-1;--i)
        {
            for(j=0;j<col;++j)putchar(ans[i][j]);
            putchar('\n');
        }
    }
    return 0;
    
}