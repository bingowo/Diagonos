#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,i;
    scanf("%d", &T);
    int table[128];
    int output[61];
    memset(table, -1, sizeof(table));
    for(i = 0;i < T;i++)
    {

        int base = 1,j,sum;
        char input[61];
        scanf("%s", input);
        int n=strlen(input);
        output[0] = 1;
        table[input[0]] = base;
        int flag=0;
        for(int j=0;j<n;j++)
        {
            if(table[input[j]]==-1)
            {
                if(flag==0&&j!=0)
                {
                    flag=1;output[j]=0;
                    continue;
                }
                table[input[j]]=base;
                output[j]=base;
                base++;
            }
            else output[j]=table[input[j]];
        }
        for(j=0;j<n;j++)
        {
            sum = base*sum + output[j];
        }
        printf("case #%d:\n%d\n",i,sum);
    }
    return 0;
}