# Gamecube Memory Manager / GCMM (Under GPL License)

GameCube/Wii Memory Manager is an Application to backup Nintendo GameCube savegames.

Gcmm is a project started by dsbomb and justb, which is based on Askot's modification to add SD support to the mcbackup libogc example.

Suloku has updated the code to newest libraries to port it to the Wii system, and what I find more important: restoring savegames now works properly.

EnterpriseFreak updated the Code very well and added Support for the Great sd2sp2 Adpater. Also he added the "Restart Into" Option. Please checkout his github: https://github.com/EnterpriseFreak-v2

## Features

* Backups and restores savegames into GCI format
* Restores savegames in GCS/SAV format
* Deletes savegames from memory card
* Backups memory card raw images in .raw format
* Restores memory card raw images from RAW/GCP/MCI format
* Format the memory card
* Wiimote and GameCube controller support
* Power button support
* Front SD and FAT32 USB device (Wii) and sd2sp2/SDGecko (Gamecube) support
* "Restart Into" Option (Gamecube): Restarts the Gamecube or booting directly into a autoexec.dol if one is located on the SD Card 
* Shows savegame information, alongside animated Icon and Banner!
* A (somewhat) nice UI
* Open Source!

## TO DO

* Add hotswapping or warmswapping (memory cards can be swapped, SD Gecko/SD/USB can't be swapped)
* New Background / alternativ Dark Mode Background

## ABOUT SAVEGAMES AND RAW IMAGES

        Raw Images
--------------------------

A raw image is a 1:1 copy of the memory card. It can only be restored to the card it was made from.
Note that unofficial cards share the same Flash ID, which allows restoring raw images between unofficial cards (as long as they have the same size).

These limitations can be solved with Raw Tools: http://code.google.com/p/gcmm/wiki/Raw_Tools

For example:
You can grab a 59 block card raw image from an unofficial card and modify it so you can restore it to your 1019 blocks official card, mantaining the serial number of the card so your protected savegames still work.

note: as of GCMM 1.3 protected savegames can be restored to any card and they will work (thanks to Ralf!)


    Protected Savegames
--------------------------

This is just for information, as since GCMM 1.3 even serial protected savegames can be restored to any memory card.

There are two kinds of protected savegames:

* Permision protected savegames: this savegames can't be moved/copied from the Gamecube/Wii memory card manager. These saves can be backed up and restored without problems by GCMM

* Serial protected savegames: this savegames can't be moved/copied from the Gamecube/Wii memory card manager and will only work in the card they were backupped from. This protected savegames rely on the serial number that is given to the memory card when it is formated. That's why they won't work in other cards and why they won't work on the same card if that has been formatted.

Restoring a raw image to a diferent card won't work, it has to be the same card (it will work even if the card was formatted). Please note that all unofficial cards share the same Flash ID (which is different from the serial number), allowing raw image restoring between unofficial cards (as long as they are the same size).


    Other savegame formats
----------------------------
There are computer programs that can transform other savegame formats into GCI (currently GCMM supports SAV and GCS restoring).

RAW/GCP format is a raw image of the memory card with all its contents.

MCI format (createad by softdev's sdmc) is a raw image of the card, preceded by a 64 byte header.

## CONSIDERATIONS

Users:
* If you extract a device (USB, internal SD, USB gecko), it won't work againt. If you did so, reboot the GCMM. On the contrary
* Memory cards can be extracted/inserted at will at the main menu screen. It is not recommended to change the card in any other screen.
* Dolphin (wii/gc computer emulator) has a nice memory card manager, check it out!

About usb devices:
* Two of my usb devices won't work with GCMM, but those same devices make The Homebrew Channel crash. If you have problems try another usb device or an SD card.

Developers:

* LibOGC card functions works with time functions that use Epoch (seconds since jan 1, 1970) as reference, while GameCube works with seconds since jan 1, 2000). The difference is 946684800 seconds
* GCMM now uses libogc 1.8.11 git (2012-07-25) card.c, card.h and system.h with tueidj's patches for proper memory card unlocking. It would be wise to update those files in GCMM if changes are made to libogc concerning other functions. Note that even if libogc asumes the changes, as GCMM now uses some static functions from libogc, it needs card.c and card.h, but if libogc updates the sramex structure (system.h) and fixes the checksums in card.c, system.h will no longer be needed.
* Very good sources of documentation are libogc and dolphin's source code.
* Card_Init() shall be called only once. Any subsequent call will be pointless; to change the company and gamecode one should use Card_setgamecode() and Card_setcompany libogc functions.

## SETUP & INSTALLATION

Wii: Copy the boot.dol on your SD Card in apps/gcmm
     - or just copy the Wii-Ready Folder on your SD Card.
				
Gamecube: Just place the gcmm_sp2_GC.dol file on your sd2sp2/GeckoSD Adapter
				
    Wii
----------
On the Wii, the savegames will be read from and written to the front SD slot or FAT32 USB device.
The user will be prompted at startup for which device to use.
If the selected device isn't available, GCMM will try to use the other device (i.e: user selects usb device but there's none connected, so GCMM will try to use the internal SD).
Memory card can be in either slot.


  Gamecube
------------
On the GameCube you will need a sd2sp2/Gecko SD adapter. You can than choose where the MCBACKUP Folder is
Y: for sd2sp2
A/B: Where the GeckoSD is inserted

than you can choose where the Memory Card is inserted

------------------------------
Loading / Running the app:
------------------------------

Wii - Via Homebrew Channel:
--------------------
The most popular method of running homebrew on the Wii is through the Homebrew Channel. If you already have the channel installed, just copy over the apps folder included in the archive into the root of your SD card.

If you haven't installed the Homebrew Channel yet, read about how to here:
http://hbc.hackmii.com/

Gamecube:
---------
You can load gcmm via sdload and an SD card (sd2sp2 or GeckoSD), or by streaming 
it to your Gamecube, or by booting a bootable DVD with gcmm on it. 
This document doesn't cover how to do any of that. A good source for information on these topics is at http://www.gc-forever.com/wiki/index.php?title=Booting_Homebrew


## CONTROLS

They are shown at the screen.

Raw mode controls: hold L (gamecube pad) or B (wiimote) then press the corresponding button
* Raw Backup Mode:  GC_pad L+Y , Wiimote B+Minus
* Raw Restore Mode: GC_pad L+X , Wiimote B+Plus
* Format Card Mode: GC_pad L+Z , Wiimote B+2

## COMPILING
Currently gcmm uses:

* devkitpro: https://devkitpro.org/wiki/Getting_Started (links to the installer can be found in the setup section)
* devkitppc: Can be installed using the devkitPro for Windows installer or `(dkp-)pacman -S devkitPPC`
* libogc: Can be installed using the devkitPro for Windows installer or `(dkp-)pacman -S libogc`
* zlib-1.2.5-ppc: https://wii.leseratte10.de/devkitPro/portlibs/zlib-1.2.5-ppc.tar.bz2 or `(dkp-)pacman -S ppc-zlib`
* ppc-freelib-2.9.1: https://wii.leseratte10.de/devkitPro/portlibs/ppc-freetype-2.9.1-2-any.pkg.tar.xz or `(dkp-)pacman -S ppc-freetype`
* libfat-ogc-1.1.5-1: https://wii.leseratte10.de/devkitPro//libfat/libfat_1.1.5%20(2020-04-18)/libfat-ogc-1.1.5-1-any.pkg.tar.xz or `(dkp-)pacman -S libfat`
* for Wii you need devkitARM: Can be installed using the devkitPro for Windows installer or `(dkp-)pacman -S devkitARM`
* If you are using '(dkp-)pacman', you can install some dependencies with `(dkp-)pacman -S gamecube-dev` or `(dkp-)pacman -S wii-dev`

## CREDITS

* SoftDev for his contributions to the GC/WII scene
* Costis for helping with some doubts, he's allways there
* Masken for his code on raw data reading/writing
* Justb & dsbomb for originally creating gcmm
* CowTRobo & Samsom for very useful old sources
* Tantric for pointing out that official memory cards won't work on wii mode, which encouraged me to continue gcmm as all my previous efforts where in vane due to using an official card for the testing.
* tueidj, for his patches and very useful information and support. Official memory cards work due to his work.
* dronesplitter for banner and icon implementation
* PlabloACZ and Picachu025 for updating the source.
* Nano(Excelsiior), for inspiring me to finally working again on GCMM
* bm123456 and themanuel for beta testing and support
* suloku for his ongoing work
* EnterpriseFreak for adding sd2sp2 Support and "Restart Into" Option (autoexec or restart the Gamecube) - check out his github: https://github.com/EnterpriseFreak-v2
* Special thanks to Leseratte for hosting older version of the required libarys so that we can still compile homebrew without having to change huge parts of the code. Great website - check it out: https://wii.leseratte10.de/
