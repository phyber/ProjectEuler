#!/bin/bash
ARGS=("$@")
# Zero pad the problem so they line up nicely
PROB=$(printf "%03d" "${ARGS[0]}")

if [ ! -d "${PROB}" ]; then
	echo "Creating directory for problem ${PROB} and copying base files."
	mkdir ${PROB}
	if [ $? -eq 0 ]; then
		for i in base.*; do
			cp ${i} ${PROB}/$(echo ${i} | sed 's/base/solution/')
		done
	else
		echo "Problem creating problem directory! :o"
		exit 1
	fi
fi
