#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>


void* fir1(void* arg){
    for(int i = 1; i <= 4; i++){
    printf("Intrebarea %d\n", i);
    }
}

void *fir2(void* arg){
    char Intr1[] = "adevarat";
    char Intr2[] = "fals";
    char Intr3[] = "C";
    char Intr4[] = "D";
    for(int i =1; i <= 4; i++){
        if(i==1){
            printf("Raspunsul meu la intreabarea %d este %s\n",i,Intr1);
        }
        else if(i==2){
            printf("Raspunsul meu la intreabarea %d este %s\n",i,Intr2);
        }
        else if(i==3){
            printf("Raspunsul meu la intreabarea %d este %s\n",i,Intr3);
        }
        else{
            printf("Raspunsul meu la intreabarea %d este %s\n",i,Intr4);
        }
    }
}

void *fir3(void* arg){
    int count = 10;
    for(int i = 0; i <= 10; i++){
        sleep(1);
        printf("Timp Ramas: %d\n",count - i);
    }
}

int main(){
    char Nume[100];
    pthread_t th1;
    pthread_t th2;
    pthread_t th3;
    pthread_create(&th1, NULL, fir1, NULL);
    pthread_join(th1, NULL);
    pthread_create(&th2, NULL, fir2, NULL);
    pthread_join(th2, NULL);
    pthread_create(&th3, NULL, fir3, NULL);
    pthread_join(th3, NULL);
    printf("Numele Candidatului este:");
    scanf("%s",Nume);
    return 0;
}