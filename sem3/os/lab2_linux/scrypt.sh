#!/bin/bash

for((CPUs=1; CPUs<=6; CPUs++)); do
	taskset -c 0-$(($CPUs - 1)) ./a.out
done
