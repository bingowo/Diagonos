#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int T;
    int m,N,R;
    scanf("%d",&T);
    char s[1000];
    int j=0;
    for(int i=0;i<T;i++)
    {
        scanf("%d%d",&N,&R);
        m=N;
        if(N<0) m=-N;
        while(m/R!=0)
        {
            if(m%R>9)
            {
                s[j++]=m%R+'0'+7;
            }
            else
            {
                 s[j++]=m%R+'0';
            }
            m=m/R;
        }
            if(m%R>9)
            {
                s[j++]=m%R+'0'+7;
            }
            else
            {
                 s[j++]=m%R+'0';
            }
            s[j]='\0';
            if(N<0) printf("%c",45);
            int t;
            for(int k=0;k<strlen(s)/2;k++)
            {
                t=s[k];
                s[k]=s[strlen(s)-1-k];
                s[strlen(s)-1-k]=t;
            }
            printf("%s",s);
            printf("%c",'\n');
            j=0;
    }
}
