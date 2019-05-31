#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int n, m;
pthread_t tid[2];

int primeNumber(int foo, int temp) {
    n = foo;
    if (n <= 1) {
         printf("%d is not a prime number \n", n);
         return 0;
    }
    if (temp > foo/2) {
        printf("%d is a prime number \n", n);
        return 0;
    }
    else {
        if (n % temp == 0) {
            printf("%d is not a prime number \n", n);
            return 0;
        }
        else return primeNumber(foo, temp+1);
    }
    return 0;
}

int primeNumber_alt(int foo) {
    int divisors = 2;
    n = foo;
    if (n <= 1) {
         printf("%d is not a prime number \n", n);
         return 0;
    }
    else {
        for (int i = 2; i <= foo/2; i++) {
            if (n % i == 0) divisors++;
        }
    }
    if (divisors == 2) printf("%d is a prime number \n", n);
    else printf("%d is not a prime number \n", n);
    return 0;
}

int factorial(int bar) {
    m = 1;
    if (bar == 0 || bar == 1) {
        printf("%d! is %d \n", bar, m);
        return 0;
    }
    else {
        for (int i = 2; i <= bar; i++) {
        m = m * i;
        }
        }
    printf("%d! is %d \n", bar, m);
    return 0;
}

void *primeThread(void *param) {
	primeNumber_alt(n);
	pthread_exit(NULL);
}

void *factThread(void *param) {
	factorial(m);
	pthread_exit(NULL);
}

int main() {
    printf("Enter value for n: ");
    scanf("%d", &n);
    printf("Enter value for m: ");
    scanf("%d", &m);
    printf("Creating primeNumber thread... \n");
    pthread_create(&tid[0], NULL, primeThread, NULL);
    printf("Creating factorial thread... \n");
    pthread_create(&tid[1], NULL, factThread, NULL);
    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_exit(NULL);
    return 0;
}
