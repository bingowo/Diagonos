#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[10]={0};
    int a=0,b=0,cc=0,d=0;
    while(scanf("%s",s)!=EOF)
    {
        if(strcmp(s,"IN")==0)
        {
            char x[5]={0};
            int flag=0;
            char c=getchar();
            while((c=getchar())!=',')
            {
                x[flag]=c;
                flag++;
            }
            int in;
            scanf("%d\n",&in);
            if(strcmp(x,"AX")==0) a=in;
            if(strcmp(x,"BX")==0) b=in;
            if(strcmp(x,"CX")==0) cc=in;
            if(strcmp(x,"DX")==0) d=in;
            //printf("%d %d %d %d\n",a,b,cc,d);
        }
        if(strcmp(s,"MOV")==0)
        {
            char x0[5]={0};
            char x1[5]={0};
            int flag=0;
            char c=getchar();
            while((c=getchar())!=',')
            {
                x0[flag]=c;
                flag++;
            }
            flag=0;
            while((c=getchar())!='\n')
            {
                x1[flag]=c;
                flag++;
            }
            int temp=0;
            if(strcmp(x1,"AX")==0) temp=a;
            if(strcmp(x1,"BX")==0) temp=b;
            if(strcmp(x1,"CX")==0) temp=cc;
            if(strcmp(x1,"DX")==0) temp=d;
            if(strcmp(x0,"AX")==0) a=temp;
            if(strcmp(x0,"BX")==0) b=temp;
            if(strcmp(x0,"CX")==0) cc=temp;
            if(strcmp(x0,"DX")==0) d=temp;
            //printf("%d %d %d %d\n",a,b,cc,d);
        }
        if(strcmp(s,"ADD")==0)
        {
            char x0[5]={0};
            char x1[5]={0};
            int flag=0;
            char c=getchar();
            while((c=getchar())!=',')
            {
                x0[flag]=c;
                flag++;
            }
            flag=0;
            while((c=getchar())!='\n')
            {
                x1[flag]=c;
                flag++;
            }
            int temp=0;
            if(strcmp(x1,"AX")==0) temp=a;
            if(strcmp(x1,"BX")==0) temp=b;
            if(strcmp(x1,"CX")==0) temp=cc;
            if(strcmp(x1,"DX")==0) temp=d;
            if(strcmp(x0,"AX")==0) a+=temp;
            if(strcmp(x0,"BX")==0) b+=temp;
            if(strcmp(x0,"CX")==0) cc+=temp;
            if(strcmp(x0,"DX")==0) d+=temp;
            //printf("%d %d %d %d\n",a,b,cc,d);
        }
        if(strcmp(s,"SUB")==0)
        {
            char x0[5]={0};
            char x1[5]={0};
            int flag=0;
            char c=getchar();
            while((c=getchar())!=',')
            {
                x0[flag]=c;
                flag++;
            }
            flag=0;
            while((c=getchar())!='\n')
            {
                x1[flag]=c;
                flag++;
            }
            int temp=0;
            if(strcmp(x1,"AX")==0) temp=a;
            if(strcmp(x1,"BX")==0) temp=b;
            if(strcmp(x1,"CX")==0) temp=cc;
            if(strcmp(x1,"DX")==0) temp=d;
            if(strcmp(x0,"AX")==0) a-=temp;
            if(strcmp(x0,"BX")==0) b-=temp;
            if(strcmp(x0,"CX")==0) cc-=temp;
            if(strcmp(x0,"DX")==0) d-=temp;
            //printf("%d %d %d %d\n",a,b,cc,d);

        }
        if(strcmp(s,"MUL")==0)
        {
            char x0[5]={0};
            char x1[5]={0};
            int flag=0;
            char c=getchar();
            while((c=getchar())!=',')
            {
                x0[flag]=c;
                flag++;
            }
            flag=0;
            while((c=getchar())!='\n')
            {
                x1[flag]=c;
                flag++;
            }
            int temp=0;
            if(strcmp(x1,"AX")==0) temp=a;
            if(strcmp(x1,"BX")==0) temp=b;
            if(strcmp(x1,"CX")==0) temp=cc;
            if(strcmp(x1,"DX")==0) temp=d;
            if(strcmp(x0,"AX")==0) a*=temp;
            if(strcmp(x0,"BX")==0) b*=temp;
            if(strcmp(x0,"CX")==0) cc*=temp;
            if(strcmp(x0,"DX")==0) d*=temp;
            /*printf("%d %d %d %d\n",a,b,cc,d);*/

        }
        if(strcmp(s,"DIV")==0)
        {
            char x0[5]={0};
            char x1[5]={0};
            int flag=0;
            char c=getchar();
            while((c=getchar())!=',')
            {
                x0[flag]=c;
                flag++;
            }
            flag=0;
            while((c=getchar())!='\n')
            {
                x1[flag]=c;
                flag++;
            }
            int temp=0;
            if(strcmp(x1,"AX")==0) temp=a;
            if(strcmp(x1,"BX")==0) temp=b;
            if(strcmp(x1,"CX")==0) temp=cc;
            if(strcmp(x1,"DX")==0) temp=d;
            if(strcmp(x0,"AX")==0) a=a/temp;
            if(strcmp(x0,"BX")==0) b=b/temp;
            if(strcmp(x0,"CX")==0) cc=cc/temp;
            if(strcmp(x0,"DX")==0) d=d/temp;
            /*printf("%d %d %d %d\n",a,b,cc,d);*/

        }
        if(strcmp(s,"OUT")==0)
        {

            char x[5]={0};
            scanf("%s",x);
            if(strcmp(x,"AX")==0) printf("%d\n",a);
            if(strcmp(x,"BX")==0) printf("%d\n",b);
            if(strcmp(x,"CX")==0) printf("%d\n",cc);
            if(strcmp(x,"DX")==0) printf("%d\n",d);

        }
        for(int i=0;i<10;i++)
        {
            s[i]=0;
        }

    }
}
