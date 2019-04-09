#!/bin/sh

gcc -o mytail mytail.c
apt | ./mytail -n 3