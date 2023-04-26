#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()

{
    int n,flag=0,sp=0;
    scanf("%d",&n);
    char s[105];
    for(int i=0;i<n;i++){
        scanf("%s",s);
        char* c=s;
        while((*c)!='\0'){
            if((*c)=='{'){c++;if(sp){flag=1;break;}sp=1;if((*c)!='['){flag=1;break;}}
            if((*c)=='['){c++;if(sp){if((*(c-2))=='{'){flag=1;break;}}if(!sp)sp=2;if((*c)!='('){flag=1;break;}}
            if((*c)=='('){c++;if(sp){if((*(c-2))=='['){flag=1;break;}}if(!sp)sp=3;if((*c)!=')'){flag=1;break;}}
            if((*c)==')'){c++;if(sp==3)sp=0;if((*(c-2))!='('){flag=1;break;}}
            if((*c)==']'){c++;if(sp==2)sp=0;if((*(c-2))!=')'){flag=1;break;}}
            if((*c)=='}'){c++;if(sp==1)sp=0;if((*(c-2))!=']'){flag=1;break;}}


        }
        if(flag)printf("No\n");
        else printf("Yes\n");

    }
    return 0;
}
