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

cat ~/.bashrc
# Add environment variable COCOS_CONSOLE_ROOT for cocos2d-x
export COCOS_CONSOLE_ROOT="$HOME/cocos/cocos2d-x-3.15.1/tools/cocos2d-console/bin"
export PATH=$COCOS_CONSOLE_ROOT:$PATH

# Add environment variable COCOS_X_ROOT for cocos2d-x
export COCOS_X_ROOT="$HOME/cocos"
export PATH=$COCOS_X_ROOT:$PATH

# Add environment variable COCOS_TEMPLATES_ROOT for cocos2d-x
export COCOS_TEMPLATES_ROOT="$HOME/cocos/cocos2d-x-3.15.1/templates"
export PATH=$COCOS_TEMPLATES_ROOT:$PATH

cat ~/.bashrc

echo Testing
cd $HOME/cocos/cocos*/build
mkdir linux-build
cd linux-build
cmake ../..



