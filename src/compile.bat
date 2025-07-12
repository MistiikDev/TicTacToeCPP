@echo off
echo Compiling Project...

g++ -I../include *.cpp -o TicTacToe

IF %ERRORLEVEL% EQU 0 (
    echo Compilation successful. Running program...
    TicTacToe
) ELSE (
    echo Compilation failed. Program will not run.
    exit /b 1
)