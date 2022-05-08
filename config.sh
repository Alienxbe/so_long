#!/bin/sh

OS=$(uname)

# Mlx installation
if [ $OS == "Linux" ]
then
	if [! -f "/usr/local/lib/libmlx.a"]
	then
		sudo apt update
		sudo apt install gcc make xorg libxext-dev libbsd-dev
		git clone https://github.com/42Paris/minilibx-linux.git ~/.mlx
		Make -C ~/.mlx
		cp -vr ~/.mlx/libmlx_Linux /usr/local/lib
		cp -vr ~/.mlx/mlx.h /usr/local/include
		cp -vr ~/.mlx/man/man3 /usr/local/man/
	fi
elif [ $OS == "Darwin" ]
then
	echo "You're at school it's already installed"
fi
