#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    char s[105];
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%s",s);
        int l=strlen(s);
        char stack[105]={0};
        int cnt=0;

        int flag=1;
        for(int j=0;(j<l)&&(flag==1);j++)
        {


            if(cnt==0)
            {

               stack[cnt++]=s[j];
                continue;
          }


            switch(s[j])
            {
        case '(':
            if(stack[cnt-1]== '[')
            {
                stack[cnt++]=s[j];
            }
            else{
                flag = 0;

            }
            break;

        case')':
            if(stack[cnt-1] == '(')
            {
               cnt--;
            }
            else{
                flag = 0;

            }
            break;



        case '[':
            if(stack[cnt-1]== '{')
            {
               stack[cnt++]=s[j];
            }
            else{
                flag = 0;

            }
            break;


        case']':
            if(stack[cnt-1]== '[')
            {
                cnt--;
            }
            else{
                flag = 0;

            }
            break;





        case '{':
            if(stack[cnt-1]== '(')
            {
                 stack[cnt++]=s[j];
            }
            else{
                flag = 0;

            }
            break;


        case'}':
            if(stack[cnt-1]== '{')
            {
                cnt--;
            }
            else{
                flag = 0;

            }
            break;



            }


           }
        if(cnt==0&&flag==1)printf("Yes\n");
        else printf("No\n");
    }
}

