@echo off
F：
cd F:\PrCode\C
git config --global credential.helper store
git add .
git commit -m %1
git push