#!/bin/bash

counter=1
while [ $counter -le 10]
do
	if [$(($(awk -v seed=$RANDOM 'BEGIN{srand(seed);print rand()}') ** 2) + $(($(awk -v seed=$RANDOM 'BEGIN{srand(seed);print rand()}') ** 2))]
