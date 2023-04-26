#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char h[3] = {},m[3] = {},second[3] = {}; int hour_ = 0;

int main()
{
    char *s = (char*)malloc(10001);
    while (gets(s))
    {
        char *part[101]; int index = 0;
        char *ptr;
        char buf[1001] = {};

        if (strcmp(s,"END")==0) break;
        for (int i=0;s[i]!=',';i++) buf[i] = s[i];
        if (strcmp(buf,"$GPRMC")!=0) continue;
        memset(buf,0,sizeof(buf));

        int p;
        int check = s[1];
        for (p=2;s[p]!='*';p++) check ^= s[p];
        char num[10] = {};
        for (int q=0;s[p+q+1];q++) num[q] = s[p+q+1];
        long code = strtol(num,NULL,16);

        for (int i=0;s[i];i++) if (s[i]==',') s[i] = ' ';
        strcat(s," ");

        while (sscanf(s,"%s",buf)!=EOF)
        {
            s = strchr(s,' ')+1;
            ptr = (char*)malloc(strlen(buf)+1);
            strcpy(ptr,buf);
            part[index++] = ptr;
        }
        if (strcmp(part[0],"END")==0) break;
        if (strcmp(part[0],"$GPRMC")!=0||strcmp(part[2],"A")!=0||check!=code) continue;

        h[0] = part[1][0],h[1] = part[1][1]; 
        m[0] = part[1][2],m[1] = part[1][3];
        second[0] = part[1][4],second[1] = part[1][5];
        int hour = atoi(h);
        double longtitude = atof(part[5])/100;
        int delta = 0;
        for (;fabs(longtitude-delta*15)>7.5;delta++) ;
        int sign = (strcmp(part[6],"E")==0)?1:-1;
        hour = (hour+24+sign*delta)%24;
        hour_ = hour;
        memset(s,0,sizeof(s));
    }
    printf("%d:%s:%s\n",hour_,m,second);
    return 0;
}