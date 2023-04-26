#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int w,h,d;
    char c;
    scanf("%d%d%d%c",&w,&h,&d,&c);
    int s[200][200];
    for(int i=0;i<h;i++)
      for(int j=0;j<w;j++)
            scanf("%d",&s[i][j]);
    if(d>=360) d=d%360;
    if(c=='L')
    {
        d=360-d;
    }
    if(d==0)
        {
            printf("%d %d\n",w,h);
            for(int i=0;i<h;i++)
            {for(int j=0;j<w;j++)
               printf("%d",s[i][j]);
               printf("\n");}
        }
        else if(d==90)
        {
           printf("%d %d\n",h,w);
           for(int i=0;i<w;i++)
           {
               for(int j=h-1;j>=0;j--)
                printf("%d",s[j][i]);
               printf("\n");
           }
        }
        else if(d==180)
        {
            printf("%d %d\n",w,h);
            for(int i=h-1;i>=0;i--)
            {for(int j=w-1;j>=0;j--)
                printf("%d",s[i][j]);
                printf("\n");}
        }
        else if(d==270)
        {
            printf("%d %d\n",h,w);
            for(int i=w-1;i>=0;i--)
            {
                for(int j=0;j<h;j++)
                    printf("%d",s[j][i]);
                printf("\n");
            }
        }




    return 0;
}
