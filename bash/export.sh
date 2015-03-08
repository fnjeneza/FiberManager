#!/bin/bash

mdb-export -d ";" -q "" $1 $2 > hello.txt
