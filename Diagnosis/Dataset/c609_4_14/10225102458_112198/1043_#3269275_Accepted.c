#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()

{
    int n;
    scanf("%d",&n);
    char s[105];
    for(int i=0;i<n;i++){
        int flag=0,sp=0;
        scanf("%s",s);
        char* c=s;//考虑一种情况即可，没必要左右两边都考虑，sp表示的是栈有没有空。
        while((*c)!='\0'){
            if((*c)=='{'){c++;if(sp){if((*(c-2))!='('&&(*(c-2))!='}'){flag=1;break;}}sp++;}
            if((*c)=='['){c++;if(sp){if((*(c-2))!='{'&&(*(c-2))!=']'){flag=1;break;}}sp++;}
            if((*c)=='('){c++;if(sp){if((*(c-2))!='['&&(*(c-2))!=')'){flag=1;break;}}sp++;}

            if((*c)==')'){c++;if(sp==0||((*(c-2))!='('&&(*(c-2))!='}')){flag=1;break;}sp--;}
            if((*c)==']'){c++;if(sp==0||(*(c-2))!=')'){flag=1;break;}sp--;}
            if((*c)=='}'){c++;if(sp==0||(*(c-2))!=']'){flag=1;break;}sp--;}


        }
        if(sp==0 && flag==0)printf("Yes\n");
        else printf("No\n");

    }
    return 0;
}
