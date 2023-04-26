#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T,i;
    scanf("%d", &T);
    int table[256];
     for(i = 0;i < T;i++)
    {
        memset(table, -1, sizeof(table));
        int output[61];
        int base = 1;
        long long int sum=0;
        char input[61];
        scanf("%s", input);
        int n=strlen(input);
        int flag=0;
        for(int j=0;j<n;j++)
        {
            if(table[input[j]]==-1)
            {
                if(flag==0&&j!=0)
                {
                    flag=1;output[j]=0;
                    table[input[j]] = 0;
                    continue;
                }
                table[(int)input[j]]=base;
                output[j]=base;
                base++;
            }
            else output[j]=table[(int)input[j]];
        }
        int j = 0;
        for(j=0;j<n;j++)
        {
            sum = base*sum + output[j];
        }
        printf("case #%d:\n%lld\n",i,sum);
    }
    return 0;
}
