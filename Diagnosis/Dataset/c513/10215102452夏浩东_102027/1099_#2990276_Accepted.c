#include <stdio.h>
#include <string.h>
char cas[26][5]={".-\0","-...\0","-.-.\0","-..\0",
".\0","..-.\0","--.\0","....\0","..\0",".---\0","-.-\0",
".-..\0","--\0","-.\0","---\0",".--.\0","--.-\0",".-.\0",
"...\0","-\0","..-\0","...-\0",".--\0","-..-\0","-.--\0",
"--..\0"};
char num[10][6]={"-----\0",".----\0","..---\0","...--\0",
"....-\0",".....\0","-....\0","--...\0","---..\0","----.\0"
};
char find(char *s)
{
    char c='?';
    for(int i=0;i<26;i++){
        if(strcmp(cas[i],s)==0){c='A'+i;break;}
    }
    for(int i=0;i<10;i++){
        if(strcmp(num[i],s)==0){c='0'+i;break;}
    }
    return c;
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int mm=0;mm<cnt;mm++)
    {
        char s[1001];
        scanf("%s",s);
        int begin=0,end=0;
        char r[6],res;
        printf("case #%d:\n",mm);
        for(int i=0;i<(int)strlen(s);i++)
        {
            if(s[i]!='/' && i+1!=(int)strlen(s)) end++;
            else if(i+1==(int)strlen(s)){
            	end++;
            	int k=0;
                for(int j=begin;j<end;j++,k++) r[k]=s[j];
                r[k]='\0';
                res = find(r);
                printf("%c",res);
			}
            else if(s[i]=='/'){
                int k=0;
                for(int j=begin;j<end;j++,k++) r[k]=s[j];
                r[k]='\0';
                res = find(r);
                if(s[i+1]!='/'){
                    printf("%c",res);
                    end+=1;
                    begin=end;
                }else if(s[i+1]=='/' && s[i+2]=='/' && s[i+3]!='/'){
                    printf("%c ",res);
                    end+=3;
                    begin=end;
                    i+=2;
                }else{
                    printf("%c.",res);
                    end+=5;
                    begin=end;
                    i+=4; 
                }
            }
        }
        printf("\n");
    }
    return 0;
}