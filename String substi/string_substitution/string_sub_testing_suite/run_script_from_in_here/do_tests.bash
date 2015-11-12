#!/bin/bash

EXECUTABLE_NAME=./a.out

if [ ! -e ../origfiles ] 
then
  echo "can't find original files. Are you in the correct directory?"
  exit 1
fi

cp ../origfiles/File01.txt Test01.txt
cp ../origfiles/File01.txt Test02.txt
cp ../origfiles/File01.txt Test03.txt
cp ../origfiles/File02.txt Test04.txt
cp ../origfiles/File02.txt Test05.txt
cp ../origfiles/File02.txt Test06.txt
cp ../origfiles/File03.txt Test07.txt
cp ../origfiles/File03.txt Test08.txt
cp ../origfiles/File03.txt Test09.txt
cp ../origfiles/File04.txt Test10.txt
cp ../origfiles/File05.txt Test11.txt
cp ../origfiles/File06.txt Test12.txt
cp ../origfiles/File07.txt Test13.txt
cp ../origfiles/File08.txt Test14.txt
cp ../origfiles/File09.txt Test15.txt
cp ../origfiles/File10.txt Test16.txt
cp ../origfiles/File11.txt Test17.txt
cp ../origfiles/File12.txt Test18.txt

cat ../list_of_tests.dat | while read testname old new filename
do
  echo "================"
  echo $testname
  echo "================"
  $EXECUTABLE_NAME $old $new $testname.txt 
  diff $testname.txt ../expected_results/$testname.txt >/dev/null
  if [ $? -eq 0 ]
  then
    echo "$testname success!" 
  else
    echo "$testname failure <########################################"
    #only show contents of short files
    echo "Search for: $old, replace with: $new"
    if [ `wc -c ../origfiles/$filename|awk '{print $1}'` -lt 50 ]
    then
      echo -n "Original file:--->"
      cat ../origfiles/$filename
      echo "<-"
      echo -n "Expected result:->"
      cat ../expected_results/$testname.txt
      echo "<-"
      echo -n "Test result:----->"
      cat $testname.txt
      echo "<-"
    else
      echo "Original file: ../origfiles/$filename"
      echo "Expected results: ../expected_results/$testname.txt"
      echo "Test results: $testname.txt"
    fi
  fi
  echo
  echo
done
