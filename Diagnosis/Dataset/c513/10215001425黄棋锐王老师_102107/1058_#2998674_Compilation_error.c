#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
static FILE* fpin;
static FILE* fpout;
 
/*
 * 删除注释状态机的状态
 */
 
#define STATUS_NORMAL   0 //正常状态;
#define STATUS_QUOTE    1 //引号内”;
#define STATUS_STIN1    2 //碰到第一个"/" 等待第二个"/"；
#define STATUS_STIN2    3 //碰到第二个"/" 并进入到注释内部；
#define STATUS_STINN    4 //进入到注释内部,碰到折行"\"；
#define STATUS_STACT    5 //虚拟状态，表示状态机打印。
 
/*
 * 状态机的动作
 */
 
#define STFLAG_NOACT    0 //没有任何动作，忽略字符；
#define STFLAG_FPUTC    1 //打印输出；
#define STFLAG_UNPUTC   2 //回退上一个字符；
 
/*
 * 128主要是考虑ascii码基本字符128个。这个状态表第一维表示状态机状态，第二维表示遇到的下一个字符，整个码表表示遇到下一个字符需要设置的状态。
 */
static int status_table[6][128];
static int status = STATUS_NORMAL;
 
#define st(i,j) status_table[(i)][(j)]
 
/*
 * 初始化状态码表，这里描述整体状态机的转换图。
 */
 
void set_status_table(int i,int j,int s)
{
    if (-1 != j){
        st(i,j) = s;
    }else{
        for (j = 0; j<128; ++j) {
            st(i,j) = s;
        }
    }
}
 
void init_status()
{
    set_status_table(STATUS_NORMAL,-1,STATUS_NORMAL);
    set_status_table(STATUS_NORMAL,'"',STATUS_QUOTE);
    set_status_table(STATUS_NORMAL,'/',STATUS_STIN1);
    
    set_status_table(STATUS_QUOTE,-1,STATUS_QUOTE);
    set_status_table(STATUS_QUOTE,'"',STATUS_NORMAL);
    
    set_status_table(STATUS_STIN1,-1,STATUS_NORMAL);
    set_status_table(STATUS_STIN1,'/',STATUS_STIN2);
    
    set_status_table(STATUS_STIN2,-1,STATUS_STIN2);
    set_status_table(STATUS_STIN2,'\\',STATUS_STINN);
    set_status_table(STATUS_STIN2,'\n',STATUS_NORMAL);
    
    set_status_table(STATUS_STINN,-1,STATUS_STINN);
    set_status_table(STATUS_STINN,'\n',STATUS_STIN2);
    
    set_status_table(STATUS_STACT, STATUS_NORMAL, STFLAG_FPUTC);
    set_status_table(STATUS_STACT, STATUS_QUOTE, STFLAG_FPUTC);
    set_status_table(STATUS_STACT, STATUS_STIN1, STFLAG_UNPUTC);
    set_status_table(STATUS_STACT, STATUS_STIN2, STFLAG_NOACT);
    set_status_table(STATUS_STACT, STATUS_STINN, STFLAG_NOACT);
    
}
 
 
#define file_noact ((status_handler_t)NULL)
typedef void (*status_handler_t)(char);
 
static void file_putc(char c);
static void file_unputc(char c);
 
static void status_handler(char c)
{
    const status_handler_t handler_a[] = {
        file_noact, file_putc, file_unputc
    };
    int actidx = st(STATUS_STACT, status);
    status_handler_t handler = handler_a[actidx];
    if (handler != NULL) handler(c);
}
 
static void show_status(char c);
static void show_status_end();
 
/*
 * 删除注释函数调用。
 */
 
void del_comment(char *inpath, char *outpath)
{
    char c;
    init_status();
    fpin = fopen(inpath, "r");
    fpout = fopen(outpath, "w");
    assert(fpin && fpout != NULL);
    while ((c = fgetc(fpin)) != EOF) {
        show_status(c);             //输入下一个字符前状态
        if (c == '\r') continue;
        status = st(status, (int)c);
        show_status_end();          //输入下一个字符后状态
        status_handler(c);
    }
}
 
 
/*
 *基础字符处理函数。
 */
 
static char *c_str(char c, char *buf, int size)
{
    if (c == ' ') return "_";
    else if (c == '\t') return "\\t";
    else if (c == '\n') return "\\n";
    else if (c == '\r') return "\\r";
    else if (c == '\0') return "\\0";
    snprintf(buf, size, "%c", c);
    return buf;
}
 
#define RET_STATUS_STRING(s)    \
if (status == (s)) return #s
 
static char *status_str(void)
{
    RET_STATUS_STRING(STATUS_NORMAL);
    RET_STATUS_STRING(STATUS_QUOTE);
    RET_STATUS_STRING(STATUS_STIN1);
    RET_STATUS_STRING(STATUS_STIN2);
    RET_STATUS_STRING(STATUS_STINN);
    return "invalid status";
}
 
static void show_status(char c)
{
    char t[4];
    fprintf(stdout, "[%s] -->(%s)-->",
            status_str(), c_str(c, t, sizeof t));
}
 
static void show_status_end()
{
    fprintf(stdout, "[%s]\n",status_str());
}
 
#define MAXLINE 256
static char linebuf[MAXLINE];
static char *lineptr = linebuf;
 
static void init_line_buf(void)
{
    memset(linebuf, 0, sizeof linebuf);
    lineptr = linebuf;
}
 
#define isblank(c) ((c) == ' ' || (c) == '\t' || (c) == '\n')
 
/* 
 * is writable （非空行 + 不多于1个的空行，可以输出。）
 */
static int is_wrt(void)
{
    char c, *ptr = linebuf;
    for ( ; (c = *ptr); ptr++) {
        if (!isblank(c))
        {
            //非空行
            return 1;
        }
    }
    return 0;
}
 
static void file_puts(void)
{
    static int lines; /* empty lines */
    
    if (is_wrt())//不是空行，设置lines = 0；
        lines = 0;
    else
        lines++;//统计有多少空行，如果多于1个空行就不把空行输出。
    if (lines > 1)
    {
        return;
    }
    
    unsigned long len = strlen(linebuf);
    fwrite(linebuf, len, 1, fpout);
}
 
static void file_putc(char c)
{
    *lineptr++ = c;
    /*
     *如果碰到换行符，输出获得的一行。
     */
    if (c == '\n') {
        file_puts();
        init_line_buf();
    }
}
 
static void file_unputc(char c)
{
    *--lineptr = 0;
}
