#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++){
        printf("case #%d:\n",i);
        double num[109];
        char s[109];
        int top=0;
        gets(s);
        int len=strlen(s);
        for(int j=0;j<len;j++)if(s[j]==' ')s[j]=0;
        for(int j=len-1;j>=0;j--){
            double temp;
            if(s[j]=='+'){
                temp=num[top]+num[top-1];
                num[--top]=temp;
            }
            else if(s[j]=='-'){
                temp=num[top]-num[top-1];
                num[--top]=temp;
            }
            else if(s[j]=='*'){
                temp=num[top]*num[top-1];
                num[--top]=temp;
            }
            else if(s[j]=='/'){
                temp=num[top]/num[top-1];
                num[--top]=temp;
            }
            else if(s[j]){
                while(j>=0&&s[j])j--;
                j++;
                num[++top]=atof(s+j);
            }
        }
        printf("%lf\n",num[1]);
    }
    return 0;
}
