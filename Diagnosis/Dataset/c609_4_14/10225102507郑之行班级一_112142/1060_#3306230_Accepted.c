#include <stdio.h>
#include <stdlib.h>
/*
void insert(char *s, int pos,int cnt)
{
    int i;
    for (i=strlen(s)+cnt;i>pos;i--) s[i]=s[i-cnt];
}


void trans(char*in,char*ou)
{
    strcpy(ou,in);
    char *p1 = in;
    while(p1-in+1<strlen(in))
    {
        insert(in,p1-in,1);
        int cmp=strcmp(in,ou);
        if(cmp<0)strcpy(ou,in),p1++;
        p1++;//printf("%d\t%s\n",p1-in,in);
    }
}
*/
void trans(char* in,char* ou,int l)
{
    int flag[201];

    for (int i=0;i<l;i++){
        if(in[i]==0){flag[i]=2;break;}
        if(in[i+1]>in[i])flag[i]=1;
        else if(in[i+1]<in[i])flag[i]=-1;
        else flag[i]=0;
    }

    /*for (int i=0;i<l && flag[i]!=2 ;i++){
        printf("%d",flag[i]);
    }printf("\n");*/

    int oui=0;
    for (int ini=0;ini<l&&in[ini]!='\0';ini++){
        //printf("1");
        if(flag[ini]!=0){
            //printf("2");
            if(flag[ini]==-1){
                ou[oui++]=in[ini];
            }
            else if(flag[ini]==1){
                ou[oui++]=in[ini];
                ou[oui++]=in[ini];
            }
        }
        else{
            //printf("3");
            int j=1;//printf("ini=%d\n",ini);
            ini++;
            while(flag[ini]==0){
                ini++;j++;
            }
            //printf("j=%d\n",j);
            if(flag[ini]==-1){
                for (int j1=j;j1>=0;j1--){
                    //printf("4");
                    ou[oui++]=in[ini-j1];
                }

            }
            else if(flag[ini]==1){
                for (int j1=j;j1>=0;j1--){
                    //printf("5");
                    //printf("oui=%d\n",ini-j1);
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
    //in[strlen(in)]=127;
    trans(in,ou,l);
    printf("%s",ou);
    return 0;
}
