#include <stdio.h>
#include <windows.h>
#include <steam/steam_api.h>

int WinMain(HINSTANCE hInstance,
					 HINSTANCE hPrevInstance,
					 LPSTR     lpCmdLine,
					 int       nCmdShow)
{
	bool steaminit = false;
	printf( "I am alive!  Beware.\n" );
	steaminit = SteamAPI_Init();
	if (!steaminit)
	{
		printf("Steam init failed!");
	}
	
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );

	// Start the child process. 
	if( !CreateProcess( NULL,   // No module name (use command line)
		"AnomalyLauncher.exe",		// Command line
		NULL,		   // Process handle not inheritable
		NULL,		   // Thread handle not inheritable
		FALSE,		  // Set handle inheritance to FALSE
		0,			  // No creation flags
		NULL,		   // Use parent's environment block
		NULL,		   // Use parent's starting directory 
		&si,			// Pointer to STARTUPINFO structure
		&pi )		   // Pointer to PROCESS_INFORMATION structure
	) 
	{
		printf( "CreateProcess failed (%ld).\n", GetLastError() );
		return 1;
	}

	// Wait until child process exits.
	WaitForSingleObject( pi.hProcess, INFINITE );

	// Close process and thread handles. 
	CloseHandle( pi.hProcess );
	CloseHandle( pi.hThread );
	
	if (steaminit) SteamAPI_Shutdown();
	
	return 0;
}
