#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("case #%d:\n",i);
        char c[60];
        int s[60];
        int d[60];
        for(int i=0;i<60;i++){
            s[i]=-1;
            d[i]=-1;
        }
        scanf("%s",c);
        s[0]=1;d[0]=0;//d[i]用于保护标记
        int mark;
        for(int i=1;i<strlen(c);i++){
            if(c[i]!=c[0]){
                s[i]=0;//找到首个0的位置
                d[i]=0;//标记保护0的位置
                mark=i;
                break;
            }
        }
        int num=2;
        for(int j=0;j<strlen(c);j++){
            for(int k=j+1;k<strlen(c);k++){
                if(c[j]!=c[k]&&d[k]!=0&&c[k]!=c[mark]){
                  s[k]=num;//不等就标号
                   d[k]=0;//保护与新的十进制数对应的那位
                   num++;
                   break;
                }
                else if(d[k]!=0){
                 if(c[k]==c[mark]){
                    s[k]=s[mark];
                 }
                 else s[k]=s[j];
                 d[k]=0;//相等后加上保护标记
                }
            }
        }
        long long sum=0;//数位计算部分
        for (int i=0;i<strlen(c)-1;i++){
            sum=num*(sum+s[i]);
        }
        int h=strlen(c)-1;
        sum+=s[h];
        printf("%lld\n",sum);
    }
    return 0;
}
