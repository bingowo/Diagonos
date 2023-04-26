#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int zhi;
    char dir;
}zu;

void fuzhi(zu a[][210],int hang,int lie)
{
    int i,j;
    for(i=1;i<hang;i++)
    {
        a[i][0].zhi+=a[i-1][0].zhi;
        a[i][0].dir='D';
    }
    for(j=1;j<lie;j++)
    {
        a[0][j].zhi+=a[0][j-1].zhi;
        a[0][j].dir='R';
    }
    for(i=1;i<hang;i++)
    {
        for(j=1;j<lie;j++)
        {
            if(a[i-1][j].zhi<a[i][j-1].zhi)
            {
                a[i][j].zhi+=a[i-1][j].zhi;
                a[i][j].dir='D';
            }
            else
            {
                a[i][j].zhi+=a[i][j-1].zhi;
                a[i][j].dir='R';
            }
        }

    }

}

void shuchu(zu a[][210],int hang,int lie,int x,int y)
{
    if((x==0)&&(y==0)) return;
    else
    {
        if(a[x][y].dir=='D')
        {
            shuchu(a,hang,lie,x-1,y);
            printf("D");
        }
        else
        {
            shuchu(a,hang,lie,x,y-1);
            printf("R");
        }
    }
}


int main()
{
    int hang,lie,i,j;
    zu a[210][210];
    memset(a,0,sizeof(a));
    scanf("%d%d",&hang,&lie);
    for(i=0;i<hang;i++)
    {
        for(j=0;j<lie;j++)
        {
            scanf("%d",&a[i][j].zhi);
        }
    }
    fuzhi(a,hang,lie);
    printf("%d\n",a[hang-1][lie-1].zhi);
    shuchu(a,hang,lie,hang-1,lie-1);

    return 0;

}
