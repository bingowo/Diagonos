#include <stdio.h>
#include <stdlib.h>
int pd(char s[20],int a,int k)
{
    switch(s[0])
    {
        case 'A':a=a+k;
        case 'S':a=a-k;
        case 'M':a=a*k;
        case 'D':a=a/k;
    }
    return a;
}
int main()
{
    char s[20]={0};int a=0,b=0,c=0,d=0;
    while(scanf("%s",s)!=EOF)
    {
        char t[20]={0};int i=0,k=0,g=0;
        if(strcmp(s,"IN")==0)
        {
            scanf("%s",t);
            for(i=0;t[i];i++){if(isdigit(t[i]))k=k*10+t[i]-'0';}
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
                case 'A':a=pd(s,a,k);break;
                case 'B':b=pd(s,b,k);;break;
                case 'C':c=pd(s,c,k);;break;
                case 'D':d=pd(s,d,k);;break;
            }
        }
        if(strcmp(s,"OUT")==0)
        {
            scanf("%s",t);
            switch(t[0])
            {
                case 'A':printf("%d",a);break; case 'B':printf("%d",b);break;
                case 'C':printf("%d",c);break; case 'D':printf("%d",d);break;
            }
        }
    }
    return 0;
}
