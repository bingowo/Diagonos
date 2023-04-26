#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int r;
    int c;
    char s;
}wave;
int main()
{
    char a[100];
    while(scanf("%s",a)!=EOF)
    {
        wave ans[100];
        int row=0;
        int l=0;
        int min=0;
        int i;
        for(i=0;a[i];i++)
        {
            ans[i].c=i;
            ans[i].s=a[i];
        }
        for(i=1;a[i];i++)
        {
            if(a[i]>a[i-1]) row++;
            else if(a[i]<a[i-1]) row--;
            if(row<min)
            {
                min=row;
                l=i;
            }
        }
        ans[l].r=0;
        char b[100][100]={0};
        for(i=l;i<strlen(a)-1;i++)
        {
            if(a[i]<a[i+1]) ans[i+1].r=ans[i].r+1;
            else if(a[i]>a[i+1]) ans[i+1].r=ans[i].r-1;
            else ans[i+1].r=ans[i].r;
        }
        for(i=l-1;i>=0;i--)
        {
            if(a[i]<a[i+1]) ans[i].r=ans[i+1].r-1;
            else if(a[i]>a[i+1]) ans[i].r=ans[i+1].r+1;
            else ans[i].r=ans[i+1].r;
        }
        for(i=0;a[i];i++)
        {
            b[ans[i].r][ans[i].c]=ans[i].s;
        }
        int h=0;
        for(i=0;a[i];i++)
        {
            if(h<ans[i].r) h=ans[i].r;
        }
        h++;
        for(int j=h-1;j>=0;j--)
        {
            for(int k=0;k<strlen(a);k++)
            {
                if(b[j][k]) printf("%c",b[j][k]);
                else if(k!=strlen(a)-1) printf(" ");
            }
            printf("\n");
        }
//printf("%d %d\n",ans[0].r,ans[0].c);
    }
}
