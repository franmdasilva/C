#include <stdio.h>
 
extern int count; 
// extern é usado para indicar que a variável é definida fora deste arquivo, em 'principal.c'
 
void write_extern(void) {
   printf("count is %d\n", count);
}