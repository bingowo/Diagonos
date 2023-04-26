#include<string.h>
#include<stdio.h>
char* findstr(char* s1,char*s);
int findmax(char* s1,char* s2,char* s) {
    char* start=findstr(s1,s);
    char* ps=start+1;
    char* pend=ps;
    int lens2=strlen(s2);
    int max=0;
    while(*ps) {
        pend=findstr(s2,ps);
        if(pend==ps)break;
		ps=pend+1;
        int len=pend-lens2+1-start;
        if(len>max)max=len;

    }
    return max-1;
}
char * findstr(char* s1,char*s) {
    int len=strlen(s1);
    char *pstart=s;
    char *pend=s+1;
    int i;
    while(*pstart) {
        if(*pstart!=*s1)pstart++;
        else {
            for(i=1; i<len; i++) {
                if(*(s1+i)!=*(pstart+i)) {
                    pstart++;
					break;
                }
            }
            if(i==len){
            	pend=pstart+i;
            	break;
			}
           
        }
    }
    return pend-1;
}
int main() {
    int T,cnt=0;
    scanf("%d",&T);
    while(T--) {
        printf("case #%d:\n",cnt++);
        char s1[81]= {'\0'};
        char s2[81]= {'\0'};
        char s[81]= {'\0'};
        scanf("%s%s%s",s1,s2,s);
        printf("%d\n",findmax(s1,s2,s));
    }
}