#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        char s[501];
        int number[501]={0};
        char alpha[501]={0};
        char ch;
        int j=0,r=0;
        int count=1;
        scanf("%s",s);
        ch=s[0];
        for(j=1;j<=strlen(s);j++)
        {
            if(s[j] == ch)
            {
                count++;
                if(count == 255)
                {
                    number[r] = count;
                    alpha[r++] = ch;
                    count = 0;
                }
            }
            else
            {
                if(count == 0 && j == strlen(s))
                    continue;
                //result[r++] = count;
                //reslut[r++] = ch;
                number[r] = count;
                alpha[r++] = ch;
                count = 1;
            }
            ch=s[j];
        }
        printf("case #%d:\n",i);
        for(j=0;j<r;j++)
        {
            printf("%d",number[j]);
            printf("%c",alpha[j]);
        }
        printf("\n");
    }
    return 0;
}
