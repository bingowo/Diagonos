#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
00  pop
01  no
02  zip
03  zotz
04  tzec
05  xul
06  yoxkin
07  mol
08 chen
09  yax
10  zac
11 ceh
12  mac
13  kankin
14  muan
15  pax
16  koyab
17 cumhu
18  uayet
*/
#define N 10005
int y[N],m[N],d[N],r[N];
int n;
char ts[20];
char ms[19][10]={
    "pop","no","zip","zotz","tzec",
    "xul","yoxkin","mol","chen","yax",
     "zac","ceh","mac","kankin","muan",
     "pax","koyab","cumhu","uayet"};

void Init(){
    for(int i=0;i<n;i++) r[i]=i;
}

int Cmp(const int* pa, const int* pb){
    if(y[*pa]!=y[*pb]) return y[*pa]-y[*pb];
    if(m[*pa]!=m[*pb]) return m[*pa]-m[*pb];
    return d[*pa]-d[*pb];
}

int ms2mi(char* str){
    int i;
    for(i=0;i<19;i++)
        if(!strcmp(str,ms[i]))
            return i;
    return i;
}

int main(){
    int pros;
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        Init();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d. %s %d",d+i,ts,y+i);
            m[i]=ms2mi(ts);
        }
        qsort(r,n,sizeof(r[0]),Cmp);
        printf("case #%d:\n",cnt);
        for(int i=0;i<n;i++)
            printf("%d. %s %d\n",d[r[i]],ms[m[r[i]]],y[r[i]]);
    }

    return 0;
}
