#include <stdio.h>
 
extern int count; // esta variável é definida em 'principal.c'
 
void write_extern(void) {
   printf("count is %d\n", count);
}