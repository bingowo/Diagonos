#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char start[7] = {"$GPRMC"};
char end[4] = {"END"};

int main()
{
    char s1[1007],ss[1007],time[7],h[3],m[5],s[5],x[5],z[5];
    int hour,i,k,j,r,sum;
    while(1)
    {
         scanf("%s",ss);
         if(strcmp(ss,end) == 0)break;
         int len = strlen(ss);
         strcpy(x,strstr(ss,"*")+1);//strstr是返回字符串；
         //printf("%s\n",strstr(ss,"*"));
         for(i = 2,sum = ss[1]; ss[i] != '*'; i++){sum ^= ss[i];}
         sprintf(z,"%X",sum%65536);//将sum%65536转化为16进制字符串存到z中；
         if(strcmp(x,z) != 0)continue;
         for(i = 0; i < len-6; i++)
          {
             for(j = i,k = 0; k < 6; j++,k++)s1[k] = ss[j];
             s1[k] = '\0';
             if(strcmp(s1,start) == 0)
                {
                    for(k = j+1,r = 0; r < 6; r++,k++)time[r] = ss[k];
                    hour = (time[0]-'0')*10 + time[1]-'0' + 8;
                    if(hour >= 10&&hour < 24){h[0] = hour/10 + '0';h[1] = hour%10 + '0';h[2] = '\0';}
                    else if(hour < 10){h[0] = '0';h[1] = hour + '0';h[2] = '\0';}
                    else if(hour == 24){h[0] = '0';h[1] = '0';h[2] = '\0';}
                    strcpy(m,time+2);strcpy(s,time+4);
                    m[2] = '\0';s[2] = '\0';
                }
         }
    }
    printf("%s:%s:%s",h,m,s);
    return 0;
}

