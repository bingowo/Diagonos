#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int b[101];
int main()
{
    int t;
    scanf("%d",&t);
    char s[101];

    for (int i=0; i<t; i++)
    {
        scanf("%s",s);
        printf("case #%d:\n",i);
        memset(b,0,sizeof(b));
        int len=strlen(s);
        if (len==1)
        {
            if (s[0]=='9') printf("10\n");
            else printf("%c\n",s[0]+1);
        }
        else
        {
            int find=0;
            int count=strlen(s)-1;
            s[count]+=1;
            while (find==0)
            {
                int find1=0;
                for (int j=0; j<count; j++)
                    if(s[j]==s[j+1]||s[j+1]>'9')
                    {
                        count=j+1;
                        find1=1;
                        break;
                    }

                if (find1)
                {
                    s[count]+=1;
                    
                    if (s[count]>'9')
                    {
                        count--;
                        s[count]+=1;
                        
                        if (s[count]>'9') {
                            if (count==0) {count=-1;find=1;}
                            else {count--;s[count]+=1;}
                        }
                    }
                }
                else find=1;
            }
            if (count==-1) printf("1");
            for (int j=0;j<=count;j++) printf("%c",s[j]);
            int start;
            if (count==-1) start=0;
            else if(s[count]==0) start=1;
            else start=0;
            for (int j=count+1;j<strlen(s);j++){printf("%d",start);start=1-start;}
            printf("\n");

        }
    }
}
