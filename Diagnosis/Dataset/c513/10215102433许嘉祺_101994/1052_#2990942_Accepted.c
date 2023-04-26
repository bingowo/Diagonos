#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    int count[10];
    for (int i=0;i<t;i++){
        char s[100];
        scanf("%s",s);
        memset(count,0,sizeof(count));
        int num[255];
        printf("case #%d:\n",i);
        memset(num,0,sizeof(num));
        for (int j=0;j<strlen(s);j++)
            num[s[j]]++;
        if  (num['Z']){

            num['E']-=num['Z'];
            count[0]+=num['Z'];
            num['R']-=num['Z'];
            num['O']-=num['Z'];
            num['Z']=0;
        }
        if (num['G']){
            count[8]+=num['G'];
            num['E']-=num['G'];
            num['I']-=num['G'];
            num['H']-=num['G'];
            num['T']-=num['G'];
            num['G']=0;
        }
        if (num['X']){
            count[6]+=num['X'];
            num['S']-=num['X'];
            num['I']-=num['X'];
            num['X']-=num['X'];

        }
        if (num['S']){
            count[7]+=num['S'];
            num['N']-=num['S'];
            num['E']=num['E']-2*num['S'];
            num['V']-=num['S'];
            num['S']-=num['S'];

        }
        if (num['V']){
            count[5]+=num['V'];
            num['F']-=num['V'];
            num['I']-=num['V'];
            num['E']-=num['V'];
            num['V']=0;

        }
        if (num['F']){
            count[4]+=num['F'];
            num['O']-=num['F'];
            num['U']-=num['F'];
            num['R']-=num['F'];
            num['F']=0;
        }
        if (num['R']){
            count[3]+=num['R'];
            num['T']-=num['R'];
            num['H']-=num['R'];
            num['E']=num['E']-2*num['R'];
            num['R']=0;
        }
        if (num['W']){
            count[2]+=num['W'];
            num['T']-=num['W'];
            num['O']-=num['W'];
            num['W']=0;
        }
        if (num['O']){
            count[1]+=num['O'];
            num['N']-=num['O'];
            num['E']-=num['O'];
            num['O']=0;

        }
        if (num['I']){
            count[9]+=num['I'];

        }
        for (int j=0;j<10;j++)
            for (int k=0;k<count[j];k++) printf("%d",j);
        printf("\n");
    }
    return 0;
}