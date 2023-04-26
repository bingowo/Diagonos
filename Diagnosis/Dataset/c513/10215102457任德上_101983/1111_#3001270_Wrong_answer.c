#include<stdio.h>
#include<string.h>
#include<ctype.h>
int count(int x,int a[]){
    int k=0;
    for(int i=0;i<4;i++){
        int t=1;
        for(int p=0;p<i;p++)t*=x;
        k+=a[i]*t;
    }
    return k;
}
int main(){
    char s[100],*s1,*s2,*s3;
    while(scanf("%s",s)!=EOF){
        int a[4]={0};
        s2=strchr(s,'=');
        s2++;
        while(1){
            int flag=1;
            s1=s2;
            s2=strchr(s1+1,'+');
            s3=strchr(s1+1,'-');
            if(s3==s1){
                s3=strchr(s1+1,'-');
                s1++;
                flag=-1;
            }
            if(s2==NULL&&s3==NULL){   //最后一次循环
                int n=0,i=1;
                s2=strlen(s)+s;
                s3=strchr(s1,'x');
                if(s3!=NULL)n=1;
                if(s3!=NULL&&s3+1<s2)n=*(s3+2)-'0';
                if(isdigit(*s1))i=0;
                while(isdigit(*s1)&&s1<s2){
                    i=i*10+*s1-'0';
                    s1++;
                }
                a[n]=flag*i;
                break;
            }
            else if(s2==NULL&&s3!=NULL)s2=s3;
            else if(s2!=NULL&&s3!=NULL)s2=s2>s3?s3:s2;
            char c=*s2;
            int n=0,i=1;
            *s2=0;
            s3=strchr(s1,'x');
            if(s3!=NULL)n=1;
            if(s3+1<s2)n=*(s3+2)-'0';
            if(isdigit(*s1))i=0;
            while(isdigit(*s1)&&s1<s2){
                i=i*10+*s1-'0';
                s1++;
            }
            a[n]=flag*i;
            *s2=c;
        }
        char ch[41][41]={0};
        for(int i=0;i<41;i++){
            for(int j=0;j<41;j++)ch[i][j]='.';
        }
        for(int i=0;i<40;i++)ch[20][i]='-';
        ch[20][40]='>';
        for(int i=40;i>0;i--)ch[i][20]='|';
        ch[0][20]='^';
        ch[20][20]='+';
        for(int i=-20;i<=20;i++){
            int k=count(i,a);
            if(k<=20&&k>=-20)ch[20-k][i+20]='*';
        }
        for(int i=0;i<41;i++){
            for(int j=0;j<41;j++)printf("%c",ch[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}