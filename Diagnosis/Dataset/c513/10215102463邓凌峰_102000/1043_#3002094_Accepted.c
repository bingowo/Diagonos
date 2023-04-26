#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define LEN 110
#define BigNUm 1000000007
#define Max 1000000

void insert(int idx,char* from,char *to,char x){
    int len=strlen(from);
    for(int i=0,cnt=0;i<=len;cnt++){
        if(cnt==idx){
            to[cnt]=x;
        }
        else{
            to[cnt]=from[i++];
        }
    }
}

int cut(char *tmp){
    char ans[LEN]={0};
    int start=0,len=strlen(tmp);
    int cnt=0;
    int have=0;
    do{
        have=0;
        for(;start<len;start++){
            if(tmp[start]==tmp[start+1]){
                have=1;
                break;
            }
        }
        if(have){
            int end=start+1;
            for(;end<len;end++){
                if(tmp[end]!=tmp[start]){
                    end--;
                    break;
                }
            }
            if(end==len) end--;
            cnt+=end-start+1;
            for(int i=0,j=0;i<len;i++){
                if(start<=i&&i<=end)tmp[i]='D';
            }
            start=end+1;
        }
    }while(have);
    for(int i=0,j=0;i<len;i++){
        if(tmp[i]=='D');
        else ans[j++]=tmp[i];
    }
    memset(tmp,0,sizeof(tmp));
    strcpy(tmp,ans);


    return cnt;
}




int main() {
    int T;
    scanf("%d",&T);
    for(int I=0; I<T; I++) {
        char in[LEN]={0};
        scanf("%s",in);
        int len=strlen(in);
        printf("case #%d:\n",I);
        int ans=0;
        for(int idx=0;idx<=len;idx++){
            char tmp[LEN]={0};
            for(int i=0;i<3;i++){
                int cnt=0;
                if(i==0){
                    insert(idx,in,tmp,'A');
                    while(strlen(tmp)!=0){
                        int add=cut(tmp);
                        cnt+=add;
                        if(add==0) break;
                    }
                    if(cnt>ans) ans=cnt;
                }
                else if(i==1){
                    insert(idx,in,tmp,'B');
                    while(strlen(tmp)!=0){
                        int add=cut(tmp);
                        cnt+=add;
                        if(add==0) break;
                    }
                    if(cnt>ans) ans=cnt;
                }
                else if(i==2){
                    insert(idx,in,tmp,'C');
                    while(strlen(tmp)!=0){
                        int add=cut(tmp);
                        cnt+=add;
                        if(add==0) break;
                    }
                    if(cnt>ans) ans=cnt;
                }
            }
        }
        printf("%d\n",ans);




    }
    return 0;
}
