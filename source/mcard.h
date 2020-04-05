/****************************************************************************
* mcard support prototypes
****************************************************************************/

// Warnung: Billiger Hack weil ich keinen Bock hab jeden call zu fixen. Ich Übernehme keine Haftung für Cancer.
#define stricmp strcmp
#ifndef _MCARDSUP_
#define _MCARDSUP_

void GCIMakeHeader();
void ExtractGCIHeader();
int MountCard(int cslot);
u16 FreeBlocks(s32 chn);
int CardGetDirectory (int slot);
void CardListFiles ();
int CardReadFileHeader (int slot, int id);
int CardReadFile (int slot, int id);
int CardWriteFile (int slot);
void MC_DeleteMode(int slot);
void MC_FormatMode(s32 slot);
void WaitCardError(char *src, int error);
static int OFFSET = 0;
#endif
