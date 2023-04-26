#include<stdio.h>
#include<string.h>
int main()
{
    int T,cnt=0;
    scanf("%d",&T);
    char base64_chart[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
    while(T)
    {
        printf("case #%d:\n",cnt);
        char src[1024],res[1024];
        getchar();
        gets(src);
        int len=strlen(src);
        int pos,index,bits,ret;
        pos=0;
        index=0;
        bits=0;
        ret=0;
        while(index<len)
        {
            int ch=src[index];
            int cur=(ret<<(6-bits))+(ch>>(2+bits));
            res[pos++]=base64_chart[cur];
            index++;
            bits+=2;
            ret=ch%(1<<bits);
            if(bits==6)
            {
                res[pos++]=base64_chart[ret];
                bits=0;
                ret=0;
            }
            
        }
        if(bits==2){
        	res[pos++]=base64_chart[ret<<4];
        	res[pos++]='=';
			res[pos++]='=';
		}
		else if(bits==4){
        	res[pos++]=base64_chart[ret<<2];
        	res[pos++]='=';
			
		} 
		res[pos]='\0';
		printf("%s\n",res);
       
    }
    return 0;
}