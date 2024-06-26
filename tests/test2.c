#include <stdlib.h>
#include <stdio.h>
#include "../src/helper.h"

int main()
{

  sprintf(buffer, "Running test 2 to exercise malloc and free\n");
  write(STDOUT_FILENO, buffer, strlen(buffer));

  char * ptr = ( char * ) malloc ( 65535 );

  char * ptr_array[1024];

  int i;
  for ( i = 0; i < 1024; i++ )
  {
    ptr_array[i] = ( char * ) malloc ( 1024 ); 
    
    ptr_array[i] = ptr_array[i];
  }

  free( ptr );

  for ( i = 0; i < 1024; i++ )
  {
    if( i % 2 == 0 )
    {
      free( ptr_array[i] );
    }
  }

  ptr = ( char * ) malloc ( 65535 );
  free( ptr ); 

  return 0;
}
