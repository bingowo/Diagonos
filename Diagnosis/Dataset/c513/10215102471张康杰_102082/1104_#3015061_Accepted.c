#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int register1[266] = {0};
    char command[10];
    char conduct[60];
    while(scanf("%s",command) == 1)
    {
        switch(command[0])
        {
            case 'I':
                scanf("%s",conduct);
                char*pt = strchr(conduct,',');
                pt++;
                sscanf(pt,"%d",&register1[conduct[0]]);
                break;
            case 'M':
                scanf("%s",conduct);
                if(command[2] == 'V')
                {
                    register1[conduct[0]] = register1[conduct[3]];
                }
                else if(command[2] == 'L')
                {
                    if(strlen(conduct) == 8)
                    {
                        register1[conduct[0]] = register1[conduct[3]] * register1[conduct[6]];
                    }
                    else
                    {
                        register1[conduct[0]] *= register1[conduct[3]];
                    }
                }
                else if(command[2] == 'D')
                {
                    if(strlen(conduct) == 8)
                    {
                        register1[conduct[0]] = register1[conduct[3]] % register1[conduct[6]];
                    }
                    else
                    {
                        register1[conduct[0]] %= register1[conduct[3]];
                    }
                }
                break;
            case 'A':
                scanf("%s",conduct);
                if(command[1] == 'D')
                {    
                    if(strlen(conduct) == 8)
                    {
                        register1[conduct[0]] = register1[conduct[3]] + register1[conduct[6]];
                    }
                    else
                    {
                        register1[conduct[0]] += register1[conduct[3]];
                    }
                }
                else if(command[1] == 'N')
                {
                    if(strlen(conduct) == 8)
                    {
                        register1[conduct[0]] = register1[conduct[3]] & register1[conduct[6]];
                    }
                    else
                    {
                        register1[conduct[0]] &= register1[conduct[3]];
                    }
                }
                break;
            case 'X':
                scanf("%s",conduct);
                if(command[1] == 'C')
                {
                    int temp;
                    temp = register1[conduct[0]];
                    register1[conduct[0]] = register1[conduct[3]];
                    register1[conduct[3]] = temp;
                }
                else if(command[1] == 'O')
                {
                    if(strlen(conduct) == 8)
                    {
                        register1[conduct[0]] = register1[conduct[3]] ^ register1[conduct[6]];
                    }
                    else
                    {
                        register1[conduct[0]] ^= register1[conduct[3]];
                    }
                }
                break;
            case 'O':
                scanf("%s",conduct);
                if(command[1] == 'R')
                {
                    if(strlen(conduct) == 8)
                    {
                        register1[conduct[0]] = register1[conduct[3]] | register1[conduct[6]];
                    }
                    else
                    {
                        register1[conduct[0]] |= register1[conduct[3]];
                    }
                }
                else if(command[1] == 'U')
                {
                    printf("%d\n",register1[conduct[0]]);
                }
                break;
            case 'S':
                scanf("%s",conduct);
                if(strlen(conduct) == 8)
                {
                    register1[conduct[0]] = register1[conduct[3]] - register1[conduct[6]];
                }
                else
                {
                    register1[conduct[0]] -= register1[conduct[3]];
                }
                break;
            case 'D':
                scanf("%s",conduct);
                if(strlen(conduct) == 8)
                {
                    register1[conduct[0]] = register1[conduct[3]] / register1[conduct[6]];
                }
                else
                {
                    register1[conduct[0]] /= register1[conduct[3]];
                }
                break;
        }   
    }
    return 0;
}