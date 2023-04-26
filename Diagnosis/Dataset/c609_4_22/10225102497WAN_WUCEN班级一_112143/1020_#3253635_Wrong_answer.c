#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int strnumcmp(const void * a, const void * b)
{   int i=0,number=0,pta=0,ptb=0,digita[31]={0},digitb[31]={0},j=0,digitaa[32],digitbb[32];
    for(i=0;*((char*)a+i)!='\0';i++)
        if(isdigit(*((char*)a+i))){number++;pta=i;break;}
    for(i=0;*((char*)b+i)!='\0';i++)
        if(isdigit(*((char*)b+i))){number+=2;ptb=i;break;}
    if(number==1)return 1;
    if (number==2)return -1;
    if(!number)
    for(i=0;;i++)
        {if(*((char*)a+i)=='\0'&&*((char*)b+i)=='\0')return 0;
        if(*((char*)a+i)=='\0')return -1;
        if(*((char*)b+i)=='\0')return 1;
        if(*((char*)a+i)>*((char*)b+i))return 1;
        if(*((char*)a+i)<*((char*)b+i))return -1;
        }
    else {for(j=0;pta<31;pta++)
            if(isdigit(*((char*)a+pta))){digita[pta]=*((char*)a+pta)-47;digitaa[j++]=digita[pta];}
          for(j=0;ptb<31;ptb++)
            if(isdigit(*((char*)b+ptb))){digitb[ptb]=*((char*)b+ptb)-47;digitbb[j++]=digitb[pta];}
          j=0;
          for(i=0;i<31;i++)
            if(digitaa[j++]!=digitbb[j++])return digitaa[j-1]-digitbb[j-1];
          j=0;
          for(i=0;i<31;i++)
            if(digita[j++]!=digitb[j++])return digita[j-1]-digitb[j-i];}
    for(i=0;;i++)
        {if(*((char*)a+i)=='\0'&&*((char*)b+i)=='\0')return 0;
        if(*((char*)a+i)=='\0')return -1;
        if(*((char*)b+i)=='\0')return 1;
        if(*((char*)a+i)>*((char*)b+i))return 1;
        if(*((char*)a+i)<*((char*)b+i))return -1;
        }
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
