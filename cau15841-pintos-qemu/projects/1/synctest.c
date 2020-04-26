//#include <stdio.h>
//#include "./threads/thread.h"
//void test(){
//	int i=0;
//	while(i<10000){
//	//if(i==100 || i==500)
//	if(i%20==0)	
//		thread_sleep(1);
//	printf("%d :%s  \n",i,thread_name());
//	i++;
//	}
//	return;	
//}
//void synctest(void)
//{
//	printf("implement synchronize test!!!\n");
////jjeong
//	tid_t tid1 = thread_create("1gogosing",PRI_DEFAULT,test,NULL);
//	tid_t tid2 = thread_create("2gogosing",PRI_DEFAULT,test,NULL);
//	tid_t tid3 = thread_create("3gogosing",PRI_DEFAULT,test,NULL);
//	tid_t tid4 = thread_create("4gogosing",PRI_DEFAULT,test,NULL);
//	thread_join(tid1);
//	printf("1 is done !\n");
//	thread_join(tid2);
//	printf("2 is done !\n");
//	thread_join(tid3);
//	printf("3 is done !\n");
//	thread_join(tid4);
//	printf("done");
//	return ;
//}


#include <stdio.h>
#include "./threads/thread.h"
void test(){
        int i=0;
        while(i<10000) {
                thread_sleep(1);
                printf("%d : %s\n",i++,thread_name());
        }
        return;
}
void synctest(void)
{
        printf("implement synchronize test!!!\n");

        tid_t thread_ids[4];
        const char *thread_names[4] = {"Thread1","Thread2","Thread3","Thread3"};
        int i;
//joys


        for (i=0;i<4;i++) {

                thread_ids[i] = thread_create(thread_names[i],PRI_DEFAULT,test,NULL);

        }

        for (i=0;i<4;i++) {

                thread_join(thread_ids[i]);
                printf("%s is done !\n",thread_names[i]);
        }

//        thread_join(tid2);
//        printf("2 is done !\n");
//        thread_join(tid3);
//        printf("3 is done !\n");
//        thread_join(tid4);

        printf("FINISH!!!\n");
        return ;
}


