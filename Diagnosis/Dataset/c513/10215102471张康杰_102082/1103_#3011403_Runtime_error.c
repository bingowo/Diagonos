#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int register1[256];
    char temp1[10],temp2[10],command[10],conduct[10];
    while(scanf("%s",command) == 1)
    {
        char*pt;
        switch(command[0])
        {
            case 'I':
                scanf("%s",conduct);
                pt = strchr(conduct,',');
                pt++;
                sscanf(pt,"%d",&register1[conduct[0]]);
                break;
            case 'M':
                scanf("%s,%s",temp1,temp2);
                if(command[1] == 'O')
                {
                    register1[temp1[0]] = register1[temp2[0]];
                }
                else if(command[1] == 'U')
                {
                    register1[temp1[0]] *= register1[temp2[0]];
                }
                break;
            case 'A':
                scanf("%s,%s",temp1,temp2);
                register1[temp1[0]] += register1[temp2[0]];
                break;
            case 'S':
                scanf("%s,%s",temp1,temp2);
                register1[temp1[0]] -= register1[temp2[0]];
                break;
            case 'D':
                scanf("%s,%s",temp1,temp2);
                register1[temp1[0]] /= register1[temp2[0]];
                break;
            case 'O':
                scanf("%s",temp1);
                printf("%d\n",register1[temp1[0]]);
                break;
        }
    }
    return 0;
}