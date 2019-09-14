#!/bin/bash
cd ../cmake-build-debug
make clean
make
cd -
PROGRAM_LOCATION=.
COMMAND=$1
PROGRAM=$PROGRAM_LOCATION/rich
TEST_RESULT=$PROGRAM_LOCATION/result/$COMMAND.txt
DUMP=$PROGRAM_LOCATION/dump/$COMMAND.txt

$PROGRAM < COMMAND

if [ -f "test_status.txt" ]
then
    echo "test_status is going to be write..."
else
    echo "a new test_status is going to be write..."
fi

echo $TEST_RESULT
diff $TEST_RESULT $DUMP > test_status.txt
less test_status.txt

