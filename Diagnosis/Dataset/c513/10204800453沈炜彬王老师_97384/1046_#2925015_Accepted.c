#include <stdio.h>
#include <string.h>

int
main()
{
    int questions;
    int count=0;
    char temp[30] = {'\0'};
    char s[101] = {'\0'};
    int j=0;
    
    
    scanf("%d",&questions);
    getchar();
    for (int i=0; i<questions; i++)
    {
        gets(s);
        for (int k=0; k<strlen(s); k++)
        {
            while (*(s+k) != ' ' && *(s+k)!='\0')
            {
                temp[j] = *(s+k);
                j++;
                k++;
            }
            temp[j] = '\0';
            switch (j)
            {
                case (1):
                    temp[0] = temp[0]<'a'?temp[0]+32:temp[0];
                    if (temp[0]=='a')
                    {
                        count--;
                    }
                    break;
                case (2):
                    temp[0] = temp[0]<'a'?temp[0]+32:temp[0];
                    temp[1] = temp[1]<'a'?temp[1]+32:temp[1];
                    if (temp[0]=='a' && temp[1]=='n')
                    {
                        count--;
                    }
                    else if (temp[0]=='o' && temp[1]=='f')
                    {
                        count--;
                    }
                    break;
                case (3):
                    temp[0] = temp[0]<'a'?temp[0]+32:temp[0];
                    temp[1] = temp[1]<'a'?temp[1]+32:temp[1];
                    temp[2] = temp[2]<'a'?temp[2]+32:temp[2];
                    if (temp[0]=='t' && temp[1]=='h' && temp[2]=='e')
                    {
                        count--;
                    }
                    else if (temp[0]=='f' && temp[1]=='o' && temp[2]=='r')
                    {
                        count--;
                    }
                    else if (temp[0]=='a' && temp[1]=='n' && temp[2]=='d')
                    {
                        count--;
                    }
                    break;
            }
            count++;
            j = 0;
        }
        printf("case #%d:\n",i);
        printf("%d\n",count);
        count = 0;
//        if (i!=questions-1)
//        {
//            getchar();
//        }
    }
    
    return 0;
}