#include <stdio.h>

char s[10][10] = {"","x","x^2","x^3","x^4","x^5","x^6","x^7","x^8"};

int main()
{
    int n; scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int num; int p = 8;
        int istop = 1;
        printf("case #%d:\n",i);
        for (int j=8;j>=0;j--) 
        {
            scanf("%d",&num);
            if (num==0) continue;
            if (istop&&num&&j!=0)
            {
                if (num==1) printf("%s",s[j]);
                else if (num==-1) printf("-%s",s[j]);
                else printf("%d%s",num,s[j]);
                istop = 0;
            }
            else if (istop&&j==0)
            {
                printf("%d",num);
            }
            else 
            {
                if (j==0&&num>0) printf("+%d",num);
                else if (j==0&&num<0) printf("%d",num);
                else
                {
                    if (num==1) printf("+");
                    else if (num==-1) printf("-");
                    else if (num>0) printf("+%d",num);
                    else if (num<0) printf("%d",num);
                } 
                printf("%s",s[j]);
            }
        }
        if (istop) printf("0");
        printf("\n");
    }
    return 0;
}