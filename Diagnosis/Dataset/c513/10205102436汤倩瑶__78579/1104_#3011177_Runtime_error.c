#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[5];
    int x[30]={0};
    while(scanf("%s ",s)!=EOF)
    {

        char s1[10];
        char c;
        int n;
        if(strcmp(s,"IN")==0)
        {
            scanf("%[^,]",s1);
            scanf("%c%d",&c,&n);
            x[s1[0]-'A']=n;
        }
        else if(strcmp(s,"OUT")==0)
        {

            scanf("%s",s1);
            printf("%d\n",x[s1[0]-'A']);
        }
        else
        {

            scanf("%s",s1);
            int l=strlen(s1);

            int tmp;
            int *f1,*f2,*f3;
            f1=&x[s1[0]-'A'];
            f2=&x[s1[3]-'A'];
            if(strcmp(s,"MOV")==0)*f1=*f2;
            if(strcmp(s,"XCHG")==0)
            {
                tmp=*f2;
                *f2=*f1;
                *f1=tmp;
            }

            if(l==5){
            if(strcmp(s,"ADD")==0)*f1=(*f1)+(*f2);
            if(strcmp(s,"SUB")==0)*f1=(*f1)-(*f2);
            if(strcmp(s,"MUL")==0)*f1=(*f1)*(*f2);
            if(strcmp(s,"DIV")==0)*f1=(*f1)/(*f2);
            if(strcmp(s,"MOD")==0)*f1=(*f1)%(*f2);
            if(strcmp(s,"AND")==0)*f1=(*f1)&(*f2);
            if(strcmp(s,"OR")==0)*f1=(*f1)|(*f2);
            if(strcmp(s,"NOR")==0)*f1=(*f1)^(*f2);
        }
        if(l==8){
            f3=&x[s1[6]-'A'];
            if(strcmp(s,"ADD")==0)*f1=(*f2)+(*f3);
            if(strcmp(s,"SUB")==0)*f1=(*f2)-(*f3);
            if(strcmp(s,"MUL")==0)*f1=(*f2)*(*f3);
            if(strcmp(s,"DIV")==0)*f1=(*f2)/(*f3);
            if(strcmp(s,"MOD")==0)*f1=(*f2)%(*f3);
            if(strcmp(s,"AND")==0)*f1=(*f3)&(*f3);
            if(strcmp(s,"OR")==0)*f1=(*f2)|(*f3);
            if(strcmp(s,"NOR")==0)*f1=(*f2)^(*f3);



        }

        }



    }
}
