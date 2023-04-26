#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include<string.h>
#include<malloc.h>

static char tab_code[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};
static int tab_mode[]={0,2,1};

char*base64(const unsigned char*data,char*data_code)
{
    int len1=strlen(data);
    int len2=4*((len1+2)/3);
    if(data_code==NULL) return NULL;
    else
    {
        for(int i=0,j=0;i<len1;)
        {
            uint32_t a=i<len1?(unsigned char)data[i++]:0;
            uint32_t b=i<len1?(unsigned char)data[i++]:0;
            uint32_t c=i<len1?(unsigned char)data[i++]:0;
            uint32_t t=(a<<0x10)+(b<<0x8)+c;
            data_code[j++]=tab_code[(t>>3*6)&0x3F];
            data_code[j++]=tab_code[(t>>2*6)&0x3F];
            data_code[j++]=tab_code[(t>>1*6)&0x3F];
            data_code[j++]=tab_code[(t>>0*6)&0x3F];
        }
        for(int i=0;i<tab_mode[len1%3];++i)
        {
            data_code[len2-i-1]='=';
        }
        data_code[len2]=0;
        return data_code;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;++i)
    {
        char s[101];
        scanf("%s",s);
        char*c=malloc(256*sizeof(char));
        base64(s,c);
        printf("case #%d:\n",i);
        printf("%s\n",c);
    }
    return 0;
}
