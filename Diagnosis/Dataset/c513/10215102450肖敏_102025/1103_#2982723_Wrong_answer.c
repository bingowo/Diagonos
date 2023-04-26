#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    long long int s[4];
    memset(s,0,4);
    char line[50];
    while (gets(line)) {
        int len = strlen(line);
        for (int q=0 ;q< len;q++) {
            if (line[q] == ',') {
                line[q] = ' ';
            }
        }
        char t[4][20];
        int i,j,k;
        for( i=0,j=0,k=0;line[i] != '\0';i++)
        {
            if(line[i] == ' ' )
            {
                t[j][k]= '\0';
                j++;
                k=0;
            }
            else if(i == len -1)
            {
                t[j][k++]= line[i];
                j++;
            }
            else
            {
                t[j][k++]=line[i];
            }
        }
        int l=j;
        int m,n,p;
        if(strcmp(t[0],"IN")==0)
        {
            m=t[1][0]-'A';
            s[m]= atoi(t[2]);
        }
        else if(strcmp(t[0],"OUT")==0)
        {
            m=t[1][0]-'A';
            printf("%lld\n",s[m]);
        }
        else if(strcmp(t[0],"MOV")==0)
        {
            m=t[1][0]-'A';
            n=t[2][0]-'A';
            s[m]= s[n];
        }
        else if(strcmp(t[0],"ADD")==0)
        {
            if(l==3)
            {
                m=t[1][0]-'A';
                n=t[2][0]-'A';
                s[m]+=s[n];
            }
            else
            {
                m=t[1][0]-'A';
                n=t[2][0]-'A';
                p=t[3][0]-'A';
                s[m]=s[n]+s[p];
            }
        }
        else if(strcmp(t[0],"SUB")==0)
        {
            if(l==3)
            {
                m=t[1][0]-'A';
                n=t[2][0]-'A';
                s[m]-=s[n];
            }
            else
            {
                m=t[1][0]-'A';
                n=t[2][0]-'A';
                p=t[3][0]-'A';
                s[m]=s[n]-s[p];
            }
        }
        else if(strcmp(t[0],"MUL")==0)
        {
            if(l==3)
            {
                m=t[1][0]-'A';
                n=t[2][0]-'A';
                s[m]*=s[n];
            }
            else
            {
                m=t[1][0]-'A';
                n=t[2][0]-'A';
                p=t[3][0]-'A';
                s[m]=s[n]*s[p];
            }
        }
        else if(strcmp(t[0],"DIV")==0)
        {
            if(l==3)
            {
                m=t[1][0]-'A';
                n=t[2][0]-'A';
                s[m]/=s[n];
            }
            else
            {
                m=t[1][0]-'A';
                n=t[2][0]-'A';
                p=t[3][0]-'A';
                s[m]=s[n]/s[p];
            }
        }
    }
    return 0;
}
