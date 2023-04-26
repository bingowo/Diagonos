#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char* itoamy(int num, char* buffer, int base) {
    int curr = 0;

    if (num == 0) {
        // Base case
        buffer[curr++] = '0';
        buffer[curr] = '\0';
        return buffer;
    }

    int num_digits = 0;

    if (num < 0) {
        if (base == 10) {
            num_digits ++;
            buffer[curr] = '-';
            curr ++;
            // Make it positive and finally add the minus sign
            num *= -1;
        }
        else
            // Unsupported base. Return NULL
            return NULL;
    }

    num_digits += (int)floor(log(num) / log(base)) + 1;

    // Go through the digits one by one
    // from left to right
    while (curr < num_digits) {
        // Get the base value. For example, 10^2 = 1000, for the third digit
        int base_val = (int) pow(base, num_digits-1-curr);

        // Get the numerical value
        int num_val = num / base_val;

        char value = num_val + '0';
        buffer[curr] = value;

        curr ++;
        num -= base_val * num_val;
    }
    buffer[curr] = '\0';
    return buffer;
}


int main()
{
    int a;
    scanf("%d",&a);
    for (int i=0;i<a;i++)
    {
        int n;
        scanf("%d",&n);
        int num[10000]={0};
        for(int j=0;j<n;j++)
            scanf("%d",&num[j]);
        char bin[10000][65]={'0'};
        for(int j=0;j<n;j++)
            itoamy(num[j],bin[j],2);
        int count1[10000]={0};
        for(int j=0;j<n;j++)
            {
                for(int k=0;k<64;k++)
                {
                    if(bin[j][k]=='1')
                        count1[j]++;
                }
            }
        int tmpt=0;
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(count1[j]<count1[k])
                {   tmpt=count1[k];
                    count1[k]=count1[j];
                    count1[j]=tmpt;
                    tmpt=num[k];
                    num[k]=num[j];
                    num[j]=tmpt;
                }
                else if((count1[j]==count1[k])&&(num[j]>num[k]))
                {
                    tmpt=num[k];
                    num[k]=num[j];
                    num[j]=tmpt;
                }
            }
        }
        printf("case #%d:\n",i);
        for(int j=0;j<n-1;j++)
        {
            printf("%d ",num[j]);
        }
        printf("%d\n",num[n-1]);
    }
    return 0;
}
