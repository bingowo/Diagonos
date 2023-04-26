#include<stdio.h>
#include<string.h>
int main(){
    int digit[10]={0};
    int num[21]={0};
    int t;
    scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        char s[21];
        scanf("%s",s);getchar();
        int len=strlen(s);
        for(int i=0;i<len;i++){
            num[i]=s[i]-'0';
            digit[s[i]-'0']++;
        }
        int pos1=-1,pos2=-1;
        int flag=0;
        for(int i=len-1;i>0;i--){
            for(int j=i-1;j>=0;j--){
                if(num[j]<num[i]){
                    pos1=j;pos2=i;
                    flag=1;break;
                }
            }
            if(flag)break;
        }
        if(pos1!=-1&&pos2!=-1){
            int t=num[pos1];
            num[pos1]=num[pos2];
            num[pos2]=t;
            for(int i=0;i<=pos1;i++)digit[num[i]]--;
            for(int i=pos1+1;i<len;i++){
                for(int j=0;j<10;j++){
                    if(digit[j]>0){
                        num[i]=j;digit[j]--;break;
                    }
                }
            }
        }
        printf("case #%d:\n",cas++);
        for(int i=0;i<len;i++){
            printf("%d",num[i]);
        }
        putchar('\n');
    }
}