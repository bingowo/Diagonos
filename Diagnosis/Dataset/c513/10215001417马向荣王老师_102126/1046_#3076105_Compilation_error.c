#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

char prime[6][4]={"the","a","an","of","for","and"};

int main()
{
    int T,t;scanf("%d",&T);char s[101];
    for(t=0;t<T;t++)
    {
        int d=0;
        printf("case #%d:\n",t);
        do
        {
            scanf("%s",s);int flag=-1;
            for(int i=0;i<6;i++)if(strcmp(prime+i,strler(s))==0)flag=0;
            if(flag==-1)d++;
        }while(getchar()!='\n');
        printf("%d\n",d);
    }
}
