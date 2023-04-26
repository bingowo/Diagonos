#include <stdio.h>
#include <string.h>



int main()
{
    char c;
    while((c=getchar())!=EOF)
    {
         if(c=='"')
         {
             printf("%c",c);
             while(1)
             {
                 c=getchar();
                 if(c!=';')
                 {
                     if(c=='"')
                     {
                         printf("%c",c);
                         c=getchar();
                         if(c=='\n')
                         {
                             printf("%c",c);
                             break;
                         }
                         else
                         {
                             printf("%c",c);
                         }
                     }
                     else
                     printf("%c",c);
                 }
                 else
                 {
                     printf("%c",c);
                     break;
                 }


             }

         }

         else if(c=='\'')
         {
             printf("%c",c);
             while(1)
             {
                 c=getchar();
                 if(c!=';')
                 {
                     printf("%c",c);
                 }
                 else
                 {
                     printf("%c",c);
                     break;
                 }


             }
         }

         else if(c=='/')
         {
             c=getchar();
             if(c=='/')
             {
                 while((c=getchar())!=EOF)
                 {
                    if(c=='\n')
                    {
                        printf("%c",c);
                        break;
                    }
                 }
             }
             else if(c=='*')
             {
                 while(1)
                 {
                     c=getchar();

                     if(c=='*')
                     {
                         c=getchar();
                         if(c=='/')
                         {
                             break;
                         }
                         else
                         {
                             while(c!='/'&&(c=getchar())!=EOF)
                             {
                                 ;
                             }
                             if(c=='/')
                         {
                             break;
                         }
                         }
                     }
                 }

             }
         }

        else
            printf("%c",c);

    }


    return 0;
}
