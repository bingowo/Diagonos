#include<stdio.h>
#include<stdlib.h>
int main()
{
    int w,h,d;
    char c;
    int a[205][205]= {0};
    scanf("%d %d %d %c",&w,&h,&d,&c);
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    /*for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    */
    if((d%180)==0)
    {
        printf("%d %d\n",w,h);
        for(int i=h-1; i>=0; i--)
        {
            for(int j=w-1; j>=0; j--)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("%d %d\n",h,w);
        if(c=='R')
        {

            for(int i=0; i<w; i++)
            {
                for(int j=h-1; j>=0; j--)
                {
                    printf("%d ",a[j][i]);
                }
                printf("\n");
            }



        }
        else
        {

            for(int i=w-1; i>=0; i--)
            {
                for(int j=0; j<h; j++)
                {
                    printf("%d ",a[j][i]);
                }
                printf("\n");
            }


        }



    }

}
