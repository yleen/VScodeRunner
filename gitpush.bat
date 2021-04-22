@echo off
:BEGIN
CLS
CHOICE /T 10 /N /C:123 /D 1 /M "PICK A NUMBER (1 is default, 2 is edit commit, or 3 is close)"%1

IF ERRORLEVEL ==3 GOTO THREE
IF ERRORLEVEL ==2 GOTO TWO
IF ERRORLEVEL ==1 GOTO ONE
GOTO BEGIN

:THREE
ECHO Goodbay!
GOTO END

:TWO
set /p m=please input the commit message:

if (%m%)==() (
    echo DO NOT PUSH NULL!!!
    goto TWO
) else (
    goto GITPUSH
)
GOTO BEGIN

:ONE
set m=":pencil: day ex"
GOTO GITPUSH

:GITPUSH
F：
cd F:\PrCode\C
git config --global credential.helper store
git add .
git commit -m %m%
git push

:END