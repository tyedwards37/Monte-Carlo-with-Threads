/// @file mcarlo.c
/// @brief - Runs a task through a given scheduler.
/// @author Tyler Edwards - tk.edwards2003@gmail.com

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double x;
double y;
int hitcount = 0;
int totalpoints;
double pi; 

void *runner(void *param); // thread 

int main(int argc, char *argv[])
{
pthread_t tid; // thread identifier
pthread_attr_t attr; // set of attributes for the thread 

if (argc != 2) {
	fprintf(stderr,"usage: a.out <integer value>\n");
	return -1;
}

if (atoi(argv[1]) < 0) {
	fprintf(stderr,"Argument %d must be non-negative\n",atoi(argv[1]));
	return -1;
}

totalpoints = atoi(argv[1]);

// get default attributes
pthread_attr_init(&attr);

// create thread
pthread_create(&tid,&attr,runner,argv[1]);

// wait for the thread to exit
pthread_join(tid,NULL);

pi = ((4.0 * (double) hitcount) / (double) totalpoints);

printf("Approximation of PI = %f\n",pi);
}

// Add task into the list of tasks
// @input N/A
// @output double
double random_double()
{
    return random() / ((double)RAND_MAX + 1);
}

// Add task into the list of tasks
// @input void
// @output N/A
void *runner(void *param) 
{
    for (int i = 0; i < totalpoints; i++)
    {
        x = random_double() * 2.0 - 1.0;
        y = random_double() * 2.0 - 1.0;

        if (sqrt(x*x + y*y) < 1.0)
        {
            hitcount++;
        }
    }

	pthread_exit(0);
}
