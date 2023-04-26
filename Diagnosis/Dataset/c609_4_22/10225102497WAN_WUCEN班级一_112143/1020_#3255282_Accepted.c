#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int strnumcmp(const void * a, const void * b)
{   int i=0,number=0,pta=0,ptb=0;
    char digitaa[32],digitbb[32];
    for(i=0;*((char*)a+i)!='\0';i++)
        if(isdigit(*((char*)a+i))){number++;pta=i;break;}
    for(i=0;*((char*)b+i)!='\0';i++)
        if(isdigit(*((char*)b+i))){number+=2;ptb=i;break;}
    if(number==1)return 1;
    if (number==2)return -1;
    if(!number)
        return strcmp((char*)a,(char*)b);
    else {for(i=0;pta<31&&*((char*)a+pta)!='\0';pta++)
            if(isdigit(*((char*)a+pta))) digitaa[i++]=*((char*)a+pta);
          digitaa[i]='\0';
          for(i=0;ptb<31&&*((char*)b+ptb)!='\0';ptb++)
            if(isdigit(*((char*)b+ptb))) digitbb[i++]=*((char*)b+ptb);
          digitbb[i]='\0';
          if(atoi(digitaa)!=atoi(digitbb))return atoi(digitaa)-atoi(digitbb);}
    return strcmp((char*)a,(char*)b);
}

int main()
{
    char string[100][31];
    short i=0,j=0;
    while(scanf("%s",string[i])!=EOF) i++;
        qsort(string,i,sizeof(string[0]),strnumcmp);
    for(j=0;j<i;j++)
        printf("%s ",string[j]);
    return 0;
}
