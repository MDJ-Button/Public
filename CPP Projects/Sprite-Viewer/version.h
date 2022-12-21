#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "12";
	static const char MONTH[] = "06";
	static const char YEAR[] = "2021";
	static const char UBUNTU_VERSION_STYLE[] =  "21.06";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 0;
	static const long MINOR  = 8;
	static const long BUILD  = 839;
	static const long REVISION  = 4528;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 920;
	#define RC_FILEVERSION 0,8,839,4528
	#define RC_FILEVERSION_STRING "0, 8, 839, 4528\0"
	static const char FULLVERSION_STRING [] = "0.8.839.4528";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 39;
	

}
#endif //VERSION_H
