#include "PlatformHelper.h"
#include "helper.h"

std::string OpenFileDialog()
{
#ifdef __unix__
	std::vector<std::string> data;
	char buffer[1024];
	
	FILE *b = popen("kdialog --multiple --getopenfilename /home/tim/Music", "r");
	while (fgets(buffer, 1024, b) != NULL)
	{
		data.push_back(buffer);
	}
	pclose(b);
	return trim(data[0]);
#endif
}