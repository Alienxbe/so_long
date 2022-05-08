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
fi

# Libft installation
if [ ! -d "Libft" ]
then
	git clone https://github.com/Alienxbe/Libft Libft
else
	git -C Libft pull
fi
