#include "../../pch.h"
#include "AntiScreenCapture.h"
bool AntiScreenCapture_One(IN HWND hwdn)
{
	if (!::SetWindowDisplayAffinity(hwdn, WDA_EXCLUDEFROMCAPTURE))
	{
		return false;
	}

	return true;
	
}