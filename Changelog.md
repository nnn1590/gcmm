## Changelog

[What's New 1.5a - april 06, 2020 - By EnterpriseFreak & seeWood]
* Added support for sd2sp2 Adapter
* Added "Restart Into" Option
  - If it finds a autoexec.dol on the SD Card it will try to boot that
    - If it fails to boot into the autoexec.dol or it cannot find a autoexec.dol, it restarts the Gamecube
    
[What's New 1.4f - april 05, 2017 - By suloku]
* dragonbane0 made a mod of version 1.4c with folder selection and alphabetical sorting. Zephiles pointed this out and the changes have been merged with some little extra tweaks. Thanks you both!

[What's New 1.4e - february 27, 2016 - By suloku]
* Fixed bug in card.c that prevented correct backup/write of saves with same filename but different case. Bug affected Timesplitters 2, probably Timesplitters 3 too. Thanks to DakuTree for reporting and Antidote for fixing.

[What's New 1.4d - august 08, 2015 - By suloku]
* Fixed bug in card.c that prevented writing to the last block of the memory card, preventing restoring a savegame that would fill the memory card (thanks to undergroundmonorail)
* Fixed bug in card.c that prevented correct block freeing when deleting a file and only was fixed by using the memory card on official software (the wii/gamecube save manager or probably also games)
* Added libogc fix for a bug in card.c (the bug didn't affect GCMM, it was fixed in 1.4b, but I didn't change card.c)
* Changed button presses for single savegame delete to prevent unvoluntary savegame deleting

[What's New 1.4c - january 05, 2014 - By suloku]
* Disabled __sector_erase() check when raw restoring as some unofficial cards seem to have problems with it.

[What's New 1.4b - september 03, 2013 - By suloku]
* Card initialization was wrong all the way, wich lead to savegames of the same game of different region or those that shared similar filenames (Twilight Princess and WindWaker) to not work properly. Thanks to antidote.crk for noticing. (read considerations sections for more info)
* Added version display

[What's New 1.4a - october 18, 2012 - By suloku]
* Fixed SD Gecko when inserted/swapped at slot selection screen in GameCube mode.
* FLash ID display was missing a byte
* Changed some text that may confuse the user
* Made font sizes more coherent

[What's New 1.4 - october 08, 2012 - By suloku]
* Animated icon alongside several (minor) graphical improvements
* Ability to select SD Gecko slot in GameCube mode (just like Wii mode SD/USB prompt)
* Moved "Backup All" to Backup Mode (press R/1 when in Backup Mode)
* Added an analog "Restore All" in Restore Mode (overwriting is supported)
* Shows filename when prompted to overwrite (also in "Restore All")
* Savegame permisions are shown in a more explicit and user friendly way
* Shows memory card freeblocks
* Page number display in file selector
* Left and right now scroll 5 file entries at once
* Scrolling of file entries can be done holding the button (up/down/left/right)
* Added security checks to Raw Restore Mode
* Added some special characters to the font (needed for savegame comments)
* Minor code tweaks

Lots of thanks to bm123456 and themanuel for beta testing and support!

[What's New 1.3 - september 14, 2012 - By suloku]

* Shows card/image serial number in Raw Restore Mode
* F-zero and Phantasy Star Online Ep I&II and Phantasy Star Online III savegames
are patched uppon restoring so they will work on target card (by Ralf)

Lot's of thanks to Ralf at gscentral.org forums
http://board.gscentral.org/retro-hacking/53093.htm#post188949

[What's New 1.2d - september 08, 2012 - By suloku]

* Previous version couldn't raw backup if backup folder didn't exist in sd/usb
* Added (double)overwrite prompt when restoring a savefile to memory card (Nano/Excelsiior's idea)
* Updated graphics so raw mode commands are less cryptic (wii mode design based on JoostinOnline's for GCMM+)
* Use DejavuSans as font (much better readability) from GCMM+ by Nano/Excelsiior

[What's New 1.2c - september 06, 2012 - By suloku]

* Raw backups are now named with the number of blocks: insted of Backup_*timestamp*.raw now it is 0059b_*timestamp.raw, 2043b_*timestamp.raw...
* Minor code changes (just for safety)

[What's New 1.2b - september 06, 2012 - By suloku]

* Solved a potential bug, 1.2 and 1.2a seemed unaffected by it.

[What's New 1.2a - september 06, 2012 - By suloku]

* 1.2 wasn't correctly freeing memory and eventually raw backup and restore would hang the app (a 2043 block card would make it hang at the second attempt to raw backup the card)

[What's New 1.2 - september 06, 2012 - By suloku]

* Added raw backup mode (in .raw format, compatible with dolphin and devolution)
* Added RAW/GCP/MCI support for raw restore mode
* Added format mode
* Flash ID of inserted card and SD image are shown in Raw Restore Mode
* Protection against writing a raw image to the wrong card (trough Flash ID checking)
* Raw mode works with official and unofficial cards, as well as gci mode (thanks to tueidj for pointing me in the right path!)

[What's New 1.1 - august 29, 2012 - By suloku]

* Icon and banner by dronesplitter!
* Added USB-SD selection in wiimode (only at boot)
* Added card slot selection (wii mode only)
* Propper GCI backup and restore. Now GCMM uses __card_getstatusex and __card_setstatuex, which provide a more 1:1 backup/restore
* Correctly displaying savegame Date information
* Savegame information rearranged.

Accepted PlabloACZ and Picachu025 modifications, with the following changes:
* Tweaked mount function
* Filenames are no longer prefixed with a number for current sesion. Instead, savegames are suffixed with a number. When backing up a savegame if the same file exists on SD it will be prefixed with a growing number (if savegame_00.gci exists, then it will try savegame_01.gci, savegame_02.gci... and so on)
* Infinite loop can't happen when backupping a savegame as in r11 MOD 2.

[What's New r11 MOD 2 - September 11, 2011 - By Pikachu025]
* R (GC-Pad) / 1 (Wiimote) now launches a "backup all" mode, where all saves on the memory card are written to the SD card without any user prompts in the meantime.
* I came across a couple saves that had ridiculous filenames that refused to write to SD, so if the program comes across one of those, it'll now write them out as "illegal_name" instead of the actual filename.
* Filenames written to SD are now prefixed with a number, counting up from 1 for every file written during the current session. I added this since I had multiple files that resulted in the same filename.
* I also added a small check if the file was written correctly. If not, it'll retry. This probably results in an infinite loop when your SD card doesn't have enough free space, so ensure that I guess.
* I also (quite shoddily) edited the image listing all the options to add the new option, it's ugly but does its job. Feel free to fix, I don't have Photoshop or anything here.

[What's New r11 MOD - September 09, 2011 - By PabloACZ]
* SDGetFileList() function in sdsupp.c updated to reflect the changes in DevKitPPC/libogc from the last three years (diropen, dirnext and dirclose commands were replaced with opendir, readdir and closedir, respectively).
* Modified the MountCard() function in mcard.c to perform a probe on the GC Memory Card slot, to make sure it was mounted properly.
* Improved the compatibility with GCS/SAV files with the patch posted by jcwitzel in December 2009 (http://code.google.com/p/gcmm/issues/detail?id=1#c25).
* The Makefiles were modified to include the zlib in the libraries section. It seems that the latest libFreeType PPC port needs it to work.
* **Hopefully** Added compatibility with Official GameCube Memory Cards (see this: http://devkitpro.svn.sourceforge.net/viewvc/devkitpro?view=revision&revision=4049). According to a friend of mine, it works with a 256 blocks Memory Card.
* Compiled with DevKitPPC r24, libogc 1.8.8, libfat 1.0.10 and libFreetype 2.4.2.

[What's New 1.0 - December 31, 2008]
* Updated to libfat
* Added Wii support
* Fixed restore bug (yes, savegames will restore properly)
* New background
* Support for interlaced and widescreen in all regions
* Delete mode (dsbomb&justb)
* Shows the savegame information (mostly by dsbomb&justb)
* Many other fixes/modifications for the user
