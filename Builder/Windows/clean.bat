@echo off

set OBJ="%cd%\Great\BuildInt"
set BUILD="%cd%\Great\Build\"

rd /s /q %OBJ%
rd /s /q %BUILD%

mkdir %OBJ%
mkdir %BUILD%