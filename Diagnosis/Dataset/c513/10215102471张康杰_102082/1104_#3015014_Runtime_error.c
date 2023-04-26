#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int register1[256] = {0};
    char temp1[3],temp2[3];
    char command[10];
    char conduct[50];
    while(scanf("%s",command) == 1)
    {
        switch(command[0])
        {
            case 'I':
                scanf("%s",conduct);
                char*pt = strchr(conduct,',');
                pt++;
                sscanf(pt,"%d",register1[conduct[0]]);
                break;
            case 'M':
                scanf("%s,%s",temp1,temp2);
                if(command[2] == 'V')
                {
                    register1[temp1[0]] = register1[temp2[0]];
                }
                else if(command[2] == 'L')
                {
                    register1[temp1[0]] *= register1[temp2[0]];
                }
                else if(command[2] == 'D')
                {
                    register1[temp1[0]] %= register1[temp2[0]];
                }
                break;
            case 'A':
                if(command[1] == 'D')
                {
                    scanf("%s",conduct);
                    if(strlen(conduct) == 8)
                    {
                        register1[conduct[0]] = register1[conduct[3]] + register1[conduct[5]];
                    }
                    else
                    {
                        register1[conduct[0]] += register1[conduct[3]];
                    }
                }
                else if(command[1] == 'N')
                {
                    scanf("%s,%s",temp1,temp2);
                    register1[temp1[0]] &= register1[temp2[0]];
                }
            case 'X':
                if(command[1] == 'C')
                {
                    int temp;
                    scanf("%s",conduct);
                    temp = register1[conduct[0]];
                    register1[conduct[0]] = register1[conduct[3]];
                    register1[conduct[3]] = temp;
                }
                else if(command[1] == 'O')
                {
                    scanf("%s",conduct);
                    register1[conduct[0]] = register1[conduct[0]] ^ register1[conduct[3]];
                }
            case 'O':
                if(command[1] == 'R')
                {
                    scanf("%s",conduct);
                    register1[conduct[0]] = register1[conduct[0]] | register1[conduct[3]];
                }
                else if(command[1] == 'U')
                {
                    scanf("%s",temp1);
                    printf("%d\n",register1[temp1[0]]);
                }
                break;
            case 'S':
                scanf("%s",conduct);
                if(strlen(conduct) == 8)
                {
                    register1[conduct[0]] = register1[conduct[3]] - register1[conduct[5]];
                }
                else
                {
                    register1[conduct[0]] -= register1[conduct[3]];
                }
                break;
            case 'D':
                scanf("%s,%s",temp1,temp2);
                register1[temp1[0]] /= register1[temp2[0]];
                break;
        }   
    }
    return 0;
}