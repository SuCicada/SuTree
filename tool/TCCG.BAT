@echo off
tcc -c %1
tlink c0s.obj %1,%1,,cs.lib maths.lib GRAPHICS.LIB 
