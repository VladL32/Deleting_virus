@echo off
echo Extracting archive...
"%~dp0\program.exe" && (
    echo Program executed successfully.
    echo Press Enter to exit...
    pause > nul
)