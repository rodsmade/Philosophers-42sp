# include <pthread.h>
# include <stdio.h>

void	*do_this(void *arg)
{
	printf("thread existiu, count: %d\n", (*((int *)arg))++);
	return (NULL);
}

int main()
{
	int			counts[2];
	pthread_t	thread1;
	pthread_t	thread2;

	counts[0] = 0;
	counts[1] = 42;
	pthread_create(&thread1, NULL, &do_this, (void *)&counts[0]);
	pthread_create(&thread2, NULL, &do_this, (void *)&counts[1]);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_create(&thread1, NULL, &do_this, (void *)&counts[0]);
	pthread_create(&thread2, NULL, &do_this, (void *)&counts[1]);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_create(&thread1, NULL, &do_this, (void *)&counts[0]);
	pthread_create(&thread2, NULL, &do_this, (void *)&counts[1]);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_create(&thread1, NULL, &do_this, (void *)&counts[0]);
	pthread_create(&thread2, NULL, &do_this, (void *)&counts[1]);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_create(&thread1, NULL, &do_this, (void *)&counts[0]);
	pthread_create(&thread2, NULL, &do_this, (void *)&counts[1]);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_create(&thread1, NULL, &do_this, (void *)&counts[0]);
	pthread_create(&thread2, NULL, &do_this, (void *)&counts[1]);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_create(&thread1, NULL, &do_this, (void *)&counts[0]);
	pthread_create(&thread2, NULL, &do_this, (void *)&counts[1]);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_create(&thread1, NULL, &do_this, (void *)&counts[0]);
	pthread_create(&thread2, NULL, &do_this, (void *)&counts[1]);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_create(&thread1, NULL, &do_this, (void *)&counts[0]);
	pthread_create(&thread2, NULL, &do_this, (void *)&counts[1]);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return (0);
}
