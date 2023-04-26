#include <stdio.h>
#include <stdlib.h>
long long pd(char s[200],long long a,long long k)
{
    switch(s[0])
    {
        case 'A':a=a+k;break;
        case 'S':a=a-k;break;
        case 'M':a=a*k;break;
        case 'D':a=a/k;break;
    }
    return a;
}
int main()
{
    char s[200]={0};long long a=0,b=0,c=0,d=0;
    while(scanf("%s",s)!=EOF)
    {
        char t[200]={0};long long i=0,k=0,g=0,f=1;
        if(strcmp(s,"IN")==0)
        {
            scanf("%s",t);
            for(i=0;t[i];i++){if(t[i]=='-')f=-1;if(isdigit(t[i]))k=k*10+t[i]-'0';}k=k*f;
            switch(t[0])
            {
                case 'A':a=k;break; case 'B':b=k;break;
                case 'C':c=k;break; case 'D':d=k;break;
            }
        }
        if(strcmp(s,"MOV")==0)
        {
            scanf("%s",t);
            switch(t[3])
            {
                case 'A':k=a;break; case 'B':k=b;break;
                case 'C':k=c;break; case 'D':k=d;break;
            }
            switch(t[0])
            {
                case 'A':a=k;break; case 'B':b=k;break;
                case 'C':c=k;break; case 'D':d=k;break;
            }
        }
         if(strcmp(s,"ADD")==0 ||strcmp(s,"SUB")==0 ||strcmp(s,"MUL")==0 ||strcmp(s,"DIV")==0)
        {
            scanf("%s",t);
            switch(t[3])
            {
                case 'A':k=a;break; case 'B':k=b;break;
                case 'C':k=c;break; case 'D':k=d;break;
            }
            switch(t[0])
            {
                case 'A':g=pd(s,a,k);a=g;break;
                case 'B':g=pd(s,b,k);b=g;break;
                case 'C':g=pd(s,c,k);c=g;break;
                case 'D':g=pd(s,d,k);d=g;break;
            }
        }

        if(strcmp(s,"OUT")==0)
        {
            scanf("%s",t);
            switch(t[0])
            {
                case 'A':printf("%lld\n",a);break; case 'B':printf("%lld\n",b);break;
                case 'C':printf("%lld\n",c);break; case 'D':printf("%lld\n",d);break;
            }
        }
    }
    return 0;
}
