#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int m;
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
        int count=0;
        char s[100];
        do{
            scanf("%s",s);
            count++;
        }while(getchar()!='\n');

        printf("case #%d:\n",z);

        printf("%d",count);
        
        printf("\n");
    }
    return 0;
}
