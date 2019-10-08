@echo off
tool\tcc -c %1
tool\tlink tool\c0s.obj tool\EGAVGA.OBJ %1 ,%1,,tool\cs.lib tool\maths.lib tool\GRAPHICS.LIB tool\EMU.LIB
