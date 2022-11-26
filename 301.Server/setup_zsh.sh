#!/bin/bash

# Usage: 
# wget https://github.com/qazxcdswe123/DeathRoadToBaldness/raw/main/301.Server/setup_zsh.sh -O ~/.config/setup_zsh.sh && chmod +x ~/.config/setup_zsh.sh && ~/.config/setup_zsh.sh

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
    apt update && apt install zsh -y
fi

wget https://github.com/qazxcdswe123/DeathRoadToBaldness/raw/main/301.Server/.zshrc -O ~/.zshrc
wget https://github.com/qazxcdswe123/DeathRoadToBaldness/raw/main/301.Server/.zimrc -O ~/.zimrc
wget https://github.com/qazxcdswe123/DeathRoadToBaldness/raw/main/301.Server/.p10k.zsh -O ~/.p10k.zsh

# change default shell
chsh -s $(which zsh)
zsh