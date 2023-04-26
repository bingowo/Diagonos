#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *s=(char *)malloc(100000*sizeof(char));
    scanf("%s",s);
    int i=0;
    int cnt=0;
    while(s[i+2])
    {
        if(s[i]=='0'&&s[i+1]=='x'&&s[i+2]<'f')
        {
            cnt++;
            int it=i+2;
            unsigned int sum=0;
            while(s[it]<'f'&&s[it]>='0')
            {
                if(s[it]<='9')sum=sum*16+s[it]-'0';
                else sum=sum*16+s[it]-'a'+10;
                it++;
            }
            printf("%u ",sum);
        }
        i++;
    }
    if(cnt==0)printf("%d",-1);
    //printf("%s",s);
    free(s);
    return 0;
}
