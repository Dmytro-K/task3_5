#include "task3_5_funcs.h"
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	char *text, *chars;

	puts( "Enter characters:" );

	chars = Input();
	if( chars == NULL )
	{
		puts( "Something wrong" );
		return 1;
	}

	puts( "Enter text:" );

	text = Input();
	if( text == NULL )
	{
		puts( "Something wrong" );
		free( chars );
		return 1;
	}

	removeWords( text, chars );

	puts( "\nResult text:" );
	puts( text );

	free( chars );
	free( text );

	return 0;
}