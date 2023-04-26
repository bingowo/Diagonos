#include <stdio.h>
#include <string.h>

int main()
{
    int num[10];
    int alp[26];
    char s[21];
    int t,i,j,l;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s",s);
        l=strlen(s);
        memset(num,0,sizeof(num));
        memset(alp,0,sizeof(alp));
        for(j=0;j<l;j++)
            alp[s[j]-'A']++;
        num[0]=alp['Z'-'A'];
        num[2]=alp['W'-'A'];
        num[4]=alp['U'-'A'];
        num[6]=alp['X'-'A'];
        num[8]=alp['G'-'A'];
        num[1]=alp['O'-'A']-num[0]-num[2]-num[4];
        num[3]=alp['R'-'A']-num[0]-num[4];
        num[5]=alp['F'-'A']-num[4];
        num[7]=alp['S'-'A']-num[6];
        num[9]=alp['I'-'A']-num[5]-num[6]-num[8];
        j=0;
        printf("case #%d:\n",i);
        while(j<10){
            if(num[j]==0)
                j++;
            else{
                printf("%d",j);
                num[j]--;
            }
        }
        printf("\n");
    }
    return 0;
}
