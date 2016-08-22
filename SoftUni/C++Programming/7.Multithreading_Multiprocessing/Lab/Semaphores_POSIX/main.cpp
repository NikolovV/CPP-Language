#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

sem_t sm;
pthread_mutex_t consoleLock;

void *mxFunc(void *arg)
{
    int a = (int) arg;
    pthread_mutex_lock(&consoleLock);
    cout << "mx thread: " << a << endl;
    sleep(1);
    pthread_mutex_unlock(&consoleLock);
    pthread_exit(NULL);
}

void *func(void *arg)
{
    int a = (int) arg;
    sem_wait(&sm);
    pthread_mutex_lock(&consoleLock);
    cout << "thread: " << a << endl;
    pthread_mutex_unlock(&consoleLock);
    sleep(1);
    sem_post(&sm);
    pthread_exit(NULL);
}

int main()
{
    int n = 20, m = 10;
    pthread_t pth[n];
    pthread_t mxthr[m];
    sem_init(&sm, 0, 4);
    pthread_mutex_init(&consoleLock, NULL);
    //    sem_unlink("psem");

    for (int i = 0; i < n; i++)
    {
        pthread_create(&pth[i], NULL, func, (void*) i);
    }
    for (int i = 0; i < m; i++)
    {
        pthread_create(&mxthr[i], NULL, mxFunc, (void *) i);
    }


    for (int i = 0; i < m; i++)
    {
        pthread_join(mxthr[i], NULL);
    }
    for (int i = 0; i < n; i++)
    {
        pthread_join(pth[i], NULL);
    }
    sem_destroy(&sm);
    pthread_mutex_destroy(&consoleLock);
}