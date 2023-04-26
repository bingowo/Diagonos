#include <stdio.h>
#include <stdlib.h>

int
main()
{
    int storage[4];
    char order[4];
    char temp,temp2;
    char num[11];
    
    for (int i=0; i<4; i++)
    {
        storage[i] = 0;
    }
    
    while (~scanf("%s",order))
    {
        switch(order[0])
        {
            case ('I'):
                getchar();
                temp = getchar();
                getchar();
                getchar();
                scanf("%s",num);
                storage[temp-65] = atoi(num);
                break;
            case ('M'):
                if (order[1] == 'O')
                {
                    getchar();
                    temp = getchar();
                    getchar();
                    getchar();
                    temp2 = getchar();
                    getchar();
                    storage[temp-65] = storage[temp2-65];
                }
                else
                {
                    getchar();
                    temp = getchar();
                    getchar();
                    getchar();
                    temp2 = getchar();
                    getchar();
                    storage[temp-65] = storage[temp-65] * storage[temp2-65];
                }
            case ('A'):
                getchar();
                temp = getchar();
                getchar();
                getchar();
                temp2 = getchar();
                getchar();
                storage[temp-65] = storage[temp-65] + storage[temp2-65];
                break;
            case ('S'):
                getchar();
                temp = getchar();
                getchar();
                getchar();
                temp2 = getchar();
                getchar();
                storage[temp-65] = storage[temp-65] - storage[temp2-65];
                break;
            case ('D'):
                getchar();
                temp = getchar();
                getchar();
                getchar();
                temp2 = getchar();
                getchar();
                storage[temp-65] = storage[temp-65] / storage[temp2-65];
                break;
            case ('O'):
                getchar();
                temp = getchar();
                getchar();
                printf("%d\n",storage[temp-65]);
                break;
        }
    }
    
    return 0;
}