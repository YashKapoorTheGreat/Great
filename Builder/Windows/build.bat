@echo off
setlocal enabledelayedexpansion

set "SRC=%cd%\Great\Src"
set "OBJ=%cd%\Great\BuildInt"
set "BUILD=%cd%\Great\Build\Windows"
set OUT="%BUILD%\Great.exe"

if not exist "%BUILD%" (
    mkdir "%BUILD%"
)

set "CC=gcc"
set FLAGS=-g -I"%SRC%\include" -Wall -Werror

set "objFiles="

for /R "%SRC%" %%f in (*.c) do (
    set cfile="%%f"
    set var1=%%~nf.o
    set var2=%%~dpf
    set objfile=!var1:%SRC%=%OBJ%!
    set objFolder=!var2:%SRC%=%OBJ%!
    set objFolder2="!var2:%SRC%=%OBJ%!"
    set obj="!objFolder!!objfile!"

    set objFiles=!objFiles! !obj!

    if not exist !objFolder2! (
        mkdir !objFolder2!
    )
    echo Compiling !obj!
    %CC% %FLAGS% -c !cfile! -o !obj!
    IF %ERRORLEVEL% NEQ 0 (
        echo Error:%ERRORLEVEL%
        exit
    )
)

%CC% %FLAGS% -o %OUT% !objFiles!
IF %ERRORLEVEL% NEQ 0 (
    echo Error:%ERRORLEVEL%
    exit
)
echo "Compilation Success"
