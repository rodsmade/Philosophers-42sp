#include "philo.h"

int get_time(void)
{
	struct timeval	tv;
	struct timezone	tz;
	int				time_in_milliseconds;

	gettimeofday(&tv, &tz);
	time_in_milliseconds = ((int)tv.tv_usec) / 1000;
	printf("Microseconds: %ld\n", tv.tv_usec);
	printf("Milliseconds: %d\n", time_in_milliseconds);
	printf("Seconds: %d\n", time_in_milliseconds);
	return(time_in_milliseconds);
}
