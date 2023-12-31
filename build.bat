@echo off
call "C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat"  -arch=x64 -no_logo

set CommonCompilerFlags=-Od -nologo -FC -WX -W4 -wd4201 -wd4100 -wd4505 -wd4189 -wd4457 -wd4456 -wd4819 -Wall -MTd -Oi -GR- -Gm- -EHa- -Zi /std:c11
set CommonLinkerFlags=

set SourceDir=.\..\src\
set Target=colt

del *.pdb > NUL 2> NUL
cd build

REM Optimization switches: /O2 /Oi /fp:fast
REM TODO: make this less horrendous
cl %CommonCompilerFlags% %SourceDir%main.c %SourceDir%colt.c /Fe:%Target% /link %CommonLinkerFlags%

.\%Target%.exe
cd ..\