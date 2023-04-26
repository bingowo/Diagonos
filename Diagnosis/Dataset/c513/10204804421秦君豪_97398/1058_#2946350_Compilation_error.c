
#include <iostream>
#include<fstream>
#include<cstdlib>
#include<string.h>
using namespace std;
char fsm[8][128];

void initfsm()
{
    int line_len=128;
    memset(fsm[0],0,line_len);
    memset(fsm[0],0,line_len);
    memset(fsm[1],0,line_len);
    memset(fsm[2],2,line_len);
    memset(fsm[3],3,line_len);
    memset(fsm[4],3,line_len);
    memset(fsm[5],5,line_len);
    memset(fsm[6],5,line_len);
    memset(fsm[7],0,line_len);
    fsm[0]['/']=1;
    fsm[0]['"']=5;
    fsm[0]['\'']=5;
    fsm[1]['/']=2;
    fsm[1]['*']=3;
    fsm[1]['"']=5;
    fsm[1]['\'']=5;
    fsm[2]['\n']=7;
    fsm[3]['*']=4;
    fsm[4]['/']=7;
    fsm[4]['*']=4;
    fsm[5]['"']=0;
    fsm[5]['\'']=0;
    fsm[5]['\\']=6;
    fsm[7]['/']=1;
    fsm[7]['"']=5;
    fsm[7]['\'']=5;
}
int main()
{
    int state=0;
    char c;
    string s;
    initfsm();
    while ((c=cin.get())!=EOF)
    {
        state=fsm[state][c];
        s+=c;
        switch(state)
        {
            case 0:
                cout<<s;
                s="";
                break;
            case 7:
                s="";
                if(c=='\n') cout<<c;
                break;

        }
        //cout<<"c="<<c<<'\n';

    }
    return 0;
}
























//int main(int argc,char **argv)
//{
//    ifstream fin;
//    fin.open(argv[2]);
//    ofstream fout;
//    fout.open(argv[1]);
//    while(!fin.eof())
//    {
//        char c;
//        fin.get(c);
//    }
//    fin.close()
//    fout.close();
//    return 0;
//}
评测报告
只显示前 512 个字节
测试点 #1: time: 0.007s, memory: 0.605 MB, exit code: 0, verdict: ACCEPTED
input
// Program1 
int main(){return 0;}
output

int main(){return 0;}
answer

int main(){return 0;}
checker's comment
2 lines
测试点 #2: time: 0.007s, memory: 0.613 MB, exit code: 0, verdict: ACCEPTED
input
/* Program2 
*/int main(){return 0;}
output
int main(){return 0;}
answer
int main(){return 0;}
checker's comment
single line: 'int main(){return 0;}'
测试点 #3: time: 0.007s, memory: 0.613 MB, exit code: 0, verdict: ACCEPTED
input
char* s ="// Program1";
int main(){return 0;}
output
char* s ="// Program1";
int main(){return 0;}
answer
char* s ="// Program1";
int main(){return 0;}
checker's comment
2 lines
测试点 #4: time: 0.020s, memory: 0.480 MB, exit code: 0, verdict: ACCEPTED
input
//This is a Test Input File for EraseComments
//Apr. 7, 2019

/*******************************************************************
// Programming problem:  Eight Queens Problem. 
//******************************************************************/
#include <iostream> // for cout
#include <fstream>  // for file operations
#include <iomanip>  // for setw
#include <ctime>    // for run time counting

using namespace std;

const int MAXNUM = 12 ;   //NUM <= 12

int NUM ;   

/**********************************...
output




#include <iostream> 
#include <fstream>  
#include <iomanip>  
#include <ctime>    

using namespace std;

const int MAXNUM = 12 ;   

int NUM ;   




void printBoard(const char [][MAXNUM]); 



void place(char [][MAXNUM],char,char);



void rotatematrix90(int rrow[MAXNUM],int rrow1[MAXNUM]);



bool canfound(int rrow[MAXNUM], int rowcol[][MAXNUM],int solution);

int rowcol[14200][MAXNUM];
int solution=0;
int diffrowcol[3574][MAXNUM];
int diffsolution=0;

char c='\"';
const char* p = "sdjksd\"\\d//fj/*...
answer




#include <iostream> 
#include <fstream>  
#include <iomanip>  
#include <ctime>    

using namespace std;

const int MAXNUM = 12 ;   

int NUM ;   




void printBoard(const char [][MAXNUM]); 



void place(char [][MAXNUM],char,char);



void rotatematrix90(int rrow[MAXNUM],int rrow1[MAXNUM]);



bool canfound(int rrow[MAXNUM], int rowcol[][MAXNUM],int solution);

int rowcol[14200][MAXNUM];
int solution=0;
int diffrowcol[3574][MAXNUM];
int diffsolution=0;

char c='\"';
const char* p = "sdjksd\"\\d//fj/*...
checker's comment
187 lines
测试点 #5: time: 0.009s, memory: 0.480 MB, exit code: 0, verdict: ACCEPTED
input
#include <iostream>
#include <string>
using namespace std;

int main()
{   int state{};  bool out;  char c;
    while(cin.get(c))
    {  switch(state)
       {  case   0:  out=true;
 		         break;
       }
       if (out) cout << c;
    }
    return 0;
} 


output
#include <iostream>
#include <string>
using namespace std;

int main()
{   int state{};  bool out;  char c;
    while(cin.get(c))
    {  switch(state)
       {  case   0:  out=true;
 		         break;
       }
       if (out) cout << c;
    }
    return 0;
} 


answer
#include <iostream>
#include <string>
using namespace std;

int main()
{   int state{};  bool out;  char c;
    while(cin.get(c))
    {  switch(state)
       {  case   0:  out=true;
 		         break;
       }
       if (out) cout << c;
    }
    return 0;
} 


checker's comment
16 lines
测试点 #6: time: 0.008s, memory: 0.344 MB, exit code: 0, verdict: ACCEPTED
input
Line01: char c='\"';
Line02: const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks";
Line03: 
Line04: int main()
Line05: {
Line06: 
Line07:     cout << "//The number of queens (4 -- 12) :// " ;
Line08:     cin  >> NUM;
Line09:    
Line10:    
Line11:     return 0;
Line12: }
Line13: 
Line14: // if (!canfound(rrow,rowcol,solution))
Line15: 
Line16: 
Line17: // End of the Program. 
Line18: // PLEASE check after processing by your program
Line19: 
output
Line01: char c='\"';
Line02: const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks";
Line03: 
Line04: int main()
Line05: {
Line06: 
Line07:     cout << "//The number of queens (4 -- 12) :// " ;
Line08:     cin  >> NUM;
Line09:    
Line10:    
Line11:     return 0;
Line12: }
Line13: 
Line14: 
Line15: 
Line16: 
Line17: 
Line18: 
Line19: 
answer
Line01: char c='\"';
Line02: const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks";
Line03: 
Line04: int main()
Line05: {
Line06: 
Line07:     cout << "//The number of queens (4 -- 12) :// " ;
Line08:     cin  >> NUM;
Line09:    
Line10:    
Line11:     return 0;
Line12: }
Line13: 
Line14: 
Line15: 
Line16: 
Line17: 
Line18: 
Line19: 
checker's comment
19 lines
测试点 #7: time: 0.008s, memory: 0.605 MB, exit code: 0, verdict: ACCEPTED
input
Line01: char c='\"';
Line02: const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks";
Line03: 
Line04: int main()
Line05: {
Line06: 
Line07:     cout << "//The number of queens (4 -- 12) :// " ;
Line08:     cin  >> NUM;
Line09:    
Line10:    
Line11:     return 0;
Line12: }
Line13: 
Line14: // if (!canfound(rrow,rowcol,solution))
Line15: 
Line16: 
Line17: // End of the Program. 
Line18: // PLEASE check after processing by your program
Line19: /*END**///END
output
Line01: char c='\"';
Line02: const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks";
Line03: 
Line04: int main()
Line05: {
Line06: 
Line07:     cout << "//The number of queens (4 -- 12) :// " ;
Line08:     cin  >> NUM;
Line09:    
Line10:    
Line11:     return 0;
Line12: }
Line13: 
Line14: 
Line15: 
Line16: 
Line17: 
Line18: 
Line19: 
answer
Line01: char c='\"';
Line02: const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks";
Line03: 
Line04: int main()
Line05: {
Line06: 
Line07:     cout << "//The number of queens (4 -- 12) :// " ;
Line08:     cin  >> NUM;
Line09:    
Line10:    
Line11:     return 0;
Line12: }
Line13: 
Line14: 
Line15: 
Line16: 
Line17: 
Line18: 
Line19: 
checker's comment
19 lines
测试点 #8: time: 0.008s, memory: 0.480 MB, exit code: 0, verdict: ACCEPTED
input
Line01:  
Line02: const char* p = "sdjksd";//
Line03: 
Line04: int main()
Line05: {
Line06: 
Line07:     cout << "//The number of queens (4 -- 12) :// " ;
Line08:     cin  >> NUM;
Line09:    
Line10:    
Line11:     return 0;
Line12: }
Line13: 
Line14: // if (!canfound(rrow,rowcol,solution))
Line15: 
Line16: 
Line17: // End of the Program. 
Line18: // PLEASE check after processing by your program
Line19: /*END**///END
Line20: /*dsjsdj*//*fff*///sssds/*gflg
output
Line01:  
Line02: const char* p = "sdjksd";
Line03: 
Line04: int main()
Line05: {
Line06: 
Line07:     cout << "//The number of queens (4 -- 12) :// " ;
Line08:     cin  >> NUM;
Line09:    
Line10:    
Line11:     return 0;
Line12: }
Line13: 
Line14: 
Line15: 
Line16: 
Line17: 
Line18: 
Line19: 
Line20: 
answer
Line01:  
Line02: const char* p = "sdjksd";
Line03: 
Line04: int main()
Line05: {
Line06: 
Line07:     cout << "//The number of queens (4 -- 12) :// " ;
Line08:     cin  >> NUM;
Line09:    
Line10:    
Line11:     return 0;
Line12: }
Line13: 
Line14: 
Line15: 
Line16: 
Line17: 
Line18: 
Line19: 
Line20: 
checker's comment
20 lines
测试点 #9: time: 0.007s, memory: 0.363 MB, exit code: 0, verdict: ACCEPTED
input
class Sort{
    public:
        /**
        * Simple Bubble Sort algorithm
        *
        * @param list vector of strings to sort
        * @return sorted vector of strings
        */
        static std::vector<std::string> bubbleSort(std::vector<std::string> list);
};
output
class Sort{
    public:
        
        static std::vector<std::string> bubbleSort(std::vector<std::string> list);
};
answer
class Sort{
    public:
        
        static std::vector<std::string> bubbleSort(std::vector<std::string> list);
};
checker's comment
5 lines
测试点 #10: time: 0.007s, memory: 0.480 MB, exit code: 0, verdict: ACCEPTED
input
#include "sort.h"

/**
* Simple Bubble Sort algorithm
*
* @param list vector of strings to sort
* @return sorted vector of strings
*/
std::vector<std::string> Sort::bubbleSort(std::vector<std::string> list){
    //Do anything
}
output
#include "sort.h"


std::vector<std::string> Sort::bubbleSort(std::vector<std::string> list){
    
}
answer
#include "sort.h"


std::vector<std::string> Sort::bubbleSort(std::vector<std::string> list){
    
}
checker's comment
6 lines
测试点 #11: time: 0.021s, memory: 0.613 MB, exit code: 0, verdict: ACCEPTED
input

char c='\'',cc{'\"'},ccc{'\"'},cccc{'\\'}/**//*******/;

const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks""\"\"\'\\";

int main()
{

    cout << "//The number of queens (4 -- 12) :// " ;
    cin  >> NUM;
   
   long startTime=clock();//time(0);

   char board[MAXNUM][MAXNUM];

   for (char y=0;y<NUM;y++)
   {
       memset(board,0,MAXNUM*MAXNUM);
       place(board,0,y);
   }

    long endTime=clock();

    ofstream outFile1("full.txt");
   for ( int i=0;i<solution;i++ )
   {
       outFile1 << setw(3) ...
output

char c='\'',cc{'\"'},ccc{'\"'},cccc{'\\'};

const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks""\"\"\'\\";

int main()
{

    cout << "//The number of queens (4 -- 12) :// " ;
    cin  >> NUM;
   
   long startTime=clock();

   char board[MAXNUM][MAXNUM];

   for (char y=0;y<NUM;y++)
   {
       memset(board,0,MAXNUM*MAXNUM);
       place(board,0,y);
   }

    long endTime=clock();

    ofstream outFile1("full.txt");
   for ( int i=0;i<solution;i++ )
   {
       outFile1 << setw(3) << i+1 << ":" ;
       ...
answer

char c='\'',cc{'\"'},ccc{'\"'},cccc{'\\'};

const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks""\"\"\'\\";

int main()
{

    cout << "//The number of queens (4 -- 12) :// " ;
    cin  >> NUM;
   
   long startTime=clock();

   char board[MAXNUM][MAXNUM];

   for (char y=0;y<NUM;y++)
   {
       memset(board,0,MAXNUM*MAXNUM);
       place(board,0,y);
   }

    long endTime=clock();

    ofstream outFile1("full.txt");
   for ( int i=0;i<solution;i++ )
   {
       outFile1 << setw(3) << i+1 << ":" ;
       ...
checker's comment
152 lines
测试点 #12: time: 0.019s, memory: 0.480 MB, exit code: 0, verdict: ACCEPTED
input

char c="\\/**//*******/\\\\\\\\"/**?**/;

const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks""\"\"\'\\";

int main()
{

    cout << "//The number of queens (4 -- 12) :// " ;
    cin  >> NUM;
   
   long startTime=clock();//time(0);

   char board[MAXNUM][MAXNUM];

   for (char y=0;y<NUM;y++)
   {
       memset(board,0,MAXNUM*MAXNUM);
       place(board,0,y);
   }

    long endTime=clock();

    ofstream outFile1("full.txt");
   for ( int i=0;i<solution;i++ )
   {
       outFile1 << setw(3) << i+1 << ":" ;...
output

char c="\\/**//*******/\\\\\\\\";

const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks""\"\"\'\\";

int main()
{

    cout << "//The number of queens (4 -- 12) :// " ;
    cin  >> NUM;
   
   long startTime=clock();

   char board[MAXNUM][MAXNUM];

   for (char y=0;y<NUM;y++)
   {
       memset(board,0,MAXNUM*MAXNUM);
       place(board,0,y);
   }

    long endTime=clock();

    ofstream outFile1("full.txt");
   for ( int i=0;i<solution;i++ )
   {
       outFile1 << setw(3) << i+1 << ":" ;
        for (int...
answer

char c="\\/**//*******/\\\\\\\\";

const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks""\"\"\'\\";

int main()
{

    cout << "//The number of queens (4 -- 12) :// " ;
    cin  >> NUM;
   
   long startTime=clock();

   char board[MAXNUM][MAXNUM];

   for (char y=0;y<NUM;y++)
   {
       memset(board,0,MAXNUM*MAXNUM);
       place(board,0,y);
   }

    long endTime=clock();

    ofstream outFile1("full.txt");
   for ( int i=0;i<solution;i++ )
   {
       outFile1 << setw(3) << i+1 << ":" ;
        for (int...
checker's comment
152 lines
测试点 #13: time: 0.021s, memory: 0.480 MB, exit code: 0, verdict: ACCEPTED
input

char c="\\/**//*******/\\\\\\\\"/**?**/;

const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks""\"\"\'\\";

int main()
{

    cout << "//The number of queens (4 -- 12) :// " ;
    cin  >> NUM;
   
   long startTime=clock();//time(0);

   char board[MAXNUM][MAXNUM];

   for (char y=0;y<NUM;y++)
   {
       memset(board,0,MAXNUM*MAXNUM);
       place(board,0,y);
   }

    long endTime=clock();

    ofstream outFile1("full.txt");
   for ( int i=0;i<solution;i++ )
   {
       outFile1 << setw(3) << i+1 << ":" ;...
output

char c="\\/**//*******/\\\\\\\\";

const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks""\"\"\'\\";

int main()
{

    cout << "//The number of queens (4 -- 12) :// " ;
    cin  >> NUM;
   
   long startTime=clock();

   char board[MAXNUM][MAXNUM];

   for (char y=0;y<NUM;y++)
   {
       memset(board,0,MAXNUM*MAXNUM);
       place(board,0,y);
   }

    long endTime=clock();

    ofstream outFile1("full.txt");
   for ( int i=0;i<solution;i++ )
   {
       outFile1 << setw(3) << i+1 << ":" ;
        for (int...
answer

char c="\\/**//*******/\\\\\\\\";

const char* p = "sdjksd\"\\d//fj/*kdhjk\"dsfjl*/dks""\"\"\'\\";

int main()
{

    cout << "//The number of queens (4 -- 12) :// " ;
    cin  >> NUM;
   
   long startTime=clock();

   char board[MAXNUM][MAXNUM];

   for (char y=0;y<NUM;y++)
   {
       memset(board,0,MAXNUM*MAXNUM);
       place(board,0,y);
   }

    long endTime=clock();

    ofstream outFile1("full.txt");
   for ( int i=0;i<solution;i++ )
   {
       outFile1 << setw(3) << i+1 << ":" ;
        for (int...
checker's comment
150 lines
#	提交时间	评测时间	语言	评测结果	耗时	内存
2943629	2022-03-19 18:12:40	2022-03-19 18:12:44	C++11	
Accepted: 100
0.021	0.613
2943054	2022-03-19 16:43:06	2022-03-19 16:43:11	C++11	
Wrong answer: 36
0.020	0.742
2943027	2022-03-19 16:40:32	2022-03-19 16:40:37	C++11	
Wrong answer: 45
0.020	0.613
2942757	2022-03-19 16:15:40	2022-03-19 16:15:44	C++11	
Wrong answer: 91
0.026	0.742
服务
首页
反馈
Polygon
Wiki
开源
Github
eJudge
关于我们
团队: @ultmaster, @zerol, @kblack.
联系方式: acmsupport@admin.ecnu.edu.cn