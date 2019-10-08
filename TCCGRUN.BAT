@echo off
tool\tcc -c %1
tool\tlink tool\c0s.obj tool\EGAVGA.OBJ %1 ,%1,,tool\cs.lib tool\maths.lib tool\GRAPHICS.LIB tool\EMU.LIB

if exist %1.exe echo ----------------------------------------
if exist %1.exe echo=
if exist %1.exe %1.exe

if exist %1.map del %1.map
if exist %1.obj del %1.obj
if exist %1.exe del %1.exe

echo=
echo=
:over
