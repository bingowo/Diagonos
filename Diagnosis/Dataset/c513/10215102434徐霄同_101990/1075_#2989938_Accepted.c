#include <stdio.h>
typedef struct
{
    int d;
    char c;
}path;
void f(path a[200][200],int m,int n)
{
    int i,j;
    for(i=1;i<m;i++){
        a[i][0].d=a[i][0].d+a[i-1][0].d;
        a[i][0].c='D';
    }
    for(i=1;i<n;i++){
        a[0][i].d=a[0][i].d+a[0][i-1].d;
        a[0][i].c='R';
    }
    for(i=1;i<m;i++)
        for(j=1;j<n;j++){
            if(a[i-1][j].d<a[i][j-1].d){
                a[i][j].d=a[i][j].d+a[i-1][j].d;
                a[i][j].c='D';
            }
            else{
                a[i][j].d=a[i][j].d+a[i][j-1].d;
                a[i][j].c='R';
            }
        }
}
void pr(path a[200][200],int m,int n)
{
    if(m==0&&n==0)
        return;
    if(a[m][n].c=='D')
        pr(a,m-1,n);
    else
        pr(a,m,n-1);
    printf("%c",a[m][n].c);
}
int main()
{
    path a[200][200];
    int i,j,m,n;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j].d);
            a[i][j].c=0;
        }
    f(a,m,n);
    printf("%d\n",a[m-1][n-1].d);
    pr(a,m-1,n-1);
    printf("\n");
    return 0;
}
