//string\1053.c


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*
    one word pressure test
*/

//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

char strin[500];
char UTCtime[20];

char tem_atf[30];
double degree;
int UTClen=0;
char ans[20];
char *str;
int bre_part(int o_pos)//return non , pos
{
    while(str[o_pos++]!=',')
        ;
    return o_pos;
}
int get_UTC(int pos)
{
    UTClen=0;
    while(str[pos]!=','){
        UTCtime[UTClen++]=str[pos++];
    }
    return pos+1;//
}
int get_lotitude(int pos)
{
    memset(tem_atf,0,30*sizeof(tem_atf[0]));
    int temlen=0;
    while(str[pos]!=','){
        tem_atf[temlen++]=str[pos++];
    }
    for(int i=0,j=temlen-1;i<j;++i,--j){
        char tem=tem_atf[i];
        tem_atf[i]=tem_atf[j];
        tem_atf[j]=tem;
    }
    degree=atof(tem_atf);
    return pos+1;//
}


int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    while(scanf("%s",strin)!=EOF){
        str=strstr(strin,"$GPRMC");
        if(str!=NULL){
            int pos=0;
            pos=bre_part(pos);//0 has been avoided
            pos=get_UTC(pos);//eat 1 string
            if(str[pos++]!='A')//eat 2 string
                continue;//check pos false
            ++pos;
            pos=bre_part(pos);//eat string 3
            pos=bre_part(pos);//eat string 4
            pos=bre_part(pos);
            pos=bre_part(pos);
            while(str[pos]!='*')
                ++pos;
            char *checkv=str+pos+1;
            int check;
            sscanf(checkv,"%x",&check);
            char *cp=str+1;//non $
            char tem_check=*cp++;
            while(*cp!='*'){
                tem_check^=*cp++;
            }
            if(tem_check!=check){
                continue;
            }else{
                //legal messages
                int hour=(UTCtime[0]-'0')*10+UTCtime[1]-'0'+8;
                hour%=24;
                sprintf(ans,"%2d:%c%c:%c%c",hour,UTCtime[2],UTCtime[3],UTCtime[4],UTCtime[5]);
            }//08 and 8 key
        }
    }
    printf("%s",ans);
}

