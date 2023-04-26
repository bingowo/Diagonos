#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i =0;i<T;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        int count = 0;
        do
        {
            if(x%2!=y%2)
            {
                count++;
            }
            x = x/2;
            y = y/2;
        }while((x!=0)||(y!=0));
        printf("%d\n",count);
    }
    return 0;
}
