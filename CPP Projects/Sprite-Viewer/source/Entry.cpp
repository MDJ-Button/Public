#include "NewThread.h"

bool MyThread::Entry2()
{
	while(1)
    {
		std::cout << "\n1";
	};
	return true;
}
