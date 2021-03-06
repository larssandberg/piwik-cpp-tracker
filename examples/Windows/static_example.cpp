// piwik_static_example.cpp : Defines the entry point for the console application.
//

#include "../../src/stdafx.h"
#include "../../src/PiwikCreator.h"
#include <tchar.h>

int _tmain(int argc, _TCHAR* argv[])
{
	IPiwikTracker* piwikTracker = createPiwikTracker(1, "http://asmorkalov.piwik.pro");
	if (!piwikTracker)
	{
		printf("error");
		return -1;
	}

	unsigned int requestId = piwikTracker->doTrackPageView(L"Game Menu");
	piwikTracker->waitForRequest(requestId);
	printf("status of request: %d\n", piwikTracker->getRequestStatus(requestId));
	printf("error: %s\n", piwikTracker->getRequestErrorString(requestId));
	printf("response: %s\n", piwikTracker->getRequestResponse(requestId));

	requestId = piwikTracker->doTrackSiteSearch(L"hello", L"something", 15);
	piwikTracker->waitForRequest(requestId);
	printf("status of request: %d\n", piwikTracker->getRequestStatus(requestId));
	printf("error: %s\n", piwikTracker->getRequestErrorString(requestId));	
	printf("response: %s\n", piwikTracker->getRequestResponse(requestId));

	requestId = piwikTracker->doTrackGoal(1, 15.5f);
	piwikTracker->waitForRequest(requestId);
	printf("status of request: %d\n", piwikTracker->getRequestStatus(requestId));
	printf("error: %s\n", piwikTracker->getRequestErrorString(requestId));	
	printf("response: %s\n", piwikTracker->getRequestResponse(requestId));

	deletePiwikTracker(piwikTracker);
	printf("ended");
	return 0;	
}

