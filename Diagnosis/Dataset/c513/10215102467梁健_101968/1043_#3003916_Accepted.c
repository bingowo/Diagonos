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
        int cnt=0,res=1;
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
                c[i]=65+a;
                char d[120];
                //printf("%s\n",d);
                strcpy(d,c);
                int flag=1;
                //printf("s=%s d=%s\n",s,d);
                //printf("%s\n",d);
                while(flag==1){
            //time++;
                    char jud[120];
                    int k=0;
                    if(d[0]!=d[1]){
                            jud[k]=d[0];
                            //printf("%c",jud[k]);
                            k++;
                    }
                    else cnt++;
                    for(int i=1;i<strlen(d)-1;i++){
                        if(d[i]!=d[i+1]&&d[i]!=d[i-1]){
                            jud[k]=d[i];
                            //printf("%c",jud[k]);
                            k++;
                        }
                        else cnt++;
                    }
                    if(d[strlen(d)-2]!=d[strlen(d)-1]){
                        jud[k]=d[strlen(d)-1];
                        //printf("%c",jud[k]);
                        k++;
                    }
                    else cnt++;
                    jud[k]=0;
                    //printf("jud=%s ",jud);
                    //printf(" %s\n",d);
                    if(k==strlen(d))flag=0;
                    //printf("time=%d,k=%d,lend=%d,cnt=%d,flag=%d,jud=%s,d=%s\n",time,k,strlen(d),cnt,flag,jud,d);
                    if(k==0)break;
                    if(strlen(d)==1)break;
                    strcpy(d,jud);
                    //printf("d=%s\n",d);

                }
                if(cnt>res)res=cnt;
                cnt=0;
            }
        }
        printf("%d\n",res);
    }
    /*int flag=1;char d[120];int time=0;int cnt=0;
    scanf("%s",d);
    while(flag==1){
            time++;
            char jud[120];
            int k=0;
            if(d[0]!=d[1]){
                    jud[k]=d[0];
                    //printf("%c",jud[k]);
                    k++;
            }
            else cnt++;
            for(int i=1;i<strlen(d)-1;i++){
                if(d[i]!=d[i+1]&&d[i]!=d[i-1]){
                    jud[k]=d[i];
                    //printf("%c",jud[k]);
                    k++;
                }
                else cnt++;
            }
            if(d[strlen(d)-2]!=d[strlen(d)-1]){
                jud[k]=d[strlen(d)-1];
                //printf("%c",jud[k]);
                k++;
            }
            else cnt++;
            jud[k]=0;
            //printf("jud=%s ",jud);
            //printf(" %s\n",d);
            if(k==strlen(d))flag=0;
            printf("time=%d,k=%d,lend=%d,cnt=%d,flag=%d,jud=%s,d=%s\n",time,k,strlen(d),cnt,flag,jud,d);
            if(k==0)break;
            if(strlen(d)==1)break;
            strcpy(d,jud);
            //printf("d=%s\n",d);

        }*/
    return 0;
}
