#include "globals.h"

cSettings::cSettings()
{
	standard();
}

cSettings::~cSettings()
{

}

// Public functions
bool cSettings::load()
{
	standard();

	if( !valid_file( FILENAME ) )
	{
		pLog->write("No settings found \n");
		return false;
	}

	ifstream ifs( FILENAME, ios::in );

	if( !ifs )
	{
		pLog->write("Couldn't open preferences file : %s \n", FILENAME);
		return false;
	}
	else
	{
		char contents[500];

		for( unsigned int i = 0; ifs.getline( contents, sizeof( contents ) ); i++ )
		{
			parse( contents, i );
		}

		ifs.close();
	}

	return true;
}

void cSettings::save()
{
	ofstream ofs( FILENAME, ios::out | ios::trunc );

	char row[300];

	// Screen Settings
	sprintf( row, "# Screen : \n" );
	ofs.write( row, strlen( row ) );

	sprintf( row, "Fullscreen %i\n", (int)fullscreen );
	ofs.write( row, strlen( row ) );

    sprintf( row, "Screen_W %d\n", screen_w );
	ofs.write( row, strlen( row ) );

	sprintf( row, "Screen_H %d\n", screen_h );
	ofs.write( row, strlen( row ) );

	sprintf( row, "Bpp %d\n", bpp );
	ofs.write( row, strlen( row ) );

	sprintf( row, "\n" );
	ofs.write( row, strlen( row ) );


	// Keyboard Settings
	sprintf( row, "# Keyboard : \n" );
	ofs.write( row, strlen( row ) );

	sprintf( row, "Key_up %d\n", (int)up );
	ofs.write( row, strlen(row ) );

	sprintf( row, "Key_down %d\n", (int)down );
	ofs.write( row, strlen( row ) );

	sprintf( row, "Key_left %d\n", (int)left );
	ofs.write( row, strlen( row ) );

	sprintf( row, "Key_right %d\n", (int)right );
	ofs.write( row, strlen( row ) );

	sprintf( row, "\n" );
	ofs.write( row, strlen( row ) );


	// Misc settings
	sprintf( row, "# Misc : \n" );
	ofs.write( row, strlen( row ) );

	sprintf( row, "Show_FPS %i\n", (int)showfps );
	ofs.write( row, strlen( row ) );

	sprintf( row, "\n" );
	ofs.write( row, strlen( row ) );

	ofs.close();
}

void cSettings::standard()
{
	fullscreen = true;

    screen_w = 800;
	screen_h = 600;

	bpp = 32;

	up = SDLK_UP;
	down = SDLK_DOWN;
	left = SDLK_LEFT;
    right = SDLK_RIGHT;

	showfps = false;
}

// Private functions
void cSettings :: parse( string command, int line )
{
	if( command.length() < 5 || command.find_first_of( '#' ) == 0 )
	{
		return;
	}


	while( command.find( '\r' ) != string::npos ) // Linux support
	{
		command.erase( command.find( '\r' ), 1 );
	}

	while( command.find( '\t' ) != string::npos ) // No Tabs
	{
		command.replace( command.find( '\t' ), 1, " " );
	}

	while( command.find_last_of( ' ' ) == command.length() - 1  ) // No Spaces at the end
	{
		command.erase( command.find_last_of( ' ' ), 1 );
	}

	string tempstr = command;
	int count = 1;

	while( tempstr.find( ' ' ) != string::npos  ) // Count Spaces
	{
		tempstr.erase( tempstr.find( ' ' ) , 1 );
		count++;
	}

	tempstr = command;

	string *parts = new string[ count + 1];

	int len;
	int i = 0;

	while( count > 0 )
	{
		len = tempstr.find_first_of( ' ' );
		parts[i] = tempstr.substr( 0, len );
		tempstr.erase( 0, len + 1 );
		i++;
		count--;
	}

	parts[i] = tempstr;

	// Apply the command
	apply( parts, i, line );

	delete []parts;
}

bool cSettings :: apply( string *parts, unsigned int count, unsigned int line )
{
	if( parts[0].compare( "Fullscreen" ) == 0 )
	{
		if( string_to_int( parts[1] ) == 0 )
		{
			fullscreen = false;
		}
		else
		{
			fullscreen = true;
		}
	}
	else if( parts[0].compare( "Screen_H" ) == 0 )
	{
		if( string_to_int( parts[1] ) < 0 || string_to_int( parts[1] ) > 1600 )
		{
			//return 0;
		}
		else
		{
			screen_h = string_to_int( parts[1] );
		}
	}
	else if( parts[0].compare( "Screen_W") == 0 )
	{
		if( string_to_int( parts[1] ) < 0 || string_to_int( parts[1] ) > 1600 )
		{
			//return 0;
		}
		else
		{
			screen_w = string_to_int( parts[1] );
		}
	}
	else if( parts[0].compare( "Bpp" ) == 0 )
	{
		if( string_to_int( parts[1] ) < 0 || string_to_int( parts[1] ) > 32 )
		{
			//return 0;
		}
		else
		{
			bpp = string_to_int( parts[1] );
		}
	}
	else if( parts[0].compare( "Key_up" ) == 0 )
	{
		if( string_to_int( parts[1] ) < 0 || string_to_int( parts[1] ) > 1000 )
		{
			//return 0;
		}
		else
		{
			up = (SDLKey)string_to_int( parts[1] );
		}
	}
	else if( parts[0].compare( "Key_down" ) == 0 )
	{
		if( string_to_int( parts[1] ) < 0 || string_to_int( parts[1] ) > 1000 )
		{
			//return 0;
		}
		else
		{
			down = (SDLKey)string_to_int( parts[1] );
		}
	}
	else if( parts[0].compare( "Key_left" ) == 0 )
	{
		if( string_to_int( parts[1] ) < 0 || string_to_int( parts[1] ) > 1000 )
		{
			//return 0;
		}
		else
		{
			left = (SDLKey)string_to_int( parts[1] );
		}
	}
	else if( parts[0].compare( "Key_right" ) == 0 )
	{
		if( string_to_int( parts[1] ) < 0 || string_to_int( parts[1] ) > 1000 )
		{
			//return 0;
		}
		else
		{
			right = (SDLKey)string_to_int( parts[1] );
		}
	}
	else if( parts[0].compare( "Show_FPS" ) == 0 )
	{
		if( string_to_int( parts[1] ) == 0 )
		{
			showfps = false;
		}
		else
		{
			showfps = true;
		}
	}
	else
	{
		pLog->write("An error acurred in the settings file on line: %i \n", line);
		pLog->write("%s is a unknown command \n", parts[1].c_str());
		return false;
	}

	return true;
}
