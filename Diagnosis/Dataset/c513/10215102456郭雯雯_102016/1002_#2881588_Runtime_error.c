#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int t,o=0,ans=0;
    char a[60],b[62]="1023456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",p[60],q[60],s[60];
    scanf("%d",&t);
    while(o<t){
        scanf("%s",a);
        int len=strlen(a),l=len;
        strcpy(p,a);strcpy(s,a);
        for(int i=1;i<len;i++)
            for(int j=0;j<i;j++)
                if(p[i]==p[j]){
                    for(int k=i;k<len;k++)
                        p[k]=p[k+1];
                    len--;	//提高代码执行效率，降低时间复杂度
                    i--;    //不加这一句的话，会跳着比较查找，漏掉一些字符
                }
        strcpy(q,p);
        for(int i=0,k=0;i<len;i++,k++)q[i]=b[k];
        for(int i=0;i<l;i++){
            for(int j=0;j<len;j++)
                if(a[i]==p[j])s[i]=q[j];
        }
        if(len==1)len=2;
        int n=l;
        l=0;
        while(l<=n){
            if(s[l-1]>='0'&&s[l-1]<='9')ans=ans*len+(s[l-1]-'0');
            if(s[l-1]>='a'&&s[l-1]<='z')ans=ans*len+(s[l-1]-'a'+10);
            if(s[l-1]>='A'&&s[l-1]<='Z')ans=ans*len+(s[l-1]-'A'+37);
            l++;
        }
        printf("case#%d:\n%s\n",o,ans);
        o++;
    }
    return 0;
}
