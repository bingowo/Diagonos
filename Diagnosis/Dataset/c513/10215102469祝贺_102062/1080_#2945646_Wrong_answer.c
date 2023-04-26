#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int trans(char* bin,char*s){
    int begin=0,len=strlen(s),p=0,tag=-1;

    while(begin<len){
        int carry=0;
        if((s[len-1]-'0')%2==0 && tag!=-1)bin[p++]='0';
        else if((s[len-1]-'0')%2==1){
            bin[p++]='1';tag=1;
        }
        for(int i=begin;i<len;i++){
            int tmp=s[i]-'0'+carry;
            if(tmp==0 || tmp==1){
                if(begin==len-1){begin++;s[i]='0';break;}
                s[i+1]=tmp*10+s[i+1];
                s[i]='0';
                if(i==begin && s[i]=='0')begin++;
                continue;
            }
            s[i]=(tmp>>1)+'0';
            carry=(tmp&1)*10;
            if(i==begin && s[i]=='0')begin++;
        }
    }

    return p;
}
int multi2(char*s,int len){
    int p=0,carry=0;
    while(carry!=0 || p<len){
        int tmp=s[p]-'0';
        s[p]=(tmp*2+carry)%10+'0';
        carry=(tmp*2+carry)/10;
        p++;
    }
    return p;
}
int add(char*s, int t,int len){
    if(t==0)return len;
    else{
        int carry=1,p=0;
        while(carry!=0){
            int tmp=s[p]-'0';
            s[p]=(tmp+carry)%10+'0';
            carry=(tmp+carry)/10;
            p++;
        }
        return len<p?p:len;
    }

}
int main()
{
    int pro;scanf("%d",&pro);
    for(int index=0;index<pro;index++){
        char s[105];scanf("%s",s);
        char bin[350];int len=trans(bin,s);
        int slen=1;
        for(int i=0;i<len;i++){
            slen=multi2(s,slen);
            slen=add(s,bin[i]-'0',slen);
        }
        printf("case #%d:\n",index);
        for(int i=slen-1;i>=0;i--){
            printf("%c",s[i]);
        }
        printf("\n");
    }
}