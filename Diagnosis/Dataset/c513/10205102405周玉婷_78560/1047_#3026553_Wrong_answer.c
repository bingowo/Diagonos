#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    char c=getchar();
    for(int j=0; j<t; j++)
    {
        int map[90]={0};int len =0;
        c=getchar();
        for(int i=0; c != '\n'; i++)
        { 
            map[c] = map[c] + 1 ;
            len++;
            c=getchar();
        }
        printf("case #%d:\n",j);
        for(int i=65; i<90; i++)
        {
            if(map[i] == 0) continue;
            if(map[i] > 255)
            {
                int temp =map[i]%255;
                printf("%d%c%d%c",255,i,temp,i);
            }
            printf("%d%c",map[i],i);
        }
        printf("\n");
    }
    return 0;
}