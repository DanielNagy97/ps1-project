# ps1-project

A projekt a PSYQ-SDK-val készül. Az SDk elérhetősége: http://www.psxdev.net/downloads.html

Run-Time Library Reference: https://psx.arthus.net/sdk/Psy-Q/DOCS/Devrefs/Libref.pdf

## Projekt elindítása

## Előkészületek:
A fejlesztés ANSI C nyelven és Windows XP virtulis gépen történik (mivel az SDKban található programok (és a 16 bites DOS-os toolok) nem kompatibilisek újabb windows verziókkal)

1. Az SDK-t a következő helyre célszerű áthelyezni:
```text
C:\psyq
```
2. `regedit`-ben be kell importálni a `docs/pspath.reg` fájlt, amely tartalmazza a szükséges környezeti változókat. (Újraindítás szükséges).


Problémák linux alatt:
- A `wine32`-vel a ccpsx fordító például elindul, de az exe előállításához szükséges cpe2x már nem.
- A ccpsx által előállított .cpe állományt egyes emulátorok képesek futtatni, de a kontrollerek hozzáadása után a projekt ilyen formában már nem lesz futtatható.
TODO: Linux alatti fejlesztés beállítása. (akár DOSBOX segítségével).


## Build:
A projektet a `compile.bat` futtatásával lehet fordítani. (A `cpe2x` a lefordított .cpe fájlból futtatható EXE-t állít elő, amelyet a PSX emulátorok képesek betölteni.) Az EXE a `./bin` jegyzékben lesz elérhető.
> TODO: makefile használata (jelenleg a `psymake` a makefile-t nem tudja kezelni)


## Futtatás:
Az elkészült EXE PSX emulátorokkal futtatható (ePSXe, pcsxr).
Példa az EXE futtatására `pcsxr` emulátorral linux alatt:

```shell
pcsxr -nogui -runcd bin/MAIN.EXE
```


## ISO generálása:
A lemezképfájl CD-re írható és disk-swap trükkel, vagy chippelt PS1-el futtatható. (illetve emulátorokban is indítható).

Szükséges tool-ok:
- bin\OtherTools\buildcd\BUILDCD (a reg file a PATH-hoz rendeli)
- PSXLICENSE (http://www.psxdev.net/forum/viewtopic.php?t=704)
- STRIPISO (http://www.psxdev.net/forum/viewtopic.php?f=60&t=997) - az SDK-hoz mellékelt valamiért nem működik...

A cdrom jegyzékben található bat file legenerálja az ISO file-t és licenszeli is azt! Az elkészült ISO a `cdrom/build` jegyzékben lesz elérhető.
```shell
build_cd.bat
```

