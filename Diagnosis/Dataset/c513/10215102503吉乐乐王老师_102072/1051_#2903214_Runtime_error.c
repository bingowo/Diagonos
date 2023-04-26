#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int t;scanf("%d",&t);getchar();int cas=0;
    while(t--){
        char s[200];
        scanf("%s",s);
        char s1[500]={'\0'};//转化为八位的二进制串
        for(int i=0;i<strlen(s);i++){
            char temp[9];int ti=0;
            int num=(int)s[i];
            do{
                temp[ti]=num%2+'0';
                ti++;
                num/=2;
            }while(num);
            while(ti<8){
                temp[ti]='0';ti++;
            }
            int l=0,r=7;
            while(l<r){
                char t=temp[l];temp[l]=temp[r];temp[r]=t;l++;r--;
            }
            temp[8]='\0';strcat(s1,temp);
        }
        int n=strlen(s1);
        while(n%6!=0){
            s1[n]='0';n++;
        }
        s1[n]='\0';
        int buzu=0;
        if((n/6)%4!=0)buzu=4-((n/6)%4);
        int ret[100];int ri=0;
        for(int i=0;i<n;){
            int cnt=0;//开始六进制转化
            int num=0;
            while(cnt<6){
                num=num*2+s1[i]-'0';
                i++;cnt++;
            }
            ret[ri]=num;ri++;
        }
        while(buzu){
            ret[ri]=-1;ri++;buzu--;
        }
        printf("case #%d:\n",cas++);
        for(int i=0;i<ri;i++){
            if(ret[i]>=0&&ret[i]<=25){
                printf("%c",(char)(ret[i]+'A'));
            }
            if(ret[i]>=26&&ret[i]<=51){
                printf("%c",(char)(ret[i]-26+'a'));
            }
            if(ret[i]>=52&&ret[i]<=61){
                printf("%c",(char)(ret[i]-52+'0'));
            }
            if(ret[i]==62)printf("+");
            if(ret[i]==63)printf("/");
            if(ret[i]==-1)printf("=");
        }
        printf("\n");
    }
    getchar();
}
