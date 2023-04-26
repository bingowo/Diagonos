#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

#define maxn 51
int cmp(const void* a, const void* b)
{
    char* a1 = (char *)a;
    char* b1 = (char *)b;
    if(strcmp(a1,b1)>0) return 1;
    else if(strcmp(a1,b1)<0) return -1;
    else return 0;
}

int main(void)
{
    int t;
//    char *s=(char*)malloc(sizeof(char)*501);
    char word[501][501];
    char w[501];
    scanf("%d",&t);
    getchar();

    for(int i=0;i<t;i++)
    {
        char *s=(char*)malloc(sizeof(char)*501);
        int num=0;
        gets(s);
        char *p=s;
        while((*p)!='\0')
        {
//            printf("%c",*p);
            if(isspace(*p) || ispunct(*p)) p++;
            else
            {
                char* p2=p+1;
                while(*p2 && *p2 != ' '&& *p2 != ',' && *p2 != '.' && *p2 != '!' && *p2 != '?')
                {
                    p2++;
                }
                int len=p2-p;

                strncpy(w,p,len);
                p=p2;

                w[len]='\0';
//                printf("!!!%s\n",w);
                int flag=0;
                for(int j = 0;j<num;j++)
                {
                    if (strcmp(w,*(word+j))==0)
                        flag=1;
                }
                if(flag==0)
                {
                    strcpy(*(word+num),w);
                    num++;
                }

            }
        }
//        printf("%s",*(word+1));
        qsort(word,num,sizeof(word[0]),cmp);
//        printf("%s\n",word[1]);
        for(int k= 0;k<num;k++)
        {
            printf("%s%c",*(word+k),(k==num-1?'\n':' '));
        }
        free(s);
    }
    return 0;

}
