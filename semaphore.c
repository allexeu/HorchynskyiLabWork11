
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>

#define SEMAPHORE_NAME "/Horchynskyi"

int main(int argc, char **argv){
        sem_t *sem;
        if(argc != 2){
                if((sem = sem_open(SEMAPHORE_NAME, O_CREAT, 0770, 0)) == SEM_FAILED){
                        fprintf(stderr, "Horchynskyi sem_open error");
                        return 1;
                }
                printf("Horchynskyi sem_open. Horchynskyi semaphore is taken.\nWaiting for it to be dropped.\n");
                if(sem_wait(sem)<0)
                        fprintf(stderr, "Horchynskyi sem_wait error");
                if(sem_close(sem)<0)
                        fprintf(stderr, "Horchynskyi sem_close error");
                return 0;
        }
        else{
                printf("Dropping Horchynskyi semaphore\n");
                if((sem = sem_open(SEMAPHORE_NAME, 0)) == SEM_FAILED){
                        fprintf(stderr, "Horchynskyi sem_open error");
                        return 1;
                }
                sem_post(sem);
                printf("Horchynskyi sem_post. Horchynskyi semaphore dropped.\n");
                return 0;
        }
}
