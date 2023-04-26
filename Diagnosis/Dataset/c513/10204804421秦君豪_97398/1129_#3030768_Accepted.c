#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef long long int lli;
typedef struct
{
}data;

void print(int low,int high,char* s,lli cnt)
{
    for(lli i=0;i<cnt;i++)
    {
        for(int j=low;j<high;j++) printf("%c",s[j]);
    }
}
int main()
{

    char* s=(char *)malloc(sizeof(char)*10001);
    scanf("%s",s);
    int low=0,high=0;
    for(high=0;high<strlen(s);high++)
    {
//        printf("pass");
        if((s[high]>='0')&&(s[high]<='9'))
        {
            lli cnt=0;
            int h=high;
//            printf("!!%d!!\n",s[high]-'0');
            while(s[high]>='0'&&s[high]<='9')
            {
                cnt=cnt*10+s[high]-'0';
                high++;
            }
            high--;
            print(low,h,s,cnt);
//            printf("\n");
            low=high+1;
        }
        else
        {
            continue;
        }
    }
    if((s[strlen(s)-1]>'9')||(s[strlen(s)-1]<'0'))
    {
        print(low,strlen(s),s,1);
    }

    free(s);
    return 0;
}