#!/bin/bash

LIBRARY_NAME=Gong
LIBARY_SOURCE_PATH=../libraries/
SKETCHBOOK_PATH=/cygdrive/d/Libraries/Documents/Arduino/libraries

if [ ! -d $LIBRARY_SOURCE_PATH/$LIBARY_NAME ] #check to see if the updated library exists
then
	echo "Error: libary source path \" $LIBRARY_SOURCE_PATH/$LIBRARY_NAME \" does not exist"
	exit 1
fi

if [ ! -d $SKETCHBOOK_PATH ]  #check if the target directory exits
then
	echo "Error: path \" $SKETCHBOOK_PATH \" does not exist"
	exit 1
fi

if [ -d $SKETCHBOOK_PATH/$LIBARY_NAME ]  #remove the outdated library
then
	rm -rf $SKETCHBOOK_PATH/$LIBRARY_NAME
fi

cp -r ../libraries/$LIBRARY_NAME $SKETCHBOOK_PATH/$LIBARY_NAME #update the library

echo "Update successful"
