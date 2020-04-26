#include <stdio.h>
#include "./threads/thread.h"
void test(){
	int i=0;
	while(i<50)
	printf("%d :%s  \n",i++,thread_name());
	return;	
}
void synctest(void)
{
	printf("implement synchronize test!!!\n");
//jjeong
	tid_t tid1 = thread_create("1gogosing",PRI_DEFAULT,test,NULL);
	tid_t tid2 = thread_create("2gogosing",PRI_DEFAULT,test,NULL);
	tid_t tid3 = thread_create("3gogosing",PRI_DEFAULT,test,NULL);
	tid_t tid4 = thread_create("4gogosing",PRI_DEFAULT,test,NULL);
	thread_join(tid1);
	printf("1 is done !\n");
	thread_join(tid2);
	printf("2 is done !\n");
	thread_join(tid3);
	printf("3 is done !\n");
	thread_join(tid4);
	printf("done");
	return ;
}
