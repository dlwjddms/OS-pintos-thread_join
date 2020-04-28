#include <stdio.h>
#include "./threads/thread.h"
void test(){
        int i=0;
        while(i<3) {
                thread_sleep(1);
                printf("%d is printed by thread name ' %s' \n",i++,thread_name());
        }
        return;
}
void synctest(void)
{
        printf("implement synchronize test!!!\n");

        tid_t thread_ids[4];
        const char *thread_names[4] = {"test1","test2","test3","test"};
        int i;


        for (i=0;i<4;i++) {

                thread_ids[i] = thread_create(thread_names[i],PRI_DEFAULT,test,NULL);

        }

        for (i=0;i<4;i++) {

                thread_join(thread_ids[i]);
                printf("thread named '%s' is joined !\n",thread_names[i]);
        }

        printf(" synctest is finished !~! \n");
        return ;
}


