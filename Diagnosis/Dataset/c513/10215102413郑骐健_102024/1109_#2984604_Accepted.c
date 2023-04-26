#define _CRT_SECURE_NO_WARNINGS 1
/* strchr example */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);

     for(int i =0;i<t;i++)
    {
        printf("case #%d:\n",i);
        int r[9]={0};
         int flag=0;
        for(int g=0;g<9;g++)
        {
            scanf("%d",&r[g]);
        }

        for(int q=0;q<9;q++)
        {
            if(r[q]<0)
            {
                if(r[q]!=-1)printf("%d",r[q]);
                else if(q!=8) printf("-");
                else printf("-1");
                flag=1;
            }
            else if(r[q]>0)
            {
                if(flag)printf("+");
                else flag=1;
                if(r[q]!=1)printf("%d",r[q]);
                else if(q==8)printf("1");
            }

            if(q<=6&&r[q]!=0)printf("x^%d",8-q);
            else if(q==7&&r[q]!=0)printf("x");
            else if(q==8)
            {
                int z;
                for( z=0;z<8;z++)
                {
                    if(r[z]!=0)break;
                }
                if(z==8&&r[8]==0)printf("0");
            }
        }
        if(i!=t-1)printf("\n");
    }
	return 0;
}
