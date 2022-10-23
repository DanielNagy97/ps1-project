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
