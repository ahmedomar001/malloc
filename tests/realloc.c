#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../src/helper.h"

int main()
{
   int *ptr = (int *)malloc(sizeof(int)*2);
   int i;
   int *ptr_new;

   *ptr = 10;
   *(ptr + 1) = 20;

   ptr_new = (int *)realloc(ptr, sizeof(int)*3);
   *(ptr_new + 2) = 30;

   for(i = 0; i < 3; i++)
   {
     assert( *(ptr_new + i ) == ( i + 1 ) * 10 );
   }

   sprintf(buffer, "realloc test PASSED\n");
   write(STDOUT_FILENO, buffer, strlen(buffer));

   return 0;
}
