#READ.ME

Project: Monte Carlo Using Threads
by Tyler Edwards and Jack de Bruyn
Added October 2023

Description: Implements a function using threads that caluclates the value of pie with the Monte Carlo technique. The larger the number inputted, the closer to the value of PI the output will be. 

Language: C 

Reason: For CPSC 380 (Operating Systems)

Successes: By implementing them in C, I gained a better understanding of how threads function.

Setbacks: Figuring out how to exit the thread then have the parent thread continue a calculation afterwards proved difficult/

Learned: how to use threads


/*
Commands:
gcc mcarlo.c -pthreads -o mcarlo
./mcarlo [INSERT NUMBER]

Output:
Approximation of PI = [CALCULATED NUMBER]
*/

- Started from in-class base code