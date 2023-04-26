#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    char c=getchar();
    for(int j=0; j<t; j++)
    {
        int map[256]={0};
        c=getchar();
        for(int i=0; c != '\n'; i++)
        { 
            map[c] = map[c] + 1 ;
            c=getchar();
        }
        printf("case #%d:\n",j);
        for(int i=0; i<256; i++)
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