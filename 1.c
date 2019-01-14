#include <stdio.h>

#include <pthread.h>

//#include <sys/time.h>

 

//linux for sleep(seconds) and usleep(Microsecond)

//#include <unistd.h>

 

//windows for Sleep(millisecond)

//#include <windows.h> 

 

 

//创建线程函数返回类型

pthread_t thread[1]; 

 

/**

* 线程函数

**/

void *printThread(){

 printf("%s\n","线程开始处理任务");

 

 printf("已经处理了:");

 for(int i = 1; i <= 100; i++) {

 if(i==1){

 //数字占3格，%占一格

 printf("%3d%%",i);

 }else{

 //退4格

 printf("\b\b\b\b%3d%%",i); 

 }

 //即时标准输出(不带\n，不刷新不行)

 fflush(stdout);

 //延时1秒

 sleep(1);

 }

}

 

 

int main(){

 

 printf("我是主函数哦，我正在创建线程，呵呵\n");

 /*创建线程*/

 if(pthread_create(&thread[0], NULL, printThread, NULL)!=0){

 printf("线程创建失败\n");

 }

 printf("线程创建成功\n");

 

 printf("我是主函数哦，我正在等待线程完成任务阿，呵呵\n");

 /*等待线程结束*/

 pthread_join(thread[0],NULL);

 printf("\n线程已经结束\n");

 

 return 1;

}
