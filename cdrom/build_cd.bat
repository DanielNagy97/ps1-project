@ECHO OFF

BUILDCD -l -iGAME.IMG tools\GAME.CTI
tools\STRIPISO S 2352 GAME.IMG GAME.ISO
tools\PSXLICENSE /eu /i GAME.ISO

if not exist "build" mkdir build

move GAME.ISO build

DEL *.IMG
DEL *.TOC