#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int is0x(char c)
{
    if(isdigit(c)||((c>='a')&&(c<='f'))){return 1;}
    else {return 0;}
}


int main()
{
    //int tmp = 0;
    //scanf("%x",&tmp);
    //printf("%d",tmp);
    char *s = (char*)malloc(100001*sizeof(char));memset(s,0,100001*sizeof(char));
    scanf("%s",s);
    int slen = strlen(s);
    char ans[500000][500000/slen];memset(ans,0,500000*sizeof(char));
    int cnt = 0,k = 0;
    int i = 0;
    while(s[i]!=0)
    {
        if((s[i]=='0')&&(s[i+1]=='x')&&(is0x(s[i+2])))
        {
            ans[cnt][k++] = '0';
            ans[cnt][k++] = 'x';
            i+=2;
            while(is0x(s[i]))
            {
                ans[cnt][k] = s[i];
                k++;i++;
            }
            cnt++;
            k = 0;
        }
        else{i++;}
    }
    unsigned int n[cnt];memset(n,0,cnt*sizeof(unsigned int));
    if(cnt == 0){printf("-1");return 0;}
    for(int i = 0;i<cnt;i++)
    {
        sscanf(ans[i],"%x",&n[i]);
        //printf("%s ",ans[i]);
        printf("%d ",n[i]);
    }
    free(s);

    //printf("cnt = %d\n",cnt);
    return 0;
}
