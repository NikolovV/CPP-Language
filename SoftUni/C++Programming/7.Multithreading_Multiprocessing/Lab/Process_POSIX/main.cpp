#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/mman.h>

using namespace std;

sem_t sm;
static pthread_mutex_t *consoleLock;

void *func2(void *arg)
{
    int a = (int) arg;
    sem_wait(&sm);
    pthread_mutex_lock(consoleLock);
    cout << "sem2 thread: " << a << endl;
    pthread_mutex_unlock(consoleLock);
    sleep(1);
    sem_post(&sm);
    pthread_exit(NULL);
}

void *func(void *arg)
{
    int a = (int) arg;
    sem_wait(&sm);
    pthread_mutex_lock(consoleLock);
    cout << "thread: " << a << endl;
    pthread_mutex_unlock(consoleLock);
    sleep(1);
    sem_post(&sm);
    pthread_exit(NULL);
}

int main()
{
    int n = 20, m = 10;
    pid_t forkres;
    pthread_t pth[n];
    pthread_t smthr[m];
    sem_init(&sm, 0, 4);
    consoleLock =(pthread_mutex_t *) mmap(NULL, sizeof * consoleLock, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(consoleLock, &attr);


    forkres = fork();
    if (forkres == 0)
    {
        // child
        for (int i = 0; i < n; i++)
        {
            pthread_create(&pth[i], NULL, func, (void*) i);
        }
        for (int i = 0; i < n; i++)
        {
            pthread_join(pth[i], NULL);
        }
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            pthread_create(&smthr[i], NULL, func2, (void *) i);
        }

        for (int i = 0; i < m; i++)
        {
            pthread_join(smthr[i], NULL);
        }

        sem_destroy(&sm);
        pthread_mutex_destroy(consoleLock);
    }
    return 0;
}