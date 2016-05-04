del log_file.txt
del a.exe
set "path=D:\ProgramFiles\MinGW\bin"
g++ *.cpp -std=c++11 > log_file.txt 2>&1
cls
start "Macierz" /B /W a.exe
PAUSE
del a.exe
RD Debug /Q /S