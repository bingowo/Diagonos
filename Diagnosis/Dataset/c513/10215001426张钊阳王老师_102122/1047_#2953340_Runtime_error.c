#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m;
    scanf("%d\n",&m);
    for(int z=0;z<m;z++)
    {
        unsigned char s[500];
        gets(s);
        printf("case #%d:\n",z);
        int i,count;
        i=0;
        count=1;
        while(s[i]!='\0')
        {
            while(s[i]==s[i+1]&&count<255)
            {
                count++;
                i++;
            }
            printf("%d",count);
            printf("%c",s[i]);
            count=1;
            i++;
        }
        printf("\n");
    }
    return 0;
}
