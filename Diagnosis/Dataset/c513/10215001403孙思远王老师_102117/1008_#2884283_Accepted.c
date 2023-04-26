#include <stdio.h>
#include <stdlib.h>


int main()
{
    int t,T,x,y,num,j;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        num=32;
        j=1;
        scanf("%d%d",&x,&y);
        for(int i=0;i<32;i++)
        {
            if(((x|j)!=x&&(y|j)!=y)||((x|j)==x&&(y|j)==y))
            {
                j=j<<1;
                num--;
            }
            else
            {
                j=j<<1;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
