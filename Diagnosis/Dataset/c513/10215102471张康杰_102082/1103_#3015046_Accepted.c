#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    long long int register1[256];
    char command[4],conduct[50];
    while(scanf("%s",command) == 1)
    {
        char*pt;
        switch(command[0])
        {
            case 'I':
                scanf("%s",conduct);
                pt = strchr(conduct,',');
                pt++;
                sscanf(pt,"%lld",&register1[conduct[0]]);
                break;
            case 'M':
                scanf("%s",conduct);
                if(command[1] == 'O')
                {
                    register1[conduct[0]] = register1[conduct[3]];
                }
                else if(command[1] == 'U')
                {
                    register1[conduct[0]] *= register1[conduct[3]];
                }
                break;
            case 'A':
                scanf("%s",conduct);
                register1[conduct[0]] += register1[conduct[3]];
                break;
            case 'S':
                scanf("%s,%s",conduct,conduct);
                register1[conduct[0]] -= register1[conduct[3]];
                break;
            case 'D':
                scanf("%s,%s",conduct,conduct);
                register1[conduct[0]] /= register1[conduct[3]];
                break;
            case 'O':
                scanf("%s",conduct);
                printf("%lld\n",register1[conduct[0]]);
                break;
        }
    }
    return 0;
}