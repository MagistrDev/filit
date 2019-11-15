#include <time.h>
#include <stdio.h>

// Получить количество тактов с момента последнего сброса процессора
static __inline__ unsigned long long rdtsc(void)
{
    unsigned hi, lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

typedef struct {
    long len;
    float *data;
} vec;

long vec_len(vec *v) {
    return v->len;
}

void combine0(vec *v, float *dest)
{
    long i;
    *dest = 1;
    for (i = 0; i < vec_len(v); i++) {
        *dest *= v->data[i];
    }
}

#define SIZE 5000
float a[SIZE];
vec v = {SIZE, a};

int main(void)
{
    double time1 = clock() / (double)CLOCKS_PER_SEC;
    long cycles1 = rdtsc();
    float res;
    long i;
    //---------- ИЗМЕРИТЬ ЭТОТ КОД ----------
    for (i = 0; i < SIZE; i++)  // инициализация вектора случайными числами
        a[i] = rand();

    combine0(&v, &res);
    //----------------------
    double time2 = clock() / (double)CLOCKS_PER_SEC;
    long cycles2 = rdtsc();

    long cycles = cycles2 - cycles1;      // Столько тактов было потрачено
    double cpe = cycles / (double)SIZE;   // Столько тактов было потрачено на один элемент
    double cpu_time = time2 - time1;      // Потраченное процессорное время

    printf("CPU TIME: %.2f sec\n", cpu_time);
    printf("cycles:      %.2li\n", cycles);
    printf("CPE:      %.2f\n", cpe);
}