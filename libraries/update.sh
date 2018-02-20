#!/bin/bash

declare -a CUSTOM_LIBRARIES=($(ls -d */))
CUSTOM_LIBRARY_SOURCE_PATH=. #../libraries

CONF_FILE=arduino_libraries.conf

#check to see if config file was read properly
if [ ! -f $CONF_FILE ]
then
	
	printf "No config file found. Creating \"$CONF_FILE\". Please populate."
	printf "#text The second line in this file is the path to the Arduino sketchbook / extra libraries\n\n" > $CONF_FILE
	exit 1
fi	

CONF_FILE_SKETCHBOOK_PATH_LINE=2
SKETCHBOOK_PATH=$(sed -n ${CONF_FILE_SKETCHBOOK_PATH_LINE}p ${CONF_FILE}) 

#check to see if config file is formatted properly
if [ -z "$SKETCHBOOK_PATH" ] 
then
	printf "Error: config file not formatted properly: target line $CONF_FILE_SKETCHBOOK_PATH_LINE is blank"
	exit 1
fi

#check to see if the custom library source exists
for library in ${CUSTOM_LIBRARIES[@]}
do
	if [ ! -d $CUSTOM_LIBRARY_SOURCE_PATH/$library ]
	then
		printf "Error: custom libary source path \"$CUSTOM_LIBRARY_SOURCE_PATH/$library\" does not exist"
		exit 1
	fi
done

#check if the target directory exits
if [ ! -d $SKETCHBOOK_PATH ] 
then
	printf "Error: sketchbook folder \"$SKETCHBOOK_PATH\" does not exist"
	exit 1
fi

#remove the outdated library
for library in ${CUSTOM_LIBRARIES[@]}
do
	if [ -d $SKETCHBOOK_PATH/$LIBARY_NAME ]
	then
		printf "Deleting $SKETCHBOOK_PATH/$library \n"
		rm -rf $SKETCHBOOK_PATH/$library
	fi
done

printf "\n"

#update the library
for library in ${CUSTOM_LIBRARIES[@]}
do
	printf "Copying $CUSTOM_LIBRARY_SOURCE_PATH/$library to $SKETCHBOOK_PATH/$library \n" 
	cp -r $CUSTOM_LIBRARY_SOURCE_PATH/$library $SKETCHBOOK_PATH/$library
done

printf "\nUpdate successful\n"

