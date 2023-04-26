#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char prime[6][4]={"the","a","an","of","for","and"};

void strlwr(char s[])
{
    for(int i=0;i<strlen(s);i++)
    if(s[i]>='A'&&s[i]<='Z')s[i]+=32;
}

int main()
{
    int T,t;scanf("%d",&T);char s[101];
    for(t=0;t<T;t++)
    {
        int d=0;
        printf("case #%d:\n",t);getchar();
        do
        {
            scanf("%s",s);int flag=-1;
            for(int i=0;i<6;i++)if(strcmp(prime+i,strlwr(s))==0)flag=0;
            if(flag==-1)d++;
        }while(getchar()!='\n');
        printf("%d\n",d);
    }
}
