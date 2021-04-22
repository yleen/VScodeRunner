@echo off
set /p m=please enter the commit message:

if (%m%)==() (
    echo OK
) else (
    echo ERROR
)
goto END
F：
cd F:\PrCode\C
git config --global credential.helper store
git add .
git commit -m %m%
git push
:END