#include <stdio.h>
#include <stdlib.h>

void trans(char* in,char* ou,int l)
{
    int flag[201];

    for (int i=0;i<l;i++){
        if(in[i]==0){flag[i]=2;break;}
        if(in[i+1]>in[i])flag[i]=1;
        else if(in[i+1]<in[i])flag[i]=-1;
        else flag[i]=0;
    }

    int oui=0;
    for (int ini=0;ini<l&&in[ini]!='\0';ini++){
        if(flag[ini]!=0){
            if(flag[ini]==-1){
                ou[oui++]=in[ini];
            }
            else if(flag[ini]==1){
                ou[oui++]=in[ini];
                ou[oui++]=in[ini];
            }
        }
        else{
            int j=1;
            ini++;
            while(flag[ini]==0){
                ini++;j++;
            }
            if(flag[ini]==-1){
                for (int j1=j;j1>=0;j1--){
                    ou[oui++]=in[ini-j1];
                }

            }
            else if(flag[ini]==1){
                for (int j1=j;j1>=0;j1--){
                    ou[oui++]=in[ini-j1];
                    ou[oui++]=in[ini-j1];
                }
            }
        }

    }
    ou[oui]=0;
}

int main()
{
    char in[202];
    char ou[202];
    scanf("%s",in);
    int l=strlen(in);
    trans(in,ou,l);
    printf("%s",ou);
    return 0;
}
