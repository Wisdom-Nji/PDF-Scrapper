#!/bin/sh
TEST_NAME=OCRTest
javac -cp ../../../Lib/PDFNet.jar *.java
java -Djava.library.path=../../../Lib -cp .:../../../Lib/PDFNet.jar $TEST_NAME
