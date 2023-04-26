#include <stdio.h>
#include <string.h>

struct data{
    int position;
    int cnt;
};
struct data t[100];
int main() {
    int T;
    scanf("%d",&T);
    for(int j=0;j<T;j++) {
        for(int i=0;i<100;i++)
        {
            t[i].cnt=0;
            t[i].position=-1;
        }
        char s[101];
        scanf("%s", s);
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            if (s[i] != '!') {
                t[s[i]].position = i % 4;
                t[s[i]].cnt += 1;
            }
        }
        if((t['R'].position+t['G'].position+t['B'].position+t['Y'].position) != 6)
        {
            if(t['R'].position == -1)
                t['R'].position = 6-(+t['G'].position+t['B'].position+t['Y'].position);
            if(t['G'].position == -1)
                t['R'].position = 6-(+t['R'].position+t['B'].position+t['Y'].position);
            if(t['B'].position == -1)
                t['R'].position = 6-(+t['G'].position+t['R'].position+t['Y'].position);
            if(t['Y'].position == -1)
                t['R'].position = 6-(+t['G'].position+t['B'].position+t['R'].position);
        }
        char w[4];
        for(int l=0;l<4;l++)
        {
            if(t['R'].position==l)
                w[l]= 'R';
            else if(t['B'].position==l)
                w[l]= 'B';
            else if(t['G'].position==l)
                w[l]= 'G';
            else if(t['Y'].position==l)
                w[l]= 'Y';
        }
        int c=len%4;
        int d=len/4;
        if(c==0)
        {
            t['R'].cnt= d-t['R'].cnt;
            t['B'].cnt= d-t['B'].cnt;
            t['Y'].cnt= d-t['Y'].cnt;
            t['G'].cnt= d-t['G'].cnt;
        }
        else if(c == 1)
        {
            t[w[0]].cnt= d+1-t[w[0]].cnt;
            t[w[1]].cnt= d-t[w[1]].cnt;
            t[w[2]].cnt= d-t[w[2]].cnt;
            t[w[3]].cnt= d-t[w[3]].cnt;
        }
        else if(c == 2)
        {
            t[w[0]].cnt= d+1-t[w[0]].cnt;
            t[w[1]].cnt= d+1-t[w[1]].cnt;
            t[w[2]].cnt= d-t[w[2]].cnt;
            t[w[3]].cnt= d-t[w[3]].cnt;
        }
        else if(c == 3)
        {
            t[w[0]].cnt= d+1-t[w[0]].cnt;
            t[w[1]].cnt= d+1-t[w[1]].cnt;
            t[w[2]].cnt= d+1-t[w[2]].cnt;
            t[w[3]].cnt= d-t[w[3]].cnt;
        }
        printf("case #%d:\n%d %d %d %d\n",j,t['R'].cnt,t['B'].cnt,t['Y'].cnt,t['G'].cnt);
    }
    return 0;
}
