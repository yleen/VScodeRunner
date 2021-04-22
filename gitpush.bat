@echo off
msg=":pencil:day ex"
F：
cd F:\PrCode\C
git config --global credential.helper store
git add .
git commit -m msg
git push