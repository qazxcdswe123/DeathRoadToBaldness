#!/bin/bash

# Usage: 
# wget https://github.com/qazxcdswe123/DeathRoadToBaldness/raw/main/301.Server/setup_zsh.sh -O ~/.config/setup_zsh.sh

# check os type
if [[ $(uname) == "Linux" ]]; then
    os_type="linux"
elif [[ $(uname) == "Darwin" ]]; then
    os_type="macos"
else
    echo "Unknown OS type"
    exit 1
fi

# install zsh
if [[ $os_type == "linux" ]]; then
    sudo apt install zsh
fi

wget https://github.com/qazxcdswe123/DeathRoadToBaldness/raw/main/301.Server/.zshrc -O ~/.zshrc
wget https://github.com/qazxcdswe123/DeathRoadToBaldness/raw/main/301.Server/.zimrc -O ~/.zimrc

# change default shell
chsh -s $(which zsh)