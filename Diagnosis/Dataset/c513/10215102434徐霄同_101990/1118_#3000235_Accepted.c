#include <stdio.h>
void p(int x[200][200],int w,int h)
{
    int i,j;
    printf("%d %d\n",w,h);
    for(i=0;i<h;i++)
        for(j=0;j<w;j++){
            printf("%d",x[i][j]);
            if(j==w-1)
                printf("\n");
            else
                printf(" ");
        }
}
void r1(int a[200][200],int b[200][200],int w,int h)
{
    int i,j;
    for(i=0;i<w;i++)
        for(j=0;j<h;j++)
            b[i][j]=a[h-j-1][i];
    p(b,h,w);
}
void l1(int a[200][200],int b[200][200],int w,int h)
{
    int i,j;
    for(i=0;i<w;i++)
        for(j=0;j<h;j++)
            b[i][j]=a[j][w-i-1];
    p(b,h,w);
}
void r2(int a[200][200],int b[200][200],int w,int h)
{
    int i,j;
    for(i=0;i<h;i++)
        for(j=0;j<w;j++)
            b[i][j]=a[h-i-1][w-j-1];
    p(b,w,h);
}
int main()
{
    int a[200][200],b[200][200];
    int w,h,d,i,j;
    char c;
    scanf("%d%d%d %c",&w,&h,&d,&c);
    for(i=0;i<h;i++)
        for(j=0;j<w;j++)
            scanf("%d",&a[i][j]);
    d=d%360;
    if(d==0)
        p(a,w,h);
    else if((d==90&&c=='R')||(d==270&&c=='L'))
        r1(a,b,w,h);
    else if((d==90&&c=='L')||(d==270&&c=='R'))
        l1(a,b,w,h);
    else
        r2(a,b,w,h);
    return 0;
}
