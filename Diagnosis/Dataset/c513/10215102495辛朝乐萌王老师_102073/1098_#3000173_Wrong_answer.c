#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define LEN 110


int main()
{
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        char s[120];
        scanf("%s",s);
        char *p=s;
        int light[4]={0},a[4]={0},a1=-1,a2=-1;
        int idx=0,b[4]={0};
        while (*p) {
            if (*p!='!'&&light[idx%4]==0) {
                light[idx%4]==*p;
                switch (*p) {
                    case 'R': a[0]=1; break;
                    case 'B': a[1]=1; break;
                    case 'Y': a[2]=1; break;
                    case 'G': a[3]=1; break;
                }
            }
            p++,idx++;
        }
        for (int j=0; j<4; j++) {
            if (light[j]==0) {
                a1=j;
                break;
            }
        }
        for (int j=0; j<4; j++) {
            if (a[j]==0) {
                a2=j;
                break;
            }
        }
        if (!(a1==-1&&a2==-1)) {
            switch (a2) {
                case 0: light[a1]='R'; break;
                case 1: light[a1]='B'; break;
                case 2: light[a1]='Y'; break;
                case 3: light[a1]='G'; break;
            }
        }
        p=s,idx=0;
        while (*p) {
            if (*p=='!') {
                char c=light[idx%4];
                switch(c){
                    case 'R': b[0]++; break;
                    case 'B': b[1]++; break;
                    case 'Y': b[2]++; break;
                    case 'G': b[3]++; break;
                        
                }
            }
            p++,idx++;
        }
        printf("case #%d:\n",i);
        for (int i=0; i<4; i++) {
            printf("%d%c",b[i],i==3?'\n':' ');
        }
    }
    return 0;
}
