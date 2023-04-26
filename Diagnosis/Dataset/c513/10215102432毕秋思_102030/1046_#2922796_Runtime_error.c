#include<stdio.h>

const char *str[]={"the","a","an","of","for","and"};

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        char s[100][31];
        int m=0,n=0;
        while(getchar()!='\n')
        {
            if(getchar()==' ') m++;
            else
            {
                s[m][n]=getchar();
                n++;
            }
        }
        int count=m+1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<3;k++)
                    if(s[i][k]==str[j][k]) count--;
            }
        }
        printf("case #%d:\n",t);
        printf("%d",count);
    }
}
