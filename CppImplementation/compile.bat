:: taken from http://stackoverflow.com/questions/84404/using-visual-studios-cl-from-a-normal-command-line
@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat"
"C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\cl.exe" %*
