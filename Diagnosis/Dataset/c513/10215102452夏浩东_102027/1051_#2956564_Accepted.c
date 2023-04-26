#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int* func(int num,int begin,int*L)
{
    int k=7;
    while(num>0)
    {
        L[begin+k]=num%2;
        num=num/2;
        k--;
    }
    return L;
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    char s[101]; 
    for(int j=0;j<cnt;j++)
    {
        scanf("%s",s);
        printf("case #%d:\n",j);
        int len=(int)strlen(s);
        int nn=0;
        for(int i=0;i<len/3;i++)
        {
            int *L=(int*)malloc(24*sizeof(int));
            for(int u=0;u<24;u++) L[u]=0;
            int num=0;
            int begin=0;
            for(int t=0;t<3;t++)
            {
                num=(int)s[nn++];
                L=func(num,begin,L);
                begin+=8;
            }
            for(int k=0;k<24;k+=6)
            {
                int res=0;
                for(int m=k;m<k+6;m++) res=res*2+L[m];
                if(res<=25) printf("%c",(char)('A'+res));
                else if(res<=51) printf("%c",(char)('a'+res-26));
                else if(res<=61) printf("%c",(char)('0'+res-52));
                else if(res==62) printf("+");
                else if(res==63) printf("/");
            }
            free(L);
        }
        int *L=(int*)malloc(24*sizeof(int));
        for(int u=0;u<24;u++) L[u]=0;
        int num=0,res=0;
        if(len%3==1)
        {
            num=(int)s[nn];
            L=func(num,0,L);
            for(int i=0;i<12;i++)
            {
                res=res*2+L[i];
                if(i==5 || i==11)
                {
                    if(res<=25) printf("%c",(char)('A'+res));
                    else if(res<=51) printf("%c",(char)('a'+res-26));
                    else if(res<=61) printf("%c",(char)('0'+res-52));
                    else if(res==62) printf("+");
                    else if(res==63) printf("/");
                    res=0;
                }
            }
            printf("==");
        }
        else if(len%3==2)
        {
            num=(int)s[nn];
            L=func(num,0,L);
            num=(int)s[nn+1];
            L=func(num,8,L);
            for(int i=0;i<18;i++)
            {
                res=res*2+L[i];
                if(i==5 || i==11 || i==17)
                {
                    if(res<=25) printf("%c",(char)('A'+res));
                    else if(res<=51) printf("%c",(char)('a'+res-26));
                    else if(res<=61) printf("%c",(char)('0'+res-52));
                    else if(res==62) printf("+");
                    else if(res==63) printf("/");
                    res=0;
                }
            }
            printf("=");
        }
        printf("\n");
        free(L);
    }
    return 0;
}