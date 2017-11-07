#!/bin/bash
set -exv

mkdir $HOME/cocos

wget -P $HOME/cocos http://cdn.cocos2d-x.org/cocos2d-x-3.15.1.zip

unzip $HOME/cocos/cocos2d-x-3.15.1.zip -d $HOME/cocos
rm -f $HOME/cocos/cocos2d-x-3.15.1.zip


sudo cp $HOME/cocos/coc*/extern*/linux-specific/fmod/prebuilt/64-bit/libfmod.so /usr/lib
sudo cp $HOME/cocos/coc*/extern*/linux-specific/fmod/prebuilt/64-bit/libfmodL.so /usr/lib
ln -s libfmod.so libfmod.so.6

cd $HOME/cocos/cocos*/build
echo Installing deps
./install-deps-linux.sh

cd $HOME/cocos/cocos*/
echo starting setup
./setup.py -q
source ~/.bashrc

echo Testing
cd $HOME/cocos/cocos*/build
mkdir linux-build
cd linux-build
cmake ../..

