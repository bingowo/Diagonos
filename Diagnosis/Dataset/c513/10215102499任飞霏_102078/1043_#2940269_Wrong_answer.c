#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert(char *s,char c,int i);
void eraseString(char *s);
char a[]={'A','B','C'};

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[100];
        scanf("%s",s);
        int len=strlen(s);
        int mlen = len;
        printf("case #%d:\n",i);
        for(int pos=0;pos<=len;pos++){
            for(int cpos=0;cpos<3;cpos++){
                char temps[100];
                for(int i=0;i<len;i++){
                    temps[i]=s[i];
                }
                char ch = a[cpos];
                if(pos!=len)
                    insert(temps,ch,pos);
                else{
                    temps[len]=ch;
                    temps[len+1]='\0';
                }
                eraseString(temps);
                if(strlen(temps)<mlen)mlen = strlen(temps);
            }
        }
        printf("%d\n",len+1-mlen);

    }
    return 0;
}

void insert(char *s,char c,int i)
{
    char a[100];
    strcpy(a,s+i);

    *(s+i)=c;
    strcpy(s+i+1,a);

}

void eraseString(char *s)
{
    int flag=0;
    int l=strlen(s);
    int i=0,k=0;
    char tmp[100];
    while(i<l){
        char ch=s[i];
        int j=i+1;
        for(;j<l && s[j]==ch;j++);
        if(j==i+1){
            tmp[k++]=ch;
            i=j;
        }
        else{
            flag=1;
            i=j;
        }

    }
    if(strlen(tmp)==strlen(s))strcpy(tmp,s);
    else
        eraseString(tmp);
}
