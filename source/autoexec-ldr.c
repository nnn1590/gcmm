/* This file is heavly based on autoexec-ldr Release v1.0.0-rewrite.
https://github.com/EnterpriseFreak-v2/autoexec-ldr/releases/tag/v1.00-rewrite
*/

#include <gccore.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct _dolheader {
	u32 text_pos[7];
	u32 data_pos[11];
	u32 text_start[7];
	u32 data_start[11];
	u32 text_size[7];
	u32 data_size[11];
	u32 bss_start;
	u32 bss_size;
	u32 entry_point;
} dolheader;

typedef void (*entrypoint) (void);

int bootAutoexec(int argc, char **argv)
{
    FILE* targetDol = fopen("fat:/autoexec.dol", "rb");
    u32 dolSize = 0;
    char* dolBuf;
    u8 i;

    if (!targetDol) {
        return 1;
    }

    fseek(targetDol, 0, SEEK_END);
    dolSize = ftell(targetDol);
    fseek(targetDol, 0, SEEK_SET);

    dolBuf = (char*) malloc(sizeof(char)*dolSize);
    if (dolBuf == NULL) {
        return 1;
    }

    fread(dolBuf, 1, dolSize, targetDol);
    fclose(targetDol);

    u8* buf;
    u32 size = 0;
    dolheader *dol = (dolheader*)dolBuf;

    for (i = 0; i < 11; i++) {
        if (i < 7) {
            if ((!dol -> text_size[i]) || (dol -> text_start[i] < 0x100)) {
                continue;
            }

            size = dol -> text_size[i];
            buf = (u8*)dol -> text_start[i];
            memcpy(buf, dolBuf + dol -> text_pos[i], size);
            DCFlushRange(buf, size);
            ICInvalidateRange(buf, size);
        }

        if ((!dol -> data_size[i]) || (dol -> data_start[i] < 0x100)) {
                continue;
        }

        size = dol -> data_size[i];
        buf = (u8*)dol -> data_start[i];
        memcpy(buf, dolBuf + dol -> data_pos[i], size);
        DCFlushRange(buf, size);
        ICInvalidateRange(buf, size);
    }

    free(dolBuf);

    SYS_ResetSystem(SYS_SHUTDOWN, 0, 0);
    entrypoint entry = (entrypoint) dol -> entry_point;
    entry();

    return 1;
}
