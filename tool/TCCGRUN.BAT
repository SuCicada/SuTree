@echo off
tcc -c %1
tlink c0s.obj %1,%1,,cs.lib maths.lib GRAPHICS.LIB 

if exist %1.exe echo ----------------------------------------
if exist %1.exe echo=
if exist %1.exe %1.exe

if exist %1.obj del %1.obj 
if exist %1.exe del %1.exe

echo=
echo=
:over
