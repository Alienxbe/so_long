#!/bin/sh

# Libft installation
if [ ! -d "Libft" ]
then
	git clone https://github.com/Alienxbe/Libft Libft
else
	git -C Libft pull
fi
