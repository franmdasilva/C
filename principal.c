#include <stdio.h>
 
int count ;
extern void write_extern(); // esta funcao é definida em 'suporte.c'
 
int main() {
   count = 5;
   write_extern();

   return 0;
}