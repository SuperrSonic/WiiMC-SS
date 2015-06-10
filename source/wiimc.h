/****************************************************************************
 * WiiMC
 * Tantric 2009-2012
 *
 * wiimc.h
 ***************************************************************************/

#ifndef _WIIMC_H_
#define _WIIMC_H_

#include "utils/FreeTypeGX.h"
#include "network.h"

#define APPNAME			"WiiMC"
#define APPVERSION		"1.3.5"
#define APPFOLDER		"wiimc"

enum {
	DEVICE_SD,
	DEVICE_USB,
	DEVICE_DVD,
	DEVICE_SMB,
	DEVICE_FTP,
	DEVICE_INTERNET
};

#define NOTSILENT 0
#define SILENT 1

bool SupportedIOS(u32 ios);
bool SaneIOS(u32 ios);
void SetSleepTimer();
void ResetSleepTimer();
void CheckSleepTimer();
bool InitMPlayer();
void LoadMPlayerFile();
void ResumeMPlayerFile();
void StopMPlayerFile();
void ActivateExitThread();

extern bool ExitRequested;
extern bool ShutdownRequested;
extern FreeTypeGX *fontSystem[];
extern bool subtitleFontFound;
extern char loadedFile[];
extern char loadedDevice[];
extern char loadedFileDisplay[];
extern char appPath[];

extern "C" {
	
bool FindNextFile(bool load);

extern int controlledbygui;
int mplayer_main(); // in mplayer.c

void wiiLoadFile(char *filename, char *partitionlabel);
void wiiGotoGui();
void wiiPause();
bool wiiIsPaused();
bool wiiIsPlaying();
void wiiMute();
void wiiSetSeekBackward(int sec);
void wiiSetSeekForward(int sec);
void wiiSeekPos(int sec);
void wiiFastForward();
void wiiRewind();
double wiiGetTimeLength();
double wiiGetTimePos();
void wiiGetTimeDisplay(char *buf);
void wiiSetDVDDevice(char *dev);
bool wiiAudioOnly();
char * wiiGetMetaTitle();
char * wiiGetMetaArtist();
char * wiiGetMetaAlbum();
char * wiiGetMetaYear();
void wiiDVDNav(int cmd);
void wiiUpdatePointer(int x, int y);
bool wiiPlayingDVD();
bool wiiInDVDMenu();
void wiiSetCacheFill(int fill);
void wiiSetOnlineCacheFill(int fill);
void wiiSetAutoResume(int enable);
void wiiSetVolume(int vol);
void wiiSetProperty(int cmd, float val);
void wiiSetCodepage(char *cp);
void wiiSetAudioLanguage(char *lang);
void wiiSetSubtitleLanguage(char *lang);
void wiiSetSubtitleColor(char *color);
void wiiSetSubtitleSize(float size);
bool wiiFindRestorePoint(char *filename, char *partitionlabel);
void wiiLoadRestorePoints(char *buffer, int size);
char * wiiSaveRestorePoints(char *path);

}

#endif
