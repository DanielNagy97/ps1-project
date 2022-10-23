# ps1-project

A projekt a PSYQ-SDK-val készül.


A projektet az SDK-hoz mellékelt `psymake`-kel lehet buildelni.
> TODO: kijavítani, mert most jelenleg nem tud 3 fájlnál többet kezelni(?) a `compile.bat`-al lehet futtatni.
```shell
psymake
```

A `cpe2x` a lefordított .cpe fájlból futtatható EXE-t állít elő, amelyet a PSX emulátorok képesek betölteni.


```shell
pcsxr -nogui -runcd bin/MAIN.EXE
```

## ISO generálása:
- bin\OtherTools\buildcd\BUILDCD (a reg file a PATH-hoz rendeli)
- PSXLICENSE (http://www.psxdev.net/forum/viewtopic.php?t=704)
- STRIPISO (http://www.psxdev.net/forum/viewtopic.php?f=60&t=997) - az SDK-hoz mellékelt valamiért nem működik...

A cdrom jegyzékben található bat file legenerálja az ISO file-t és licenszeli is azt! Az elkészült ISO a `cdrom/build` jegyzékben lesz elérhető.
```shell
build_cd.bat
```
