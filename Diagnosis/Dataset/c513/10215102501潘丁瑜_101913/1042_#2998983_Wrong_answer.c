#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b)
{
    return *(char *)a > *(char *)b;
}

int main()
{
    char s[17]={0};
    char chs[2]={0};
    
    char temp;
    int N;
    int len;
    char ch;
    int i,j=0,k=0,r;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%s",s);
        len = strlen(s);
        int klen=len;
        char a[200]={0};
        char b[200]={0};
        qsort(s,len,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        for(j=0;j<len;j++)
        {
            char str[17]={0};
            
            str[0]=s[j];
            ch = s[j];
            if(a[ch] == 0)
            {
                for(r=0;r<20;r++)
                {
                    temp=s[r];
                    b[temp] = 0;
                }
                   
                printf("%s\n",str);
            }
            a[ch] = '1';
            b[ch] = '1';
            for(k=j;k<klen;k++)
            {
                ch = s[k];
                chs[0] = s[k];
                if(b[ch] == 0)
                {
                    strcat(str,chs);
                    printf("%s\n",str);
                }
                b[ch] = '1';
               
            }
            //klen--;
            
        }
    }
    return 0;
}