/***********************************************
 * tts cmd client
 * made by voiceware, modified by elijah hamilton. 7/2/2021
 ***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "vt_eng.h"

int main(int argc, char *argv[])
{
	if(argc == 1) printf("Usage: cmdclient.exe \"Text\" output.pcm speed\n"), printf("Example: cmdclient.exe \"Input Text Here\" output.pcm 100\n"), exit (0);
	int infoval;
	int nFramesize;
	char *framebuf;
	int frameflag, rc;
	int nThreadID = 0;
	FILE *fp;
	int speed = atoi(argv[3]);

	/****************************************/
	/* TTS Initialize                            */
	/* call VT_LOADTTS_ENG ()                  */
	/****************************************/
	if (VT_GetTTSInfo_ENG(VT_LOAD_SUCCESS_CODE, NULL, &infoval, sizeof(int)) != VT_INFO_SUCCESS) printf("VT_GetTTSInfo_ENG Fail\n"), exit (1);
	if (VT_LOADTTS_ENG(NULL, -1, NULL, NULL) != infoval) printf("VT_LOADTTS_ENG Fail\n"), exit (1); else printf("VT_LOADTTS_ENG Success\n");
	VT_SetPitchSpeedVolumePause_ENG(100, speed, 200, 925, 1);

	/****************************************/
	/* TTS File API                         */
	/* call VT_TextToFile_ENG ()            */
	/****************************************/
	printf("Input text: %s\n", argv[1]);
	printf("Output audio: %s\n", argv[2]);
	printf("Output audio speed: %d\n", speed);
	if (VT_TextToFile_ENG (VT_FILE_API_FMT_S16PCM , argv[1], argv[2], -1, -1, -1, -1, -1, -1, -1) != VT_FILE_API_SUCCESS)
		VT_UNLOADTTS_ENG (-1), printf("VT_TextToFile_ENG Fail\n"), exit (1); else printf("VT_TextToFile_ENG Success\n");

	/****************************************/
	/* TTS Exit                                   */
	/* call VT_UNLOADTTS_ENG ()                */
	/****************************************/
	VT_UNLOADTTS_ENG (-1);
	exit (0);
}
