#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int strnumcmp(const void * a, const void * b)
{   int i=0,number=0,pta=0,ptb=0;
    for(i=0;*(*(char**)a+i)!='\0';i++)
        if(isdigit(*(*(char**)a+i))){number++;pta=i;break;}
    for(i=0;*(*(char**)b+i)!='\0';i++)
        if(isdigit(*(*(char**)b+i))){number+=2;ptb=i;break;}
    if(number==1)return 1;
    if (number==2)return -1;
    if(!number)
    for(i=0;;i++)
        {if(*(*(char**)a+i)=='\0'&&*(*(char**)b+i)=='\0')return 0;
        if(*(*(char**)a+i)=='\0')return -1;
        if(*((char*)b+i)=='\0')return 1;
        if(*(*(char**)a+i)>*(*(char**)b+i))return 1;
        if(*(*(char**)a+i)<*(*(char**)b+i))return -1;
        }
    else for(;;)
            {   pta++;
                ptb++;
                if (!isdigit(*(*(char**)a+pta)))
                {if(isdigit(*(*(char**)b+ptb)))return -1;
                else return 0;}
            if(!isdigit(*(*(char**)b+ptb)))return 1;
            if(*(*(char**)a+pta)-48>*(*(char**)b+ptb)-48)return 1;
            if(*(*(char**)a+pta)-48<*(*(char**)b+ptb)-48)return -1;}
}

int main()
{
    char **string;
    char i=0,j=0;
    string=(char**)malloc(100*sizeof(char*));
    for(i=100;i>0;i--)
        *(string+i-1)=(char*)malloc(31*sizeof(char));
    while(scanf("%s",*(string+i))!=EOF) i++;
        qsort(string,sizeof(string)/sizeof(*string),sizeof(char*),strnumcmp);
    for(j=0;j<i;j++)
        printf("%s ",*(string+i));
    return 0;
}
