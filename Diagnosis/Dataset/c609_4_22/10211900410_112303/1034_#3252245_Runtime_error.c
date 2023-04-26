#include<stdio.h>
#include<string.h>
int main()
{
    char s[50];
    scanf("%s",&s);
    int i,j,flag=-1,sign=-1;
    int l=strlen(s);
    for(i=0;i<l-2;i++){
        if(s[i]=='0'&&s[i+1]=='x'){
            int c[100000],k=0;
            j=i+2;
            if(j<l-3){
                if(s[j]=='0'&&s[j+1]=='x'&&((s[j+2]<='f'&&s[j+2]>='a')||(s[j+2]>='0'&&s[j+2]<='9'))) continue;
            }
            for(j=i+2;j<l;j++){
                if((s[j]<='f'&&s[j]>='a')||(s[j]<='9'&&s[j]>='0')) c[k++]=s[j];
                else break;
            }
            if(k>0){
                flag=1;//判断字符串中是否有合法的十六进制数
                sign=1;//判断该段字符串是否为合法的十六进制字符串
            }

            int sum=0,weight=1;
            for(k=k-1;k>=0;k--){
               if(c[k]>='0'&&c[k]<='9') sum+=(c[k]-'0')*weight;
               else sum+=(c[k]-'a'+10)*weight;
               weight*=16;
            }
            if(sign=1){
                printf("%d ",sum);
                sign=-1;
            }
            i=j;
        }
    }
    if(flag==-1) printf("-1");
    return 0;
}


