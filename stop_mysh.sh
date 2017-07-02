#!/bin/bash

ARG_FILE=$1
PID=`pidof $ARG_FILE`
kill -9 $PID