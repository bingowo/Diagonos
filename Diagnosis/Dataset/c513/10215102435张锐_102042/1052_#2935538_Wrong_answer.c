#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[50];
        scanf("%s",s);
        int len=strlen(s);
        //有没有1
        int num01=0,num02=0,num03=0,num04=0;
        int num11=0,num12=0,num13=0;
        int num21=0,num22=0,num23=0;
        int num31=0,num32=0,num33=0,num34=0,num35=0;
        int num41=0,num42=0,num43=0,num44=0;
        int num51=0,num52=0,num53=0,num54=0;
        int num61=0,num62=0,num63=0;
        int num71=0,num72=0,num73=0,num74=0,num75=0;
        int num81=0,num82=0,num83=0,num84=0,num85=0;
        int num91=0,num92=0,num93=0,num94=0;
        int ii=0;int ans[30];
        for(int j=0;j<len;j++)
        {
            if(s[j]=='Z') num01++;
            if(s[j]=='E') num02++;
            if(s[j]=='R') num03++;
            if(s[j]=='O') num04++;//0
            if(s[j]=='O') num11++;
            if(s[j]=='N') num12++;
            if(s[j]=='E') num13++;//1
            if(s[j]=='T') num21++;
            if(s[j]=='W') num22++;
            if(s[j]=='O') num23++;//2
            if(s[j]=='T') num31++;
            if(s[j]=='H') num32++;
            if(s[j]=='R') num33++;
            if(s[j]=='E') num34++;
            if(s[j]=='E') num35++;//3
            if(s[j]=='F') num41++;
            if(s[j]=='O') num42++;
            if(s[j]=='U') num43++;
            if(s[j]=='R') num44++;//4
            if(s[j]=='F') num51++;
            if(s[j]=='I') num52++;
            if(s[j]=='V') num53++;
            if(s[j]=='E') num54++;//5
            if(s[j]=='S') num61++;
            if(s[j]=='I') num62++;
            if(s[j]=='X') num63++;//6
            if(s[j]=='S') num71++;
            if(s[j]=='E') num72++;
            if(s[j]=='V') num73++;
            if(s[j]=='E') num74++;
            if(s[j]=='N') num75++;//7
            if(s[j]=='E') num81++;
            if(s[j]=='I') num82++;
            if(s[j]=='G') num83++;
            if(s[j]=='H') num84++;
            if(s[j]=='T') num85++;//8
            if(s[j]=='N') num91++;
            if(s[j]=='I') num92++;
            if(s[j]=='N') num93++;
            if(s[j]=='E') num94++;//9
        }
        while(num01!=0&&num02!=0&&num03!=0&&num04!=0) {ans[ii++]=0;num01--;num02--;num03--;num04--;}//0
        while(num11!=0&&num12!=0&&num13!=0) {ans[ii++]=1;num11--;num12--;num13--;}//1
        while(num21!=0&&num22!=0&&num23!=0) {ans[ii++]=2;num21--;num22--;num23--;}//2
        while(num31!=0&&num32!=0&&num33!=0&&num34!=0&&num35!=0) {ans[ii++]=3;num31--;num32--;num33--;num34--;num35--;}//3
        while(num41!=0&&num42!=0&&num43!=0&&num44!=0) {ans[ii++]=4;num41--;num42--;num43--;num44--;}//4
        while(num51!=0&&num52!=0&&num53!=0&&num54!=0) {ans[ii++]=5;num51--;num52--;num53!=0;num54!=0;}//5
        while(num61!=0&&num62!=0&&num63!=0) {ans[ii++]=6;num61--;num62--;num63--;}//6
        while(num71!=0&&num72!=0&&num73!=0&&num74!=0&&num75!=0) {ans[ii++]=7;num71--;num72--;num73--;num74--;num75--;}//7
        while(num81!=0&&num82!=0&&num83!=0&&num84!=0&&num85!=0) {ans[ii++]=8;num81--;num82--;num83--;num84--;num85--;}//8
        while(num91!=0&&num92!=0&&num93!=0&&num94!=0) {ans[ii++]=9;num91--;num92--;num93--;num94--;}//9
        printf("case #%d:\n");
        for(int j=0;j<ii;j++) printf("%d",ans[j]);
        printf("\n");
    }
    return 0;
}
