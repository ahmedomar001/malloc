#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../src/helper.h"

int main()
{
  char * ptr1 = ( char * ) malloc ( 1000 );
  char * buf1 = ( char * ) malloc ( 1 );
  char * ptr6= ( char * ) malloc ( 10 );
  char * buf2 = ( char * ) malloc ( 1 );
  char * ptr2 = ( char * ) malloc ( 6000 );
  char * buf3 = ( char * ) malloc ( 1 );
  char * ptr7= ( char * ) malloc ( 10 );
  char * buf4 = ( char * ) malloc ( 1 );
  char * ptr3 = ( char * ) malloc ( 1000 );

  sprintf(buffer, "First fit should pick this one: %p\n", ptr1);
  write(STDOUT_FILENO, buffer, strlen(buffer));
  sprintf(buffer, "Next fit should pick this one: %p\n", ptr3);
  write(STDOUT_FILENO, buffer, strlen(buffer));

  free( ptr1 ); 
  free( ptr2 ); 
  free( ptr3 ); 

  char * ptr5 = ( char * ) malloc ( 6000 );

  ptr5 = ptr5;
  ptr7 = ptr7;
  ptr6 = ptr6;
  buf1 = buf1;
  buf2 = buf2;
  buf3 = buf3;
  buf4 = buf4;

  char * ptr4 = ( char * ) malloc ( 1000 );
  sprintf(buffer, "Chosen address: %p\n", ptr4);
  write(STDOUT_FILENO, buffer, strlen(buffer));

  show_heap();

  return 0;
}

