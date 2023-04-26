#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[31];
        scanf("%s",s);
        long long int ans=0;
        int num=strlen(s)-1;
        char *p=s;
        while(*p!='\0')
        {
            if(*p=='1')
            {
                ans+=1*pow(3,num);
                num--;
                p++;
                
            }
            else if(*p=='-')
            {
                ans+=(-1)*pow(3,num);
                p++;
                num--;
                 
            }
            else{
                p++;
                num--;
        
            }
        }
        printf("%lld\n",ans);

    }
    return 0;
}