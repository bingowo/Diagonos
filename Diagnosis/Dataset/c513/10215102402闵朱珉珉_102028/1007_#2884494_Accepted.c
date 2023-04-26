#include <stdio.h>
int main()
{
    int T,n,answer,res,s[32];
    scanf ("%d",&T);
    for (int i=0;i<T;i++)
    {
        scanf("%d",&n);
        int k=0;answer=1;res=1;
        while (n!=0)
        {
            s[k++]=n%2;
            n=n/2;
        }
        int j=k-1;
            for (j;j>0;j--)
            {
                if (s[j]!=s[j-1]) answer++;
                else
                {
                    if (answer>res) res=answer;
                    answer=1;
                    continue;
                }
            }
        if (answer>res) res=answer;
        printf("case #%d:\n%d\n",i,res);


    }
}
