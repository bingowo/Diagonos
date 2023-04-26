#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
main()
{
    char order[4];
    char temp_s[10];
    char temp,temp1,temp2;
    int storage[26];
    char num[12];
    int num_temp;
    
    for (int i=0; i<26; i++)
    {
        storage[i] = 0;
    }
    
    while (~scanf("%s",order))
    {
        if (order[0]=='I')
        {
            getchar();
            temp = getchar();
            getchar();
            getchar();
            scanf("%s",num);
            storage[temp-65] = atoi(num);
        }
        else if (order[0]=='O' && order[1]=='U')
        {
            getchar();
            temp = getchar();
            getchar();
            printf("%d\n",storage[temp-65]);
        }
        else if (order[0]=='M' && order[1]=='O' && order[2]=='V')
        {
            getchar();
            temp1 = getchar();
            getchar();
            getchar();
            temp2 = getchar();
            getchar();
            storage[temp1-65] = storage[temp2-65];
        }
        else if (order[0]=='X' && order[1]=='C')
        {
            getchar();
            temp1 = getchar();
            getchar();
            getchar();
            temp2 = getchar();
            getchar();
            num_temp = storage[temp1-65];
            storage[temp1-65] = storage[temp2-65];
            storage[temp2-65] = num_temp;
        }
        else if (order[0]=='A' && order[1] =='D')
        {
            scanf("%s",temp_s);
            if (strlen(temp_s)>6)
            {
                storage[temp_s[0]-65] = storage[temp_s[3]-65] + storage[temp_s[6]-65];
            }
            else
            {
                storage[temp_s[0]-65] = storage[temp_s[0]-65] + storage[temp_s[3]-65];
            }
        }
        else if (order[0]=='M' && order[1] =='U')
        {
            scanf("%s",temp_s);
            if (strlen(temp_s)>6)
            {
                storage[temp_s[0]-65] = storage[temp_s[3]-65] * storage[temp_s[6]-65];
            }
            else
            {
                storage[temp_s[0]-65] = storage[temp_s[0]-65] * storage[temp_s[3]-65];
            }
        }
        else
        {
            scanf("%s",temp_s);
            switch (order[0])
            {
                case ('S'):
                    if (strlen(temp_s)>6)
                    {
                        storage[temp_s[0]-65] = storage[temp_s[3]-65] - storage[temp_s[6]-65];
                    }
                    else
                    {
                        storage[temp_s[0]-65] = storage[temp_s[0]-65] - storage[temp_s[3]-65];
                    }
                    break;
                case ('D'):
                    if (strlen(temp_s)>6)
                    {
                        storage[temp_s[0]-65] = storage[temp_s[3]-65] / storage[temp_s[6]-65];
                    }
                    else
                    {
                        storage[temp_s[0]-65] = storage[temp_s[0]-65] / storage[temp_s[3]-65];
                    }
                    break;
                case ('M'):
                    if (strlen(temp_s)>6)
                    {
                        storage[temp_s[0]-65] = storage[temp_s[3]-65] % storage[temp_s[6]-65];
                    }
                    else
                    {
                        storage[temp_s[0]-65] = storage[temp_s[0]-65] % storage[temp_s[3]-65];
                    }
                    break;
                case ('A'):
                    if (strlen(temp_s)>6)
                    {
                        storage[temp_s[0]-65] = storage[temp_s[3]-65] & storage[temp_s[6]-65];
                    }
                    else
                    {
                        storage[temp_s[0]-65] = storage[temp_s[0]-65] & storage[temp_s[3]-65];
                    }
                    break;
                case ('O'):
                    if (strlen(temp_s)>6)
                    {
                        storage[temp_s[0]-65] = storage[temp_s[3]-65] | storage[temp_s[6]-65];
                    }
                    else
                    {
                        storage[temp_s[0]-65] = storage[temp_s[0]-65] | storage[temp_s[3]-65];
                    }
                    break;
                case ('X'):
                    if (strlen(temp_s)>6)
                    {
                        storage[temp_s[0]-65] = storage[temp_s[3]-65] ^ storage[temp_s[6]-65];
                    }
                    else
                    {
                        storage[temp_s[0]-65] = storage[temp_s[0]-65] ^ storage[temp_s[3]-65];
                    }
                    break;
                    
            }
        }
    }
    
    
    
    return 0;
}