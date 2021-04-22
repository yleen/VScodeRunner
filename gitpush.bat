@echo off
m=":pencil:day ex"
F：
cd F:\PrCode\C
git config --global credential.helper store
git add .
git commit -m %m
git push