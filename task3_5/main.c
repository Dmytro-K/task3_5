#include "task3_5_funcs.h"
#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	char *text, *chars;
	//bool k;
	//size_t i, len;

	puts( "Enter characters:" );

	chars = CheckedInput( IsAlnum );
	if( chars == NULL )
	{
		return 1;
	}

	/*do
	{
		chars = Input();
		if( chars == NULL ) {
			puts( "Something wrong" );
			return 1;
		}
		len = StrLen( chars );
		for( i = 0; i < len; i++ )
		{
			if( IsAlpha( chars[i] ) == false ) {
				k = true;
				puts( "Wrong input, try again" );
			}
		}
	} while( k );*/

	puts( "Enter text:" );

	text = CheckedInput( NULL );
	if( text == NULL )
	{
		return 1;
	}
	/*do
	{
		text = Input();
		if( text == NULL )
		{
			puts( "Something wrong" );
			free( chars );
			return 1;
		}

		len = StrLen( chars );
		for( i = 0; i < len; i++ )
		{
			if( IsAlpha( chars[i] ) == false )
			{
				k = true;
				puts( "Wrong input, try again" );
			}
		}
	} while( k );*/

	RemoveWords( text, chars );

	puts( "\nResult text:" );
	puts( text );

	free( chars );
	free( text );

	return 0;
}