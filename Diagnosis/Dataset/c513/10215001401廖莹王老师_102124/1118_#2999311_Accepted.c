#include <stdio.h>
#include <stdlib.h>
int a[200][200]={0};
int m,n;
void type0()
{
    int i=0,j=0;
    printf("%d %d\n",m,n);
    for(i=0;i<n;i++){for(j=0;j<m;j++)printf("%d ",a[i][j]);printf("\n");}
    return;
}
void type1()
{
    int i=0,j=0;
    printf("%d %d\n",n,m);
    for(j=0;j<m;j++){for(i=n-1;i>=0;i--)printf("%d ",a[i][j]);printf("\n");}
    return;
}
void type2()
{
    int i=0,j=0;
    printf("%d %d\n",m,n);
    for(i=n-1;i>=0;i--){for(j=m-1;j>=0;j--)printf("%d ",a[i][j]);printf("\n");}
    return;
}
void type3()
{
    int i=0,j=0;
    printf("%d %d\n",n,m);
    for(j=m-1;j>=0;j--){for(i=0;i<n;i++)printf("%d ",a[i][j]);printf("\n");}
    return;
}
int main()
{
    int d,i=0,j=0;
    char c;
    scanf("%d %d %d %c",&m,&n,&d,&c);
    for(i=0;i<n;i++){for(j=0;j<m;j++)scanf("%d",&a[i][j]);}
    d=d%360;
    if(c=='R')
    {
        switch(d)
       {
           case 0:type0();break;
           case 90:type1();break;
            case 180:type2();break;
            case 270:type3();break;
        }
    }
    if(c=='L')
    {
        switch(d)
       {
           case 0:type0();break;
           case 90:type3();break;
            case 180:type2();break;
            case 270:type1();break;
        }
    }


    return 0;
}
