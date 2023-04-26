#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[5];
    int ax,bx,cx,dx;
    while(scanf("%s ",s)!=EOF)
    {

        char s1[5],s2[5];
        char c;
        int n;
        if(strcmp(s,"IN")==0)
        {
            scanf("%[^,]",s1);
            scanf("%c%d",&c,&n);
            if(strcmp(s1,"AX")==0)ax=n;
            if(strcmp(s1,"BX")==0)bx=n;
            if(strcmp(s1,"CX")==0)cx=n;
            if(strcmp(s1,"DX")==0)dx=n;
        }
        else if(strcmp(s,"OUT")==0)
        {
            int ans;
            scanf("%s",s1);
            if(strcmp(s1,"AX")==0)ans=ax;
            if(strcmp(s1,"BX")==0)ans=bx;
            if(strcmp(s1,"CX")==0)ans=cx;
            if(strcmp(s1,"DX")==0)ans=dx;
            printf("%d\n",ans);
        }
        else
        {
            scanf("%[^,]",s1);
            scanf("%c%s",&c,s2);

            int *f1,*f2;
            if(strcmp(s1,"AX")==0)f1=&ax;
            if(strcmp(s1,"BX")==0)f1=&bx;
            if(strcmp(s1,"CX")==0)f1=&cx;
            if(strcmp(s1,"DX")==0)f1=&dx;
            if(strcmp(s2,"AX")==0)f2=&ax;
            if(strcmp(s2,"BX")==0)f2=&bx;
            if(strcmp(s2,"CX")==0)f2=&cx;
            if(strcmp(s2,"DX")==0)f2=&dx;
            if(strcmp(s,"MOV")==0)*f1=*f2;
            if(strcmp(s,"ADD")==0)*f1=(*f1)+(*f2);
            if(strcmp(s,"SUB")==0)*f1=(*f1)-(*f2);
            if(strcmp(s,"MUL")==0)*f1=(*f1)*(*f2);
            if(strcmp(s,"DIV")==0)*f1=(*f1)/(*f2);



        }



    }
}
