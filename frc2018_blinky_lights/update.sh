#!/bin/bash

LIBRARY_NAME=Gong
LIBARY_SOURCE_PATH=../libraries/

CONF_FILE=gong.conf

if [ ! -f $CONF_FILE ] #check to see if config file was read properly
then
	
	printf "No config file found. Creating \"$CONF_FILE\". Please populate."
	printf "#text The second line in this file is the path to the Arduino sketchbook / extra libraries\n\n" > $CONF_FILE
	exit 1
fi	

CONF_FILE_SKETCHBOOK_PATH_LINE=2
SKETCHBOOK_PATH=$(sed -n ${CONF_FILE_SKETCHBOOK_PATH_LINE}p ${CONF_FILE}) 

if [ -z "$SKETCHBOOK_PATH" ] #check to see if config file was read properly
then
	printf "Error: config file not formatted properly: target line $CONF_FILE_SKETCHBOOK_PATH_LINE is blank"
	exit 1
fi
if [ ! -d $LIBRARY_SOURCE_PATH/$LIBARY_NAME ] #check to see if the updated library to copy exists
then
	printf "Error: libary source path \"$LIBRARY_SOURCE_PATH/$LIBRARY_NAME\" does not exist"
	exit 1
fi

if [ ! -d $SKETCHBOOK_PATH ]  #check if the target directory exits
then
	printf "Error: path \"$SKETCHBOOK_PATH\" does not exist"
	exit 1
fi

if [ -d $SKETCHBOOK_PATH/$LIBARY_NAME ]  #remove the outdated library
then
	rm -rf $SKETCHBOOK_PATH/$LIBRARY_NAME
fi

cp -r ../libraries/$LIBRARY_NAME $SKETCHBOOK_PATH/$LIBARY_NAME #update the library

printf "Update successful"
