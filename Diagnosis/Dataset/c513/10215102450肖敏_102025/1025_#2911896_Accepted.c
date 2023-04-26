#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i <T;i++)
    {
        int n;
        scanf("%d",&n);
        char s[n][21];
        int j = 0,k=0;

        for(j = 0;j <n;j++)
        {
            scanf("%s",s[j]);
        }
        int count(char *c)
        {
            int num=0,x=0,y=0;
            int len=strlen(c);
            num = len;
            for(x = 0;x<len;x++)
            {
                for(y = x+1;y< len;y++)
                {
                    if(c[x] == c[y])
                    {
                        num --;
                        break;
                    }
                }
            }
            return num;
        }
        int cmp(const void *a,const void *b)
        {
            int count1,count2;
            char *str1,*str2;
            str1=*(char (*)[21])a; str2=*(char (*)[21])b;
            count1=count(str1);
            count2=count(str2);
            if(count1==count2)
                return strcmp(str1,str2);
            else
                return count2-count1;
        }
        qsort(s,n,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(int z=0;z<n;z++)
            printf("%s\n",s[z]);
    }
    return 0;
}
