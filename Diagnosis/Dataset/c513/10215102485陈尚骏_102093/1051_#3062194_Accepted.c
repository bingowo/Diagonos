#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include<string.h>

static char encoding_tab[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','+','/'};

static int mod_tab[]={0,2,1};

char*base64_encode(const unsigned char*data,char*encoded_data)
{
    int iptlen=strlen(data);
    int optlen=4*((iptlen+2)/3);
    if(encoded_data==NULL) return NULL;
    for(int i=0,j=0;i<iptlen;)
    {
        uint32_t a=i<iptlen?(unsigned char)data[i++]:0;
        uint32_t b=i<iptlen?(unsigned char)data[i++]:0;
        uint32_t c=i<iptlen?(unsigned char)data[i++]:0;
        uint32_t trp=(a<<0x10)+(b<<0x08)+c;
        encoded_data[j++]=encoding_tab[(trp>>3*6)&0x3F];
        encoded_data[j++]=encoding_tab[(trp>>2*6)&0x3F];
        encoded_data[j++]=encoding_tab[(trp>>1*6)&0x3F];
        encoded_data[j++]=encoding_tab[(trp>>0*6)&0x3F];
    }
    for(int i=0;i<mod_tab[iptlen%3];i++)
    {
        encoded_data[optlen-1-i]='=';
    }
    encoded_data[optlen]=0;
    return encoded_data;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        char s[256];
        scanf("%s",s);
        char*c=malloc(256*sizeof(char));
        base64_encode(s,c);
        printf("case #%d:\n",i);
        printf("%s\n",c);
        free(c);
    }
    return 0;
}
