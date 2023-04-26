#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char c;
    int m;
}point;
int pd(char s[200],int a,int k)
{
    if(strcmp(s,"MOD")==0){a=a%k;return a;}
    if(strcmp(s,"AND")==0){a=a&k;return a;}
    switch(s[0])
    {
        case 'A':a=a+k;break;
        case 'S':a=a-k;break;
        case 'M':a=a*k;break;
        case 'D':a=a/k;break;
        case 'O':a=a|k;break;
        case 'X':a=a^k;break;
    }
    return a;
}
int main()
{
    char s[200]={0};
    point p[26]={'A',0,'B',0,'C',0,'D',0,'E',0,'F',0,'G',0,'H',0,'I',0,'J',0,'L',0,'M',0,'N',0,
    'O',0,'P',0,'Q',0,'R',0,'S',0,'T',0,'U',0,'V',0,'W',0,'X',0,'Y',0,'Z',0};
    while(scanf("%s",s)!=EOF)
    {
        char t[200]={0};int i=0,k=0,g=0,f=1;
        if(strcmp(s,"IN")==0)
        {
            scanf("%s",t);
            for(i=0;t[i];i++){if(t[i]=='-')f=-1;if(isdigit(t[i]))k=k*10+t[i]-'0';}k=k*f;
            for(i=0;i<26;i++){if(t[0]==p[i].c){p[i].m=k;break;}}
        }
        if(strcmp(s,"MOV")==0)
        {
            scanf("%s",t);
            for(i=0;i<26;i++){if(t[3]==p[i].c){k=p[i].m;break;}}
            for(i=0;i<26;i++){if(t[0]==p[i].c){p[i].m=k;break;}}
        }
        if(strcmp(s,"XCHG")==0)
        {
            scanf("%s",t);
            for(i=0;i<26;i++){if(t[3]==p[i].c){k=p[i].m;break;}}
            for(i=0;i<26;i++){if(t[0]==p[i].c){g=p[i].m;p[i].m=k;break;}}
            for(i=0;i<26;i++){if(t[3]==p[i].c){p[i].m=g;break;}}

        }
         if(strcmp(s,"ADD")==0 ||strcmp(s,"SUB")==0 ||strcmp(s,"MUL")==0 ||strcmp(s,"DIV")==0||strcmp(s,"MOD")==0||strcmp(s,"AND")==0
            ||strcmp(s,"OR")==0||strcmp(s,"XOR")==0)
        {
            scanf("%s",t);

           if(t[6]){
                for(i=0;i<26;i++){if(t[6]==p[i].c){k=p[i].m;break;}}
                for(i=0;i<26;i++){if(t[3]==p[i].c){g=pd(s,p[i].m,k);break;}}
                for(i=0;i<26;i++){if(t[0]==p[i].c){p[i].m=g;break;}}
           }
           else{for(i=0;i<26;i++){if(t[3]==p[i].c){k=p[i].m;break;}}
               for(i=0;i<26;i++){if(t[0]==p[i].c){g=pd(s,p[i].m,k);p[i].m=g;break;}}
           }
        }

        if(strcmp(s,"OUT")==0)
        {
            scanf("%s",t);
            for(i=0;i<26;i++){if(t[0]==p[i].c){printf("%d\n",p[i].m);break;}}
        }
    }
    return 0;
}
