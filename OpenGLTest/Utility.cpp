#include "Utility.h"

std::string LoadFile( std::string fileName )
{
	std::ifstream file;
	std::string lineBuffer;
	std::stringstream scriptBuffer;
	file.open( fileName.c_str() );
	while( file.eof() == false && file.good() == true ) {
		std::getline( file, lineBuffer );
		scriptBuffer << lineBuffer << "\n";
	}
	return scriptBuffer.str();
}
