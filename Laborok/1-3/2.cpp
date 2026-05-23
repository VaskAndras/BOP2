#include <stdio.h>
#include <stdlib.h>
// The compare function compares two values received as parameters.
// We have to specify this function with general parameter types, since
// being passed to the qsort, such approach insures the type safety.
// In other words, qsort does not care about types of elements being sorted.
int compare(const void* a, const void *b)
{
// Returning value: <0, if a<b;
// 0, if a=b;
 // >0, if a>b.
double* da=(double*)a, *db=(double*)b;
if(*da<*db)return -1;
else if (*da==*db) return 0;
else return 1;
}

int main()
{
int hossz;
printf("Please enter a number of numbers zou want to sort:");

scanf("%d", &hossz);

printf("\n");
double *d= (double*) malloc(hossz*sizeof(double));

for(int i=0;i<hossz;i++)
{
printf("Enter a number:");
scanf("%lf", &d[i]);
}
qsort(d,hossz,sizeof(double), compare);
for(int i=0;i<hossz;i++)
{
printf("%lf ",d[i]);
}
free(d);
return 0;
}