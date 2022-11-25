#!/bin/bash

mkdir -p /root/.ssh
chmod 0700 /root/.ssh

# check if wget or curl exsit
if [ -x "$(command -v wget)" ]; then
    wget https://github.com/qazxcdswe123.keys -O /root/.ssh/authorized_keys
elif [ -x "$(command -v curl)" ]; then
    curl https://github.com/qazxcdswe123.keys -O /root/.ssh/authorized_keys
else
    echo "Please install wget or curl"
    exit 1
fi

# check if authorized_keys exist and not empty
if [ -s /root/.ssh/authorized_keys ]; then
    chmod 0600 /root/.ssh/authorized_keys
    echo "ssh key based auth is done"
else
    echo "ssh key based auth is failed"
fi

# disable password login and change ssh port
if [ -x "$(command -v sed)" ]; then
    sed -i 's/#PasswordAuthentication yes/PasswordAuthentication no/g' /etc/ssh/sshd_config
    sed -i 's/#Port 22/Port 2222/g' /etc/ssh/sshd_config
    systemctl restart sshd
else
    echo "Please install sed"
    exit 1
fi