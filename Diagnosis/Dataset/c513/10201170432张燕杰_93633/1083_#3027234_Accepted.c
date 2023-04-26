#include<stdio.h>
int ans = 0;

int main()
{
    int T;
    scanf("%d",&T);
    for(int i =0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int N;
        scanf("%d",&N);
        while(N>=5)
        {
            int temp = N;
            while(temp%5 == 0)
            {
                temp = temp/5;
                ans++;
            }
            N--;
        }
        printf("%d\n",ans);
        ans = 0;
    }
    return 0;
}
