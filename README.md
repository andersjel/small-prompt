Readme
======

This program prints the current working dir to the standard output,
shortening it nicely if it is too long. It can be used to build a nice
bash prompt.

Installation
------------

These instructions apply to Debian based systems.

If you need `g++` run `sudo apt-get install g++`. Compile the program
by executing

    g++ small-prompt.cpp -o small-prompt

To use this as your bash prompt, put it somewhere in your PATH (for
instance, create `~/bin/` and put it there). Now run

    echo PS1="$(small-prompt 30)\$ " >> ~/.bashrc

If you want a color version, instead run

    echo PS1="\[\033[0;31m\]\$(small-prompt 30)\$\[\033[0m\] " >> ~/.bashrc

Restart your session for the change to take effect.
