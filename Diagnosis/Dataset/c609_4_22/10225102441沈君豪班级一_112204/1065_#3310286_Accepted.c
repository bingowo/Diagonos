#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int T;
    scanf("%d",&T);
    char c;
    c=getchar();
    for(int i=0;i<T;i++){
        char s[110];
        gets(s);
        int n=strlen(s);        //字符串长度
        for(int j=0;j<n;j++){
            if(s[j]==' '){
                s[j]='\0';       //方便atof 遇到\0结束 将前面的转化为浮点数
            }
        }
        int kk=0;
        double t[110];
        for(int j=n-1;j>=0;j--){
            if(s[j]=='*'){
                t[kk-1]=t[kk]*t[kk-1];
                kk--;
            }else if(s[j]=='/'){
                t[kk-1]=t[kk]/t[kk-1];
                kk--;
            }else if(s[j]=='+'){
                t[kk-1]=t[kk]+t[kk-1];
                kk--;
            }else if(s[j]=='-'){
                t[kk-1]=t[kk]-t[kk-1];
                kk--;
            }else if(s[j]){
                while(j>=0&&s[j]){
                    j--;
                }
                j++;
                kk++;
                t[kk]=atof(s+j);
            }

        }
        printf("case #%d:\n%lf\n",i,t[1]);

    }
    return 0;
}
