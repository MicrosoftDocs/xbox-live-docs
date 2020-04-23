@echo off
set HOMEPATH=%cd%
set ROOTPATH=%HOMEPATH%
set OUTPUTPATH=%HOMEPATH%
cd ../tools
TocBuilder.exe -r="%ROOTPATH%" -o="%OUTPUTPATH%"
cd %HOMEPATH%