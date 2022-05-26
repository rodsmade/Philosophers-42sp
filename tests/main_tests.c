// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <pthread.h>

// void	*workerThreadFunc(void *arg)
// {
// 	long	*tid;

// 	printf("entrou na thread\n");
// 	tid = (long *) arg;
// 	printf("thread number: %li\n", *tid);
// 	pthread_exit((void *)42);
// 	return ((void *)42);
// }

// int main()
// {
// 	pthread_t	tid0;
// 	pthread_t	tid1;
// 	pthread_t	tid2;
// 	pthread_t	*threads[] = {&tid0, &tid1, &tid2};
// 	int			i;

// 	i = -1;
// 	while (++i < 3)
// 	{
// 		pthread_create(threads[i], NULL, workerThreadFunc, (void *) threads[i]);
// 		printf("fora: thread[%i] número: %li\n", i, *(threads[i]));
// 	}
// 	return 0;
// }


/**
 * int pthread_detach(pthread_t thread); ----> usada para INDICAR q pode liberar os recursos da thread (a liberação dos garfos?), não para ENCERRAR a thread,
 * pthread_exit é proibida pelo pdf.
 * 
 */

#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

#define THREAD_NO 2

pthread_mutex_t	lock;
pthread_t tid[THREAD_NO];

/**
 * so here's the real deal:
 * threads will share GLOBAL variables - not variables declared in the calling func. GLOBAL variables.
 * threads will NOT share variables within the called function bc each thread will have it's own stack.
 * if you pass in an argument to a thread, that argument is too shared. 
 * 
 * IN THIS PROJECT GLOBAL VARIABLES ARE FORBIDDEN ! ! ! so ........
 */
void* doSomeThing(void *counter)
{
	unsigned long i = 0;
	// int my_id;

	pthread_mutex_lock(&lock);
	*((int *) counter) += 1;
	pthread_mutex_unlock(&lock);
	// my_id = *((int *) counter);
	printf("\n Job %d started\n", *((int *)counter));
	// printf("\n Job %d started\n", my_id);

	for(i=0; i<(0xFFFFFFFF);i++);
	printf("\n Job %d finished\n", *((int *)counter));
	// printf("\n Job %d finished\n", my_id);

	return NULL;
}

int main(void)
{
	int counter = 0;
	int i = 0;
	int err;

	pthread_mutex_init(&lock, NULL);
	while(i < THREAD_NO)
	{
		err = pthread_create(&(tid[i]), NULL, &doSomeThing, (void *)&counter);
		if (err != 0)
			printf("\ncan't create thread :[%s]", strerror(err));
		i++;
	}

	i = -1;
	while (++i < THREAD_NO)
		pthread_join(tid[i], NULL);

	printf("all jobs finished i guess?\n");
	pthread_mutex_destroy(&lock);

	return 0;
}