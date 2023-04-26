#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int s[11];
        for(int k=0;k<9;k++)
            scanf("%d",&s[k]);
        printf("case #%d:\n",i);
        int l=0;
        while(s[l]==0&&l<9) l++;
        if(l==9) printf("0");
        else
            {
                if(s[l]==1) printf("x^%d",8-l);
                else if(s[l]==-1) printf("-x^%d",8-l);
                else printf("%dx^%d",s[l],8-l);
                l++;
                int k;
                for(k=l;k<=6;k++)
                {
                    if(s[k]!=0)

                    {if(s[k]>0) printf("+");
                    if(s[k]==1) printf("x^%d",8-k);
                    else if(s[k]==-1) printf("-x^%d",8-k);
                    else printf("%dx^%d",s[k],8-k);}

                }
                if(s[k]!=0)
                {if(s[k]>0) printf("+");
                if(s[k]==1) printf("x");
                else if(s[k]==-1) printf("-x");
                else printf("%dx",s[k]);}
                k++;
                if(s[k]!=0)
                {if(s[k]>0) printf("+");
                printf("%d",s[k]);}

            }
        printf("\n");
    }
    return 0;
}
