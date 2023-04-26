#include <stdio.h>
#include <string.h>

int
main()
{
    int questions;
    int count = 0;
    char temp;
    
    scanf("%d",&questions);
    for (int i=0; i<questions; i++)
    {
        char s[501] = {'\0'};
        
        
        scanf("%s",s);
        printf("case #%d:\n",i);
        count = 1;
        temp = s[0];

        for (int j=1; j<strlen(s); j++)
        {
            if (*(s+j) != temp)
            {
                printf("%d%c",count,temp);
                temp = *(s+j);
                count = 1;
            }
            else if (count == 255)
            {
                printf("%d%c",count,temp);
                count = 1;
            }
            else
            {
                count++;
            }
        }
        printf("%d%c",count,temp);
        printf("\n");
    }
    
    return 0;
}
