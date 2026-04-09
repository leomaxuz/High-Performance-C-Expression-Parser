@echo off
echo ===========================================
echo   High-Performance C++ Calculator Tests
echo ===========================================

set EXE=build\calculator.exe

if not exist %EXE% (
    echo ERROR: calculator.exe not found!
    pause
    exit /b
)

echo.
echo ==== BASIC TESTS ====
echo 2+2 | %EXE%
echo 10-3 | %EXE%
echo 4*5 | %EXE%
echo 20/4 | %EXE%

echo.
echo ==== PRIORITY TESTS ====
echo 2+3*4 | %EXE%
echo (2+3)*4 | %EXE%

echo.
echo ==== FLOAT TESTS ====
echo 2.5+1.5 | %EXE%
echo 10.2/2 | %EXE%

echo.
echo ==== UNARY TESTS ====
echo -5+3 | %EXE%
echo 2*-3 | %EXE%
echo (-2+5)*3 | %EXE%

echo.
echo ==== COMPLEX TESTS ====
echo 10+(2*3)-(4/2) | %EXE%
echo (1+2)*(3+4)*(5+6) | %EXE%

echo.
echo ==== ERROR TESTS ====
echo 5/0 | %EXE%
echo 5+*2 | %EXE%
echo ((2+3) | %EXE%

echo.
echo ===========================================
echo              TESTS FINISHED
echo ===========================================

echo.
echo Press any key to exit...
pause >nul
