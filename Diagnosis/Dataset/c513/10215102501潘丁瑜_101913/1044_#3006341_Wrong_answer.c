#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char record[100001]={0};
//char result[100001]={0};
void STtoTEN(char record[])
{
    int i;
    double j=0;
    unsigned long long int r=0;
    for(i=strlen(record)-1;i>=0;i--)
    {
        if(record[i] >= 'a' && record[i] <= 'z')
        {
            r += (record[i]-87)*pow(16.0,j);
        }
        else r = r+((record[i]-'0')*pow(16.0,j));
        j++;
    }
    printf("%lld ",r);
}
int main()
{
    char str[100001]={0};
    gets(str);
    int i,j,flag=0,begin,end;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i] == '0' && str[i+1] == 'x')
        {
            flag=1;
            begin = i+2;
            end = i+2;
            while(str[end])
            {
                if(str[end] == '0' && str[end+1] == 'x')
                    break;
                end++;
            }
            int temp = end - begin;
            for(j=0;j<=temp && str[begin] <= 'f';j++)
                record[j] = str[begin++];
            STtoTEN(record);
            i=end-1;
        }
    }
    if(flag == 0) printf("-1");
    return 0;
}