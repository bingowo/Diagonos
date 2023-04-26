#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        printf("case #%d:\n",step);
        char s[120];scanf("%s",s);
        int cnt=0,res=0;
        for(int i=1;i<=strlen(s)-1;i++){
            char c[120];
            for(int k=0;k<i;k++){
                c[k]=s[k];
            }
            for(int j=i;j<strlen(s);j++){
                c[j+1]=s[j];
            }
            c[strlen(s)+1]=0;
            for(int a=0;a<3;a++){
                c[i]=65+a;//开始判断；
                char d[120];
                //printf("%s\n",d);
                strcpy(d,c);
                int flag=1;
                //printf("s=%s d=%s\n",s,d);
                while(flag==1){
                    char t[120];t[0]=d[0];
                    int k=0;
                    for(int i=1;i<strlen(d);i++){
                        if(d[i]!=d[i-1])t[++k]=d[i];
                        else cnt++;
                    }
                    t[k+1]=0;
                    if(k==strlen(d)-1)flag=0;
                    //printf("t=%s\n",t);
                    //printf("d=%s\n",d);
                    //printf("cnt=%d\n",cnt);
                    strcpy(d,t);
                }
                cnt++;
                if(cnt>res)res=cnt;
                cnt=0;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
