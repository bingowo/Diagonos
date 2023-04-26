#include <stdio.h>
#include <stdlib.h>

char *reject[35]={"the","The","tHe","thE","THe","tHE","ThE","THE",
    "a","A",
    "an","An","AN","aN",
    "of","Of","OF","oF",
    "For","for","fOr","foR","FOr","FoR","fOR","FOR",
    "and","And","aNd","anD","ANd","AnD","ANd","AND"
};

int main()
{
   int T;
   scanf("%d",&T);
   getchar();
   for(int tag=0;tag<T;tag++)
   {
       printf("case #%d:\n",tag);
       int count=0;
       char ch;
       do{
        char s[20];

        scanf("%s",s);
        //printf("%s\n",s);
        ch=getchar();
         int flag=0;
        for(int i=0;i<34;i++)
        {
            char *p;
            p=*(reject+i);


            if(strcmp(s,p)==0)
            {
                flag=1;
            }
        }
        if(!flag)
        {
          count++;
        }
       }while(ch!='\n');
       printf("%d\n",count);
   }
}