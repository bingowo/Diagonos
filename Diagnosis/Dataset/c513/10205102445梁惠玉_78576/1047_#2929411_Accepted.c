#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        char s[501];
        scanf("%s",s);
        char ch=s[0];
        int count=1;
        for(int j=1;j<strlen(s);j++)
        {
           if(ch==s[j])
           {
               count++;
           }
           else{
                printf("%d%c",count,ch);
                ch=s[j];
                count=1;
           }
           if(count==255)
           {
               
               if((j+1)<strlen(s)){
                   printf("%d%c",count,ch);
                    ch=s[++j];
                    count=1;
               }
}
        }
        printf("%d%c\n",count,ch);
     

    }
    return 0;
}
