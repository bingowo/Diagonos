#include<stdio.h>
#include<string.h>
#define maxn 5001

int main()
{
    int n;scanf("%d",&n);
    char dictionary[n][15];
    for(int i=0;i<n;i++) scanf("%s",dictionary[i]);
    char line[maxn];scanf("%s",line);
    int p=0,l=strlen(line);
    while(p<l)
    {
        int flag;
        for(int i=n-1;i>=0;i--)
        {
            int l_tmp=strlen(dictionary[i]);
            flag = 1;
            for(int j=p;j<p+l_tmp;j++)
            {
                if(line[j]!=dictionary[i][j-p])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                printf("%s ",dictionary[i]);
                p += l_tmp;
                break;
            }
        }
        if(!flag)
            printf("%c ",line[p++]);
    }

    return 0;
}