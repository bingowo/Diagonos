#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0; i<T; i++)
    {
        printf("case #%d:\n",i);
        int a[10]= {0};
        for(int j=0; j<9; j++)scanf("%d",&a[j]);
        int k=0;
        for(k=0; k<9; k++)if(a[k]!=0){break;}


        for(int j=0; j<8; j++)
        {
            if(a[j]!=0)
            {
                if(j==k)
                {

                    if(a[j]==-1)printf("-");
                    else if(a[j]==1);
                    else printf("%d",a[j]);
                   if(8-j>1) printf("x^%d",8-j);
                   else printf("x");


                }
                else
                {
                   if(a[j]==-1)printf("-");
                  else  if(a[j]>1)printf("+%d",a[j]);
                    else if(a[j]==1)printf("+");
                   else printf("%d",a[j]);
                    if(8-j>1) printf("x^%d",8-j);
                   else printf("x");

                }
            }
        }
        if((k==9)&&(a[8]==0))printf("0");
        if(k!=9&&a[8]>0)printf("+");
        if(a[8]!=0)printf("%d",a[8]);


        printf("\n");
    }

}
