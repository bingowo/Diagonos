#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 60


int main()
{
    int T;
    scanf("%d",&T);
    for (int m=0;m<T;m++)
    {
        printf("case #%d:\n",m);
        char num[20];
        int len,len10=0,i,j,num8[20],num10[60]={0};
        scanf("%s",num);
        len=strlen(num);
        for (i=len-1,j=0;i>1;i--,j++)
            num8[j]=num[i]-'0';
        len-=2;
        for (i=0;i<len;i++)
        {
            num10[0]=num8[i];
            int len_res,rem=num10[0];
            for(len_res=0;len_res<len10||rem;)
            {
                num10[len_res]=rem/8;
                rem=(rem%8)*10+num10[++len_res];
            }
            len10=len_res;
        }
        printf("0.");
        for (i=1;i<len10;i++)
            printf("%d",num10[i]);
        printf("\n");
    }

    return 0;
}
