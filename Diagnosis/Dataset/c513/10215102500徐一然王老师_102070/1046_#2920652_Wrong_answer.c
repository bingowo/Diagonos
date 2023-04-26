#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main()
{

static char* dic[]={"the","a","an","of","for","and"};
    int count,count1,num=0;
    scanf("%d\n",&count);
    count1=count;
    char S[101];
    char*p=S;
    char*p1=S;
    while(count--)
    {

        gets(S);
        while(*p)
        {
            char *copy=malloc(101*sizeof(char));
            char*p2=copy;
            while(*p1!=' '&&*p1)
            {
                *p2=*p1;
                p1++;
                p2++;
            }
            *p2='\0';

            for(int i=0;i<6;i++)
            {
                if(strcmp(dic[i],copy)==0)
                {
                    break;
                }
                if(i==5)num++;
            }
            p=p1;
            p1++;
            free(copy);
        }
        printf("case #%d:\n",count1-count-1);
        printf("%d\n",num);
        num=0;
        p=S;
        p1=S;
    }
}
