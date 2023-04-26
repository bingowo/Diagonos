#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ctoBase64(int n)
{
    if((0<=n)&&(n<=25)){return 'A'+n;}
    else if((26<=n)&&(n<=51)){return 'a'+n-26;}
    else if((52<=n)&&(n<=61)){return '0'+n-52;}
    else if(n==62){return '+';}
    else if(n==63){return '/';}
    return -1;
}

int bToi(char s[])
{
    int len = strlen(s);
    int res = 0,i = 0;
    for(i = 0;i<len;i++){
        res = res*2 + (s[i]-'0');
    }
    return res;
}
void reverse(char *s){
    int slen = strlen(s);
    for(int i = 0,j = slen-1;i<j;i++,j--){
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}
void sToBinary(char *s, char *t)
{
    int slen = strlen(s);
    for(int i = 0;i<slen;i++)
    {
        int tmp = (int)s[i],tmpcnt = 0;
        char stmp[9];memset(stmp,0,9*sizeof(char));
        while(tmp!=0){
            int r = tmp%2;
            tmp/=2;
            stmp[tmpcnt] = r+'0';tmpcnt++;
        }
        while(tmpcnt<8){
            stmp[tmpcnt] = '0';tmpcnt++;
        }
        reverse(stmp);
        //printf("stmp = %s\n",stmp);
        strcat(t,stmp);
    }
}

int main()
{
    int T = 0;scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        char s[110];memset(s,0,110*sizeof(char));
        scanf("%s",s);
        char t[900];memset(t,0,900*sizeof(char));
        sToBinary(s,t);
        while((strlen(t)%6)!=0){
            t[strlen(t)] = '0';
        }
        int tlen = strlen(t);
        char res[200];memset(res,0,200*sizeof(char));
        int cnt = 0,rcnt = 0;
        char tmp[7];memset(tmp,0,7*sizeof(char));
        for(int j = 0;j<tlen;j++){
            tmp[cnt] = t[j];
            cnt++;
            if(cnt%6==0){
                int itmp = bToi(tmp);
                char tmpc = ctoBase64(itmp);
                res[rcnt] = tmpc;
                rcnt++;
                memset(tmp,0,7*sizeof(char));
                cnt = 0;
            }
        }
        while((strlen(res)%4)!=0){
            res[strlen(res)] = '=';
        }
        //printf("%s\n",t);
        printf("case #%d:\n",i);
        printf("%s\n",res);
    }

    return 0;
}
