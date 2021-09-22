rem this is a test list.

rem test: No Argument.
main.exe
rem test: No output file.
main.exe f0.txt s0.txt
rem test: Wrong input file name.
main.exe f5000.txt s0.txt ans0.txt
rem test: Empty file.
main.exe f0.txt s0.txt ans0.txt
rem test 1:
main.exe f1.txt s1.txt ans1.txt
rem test 2:
main.exe f2.txt s2.txt ans2.txt
rem test 3:
main.exe f3.txt s3.txt ans3.txt
rem test 3:
main.exe orig.txt orig_0.8_add.txt ans_orig_0.8_add.txt
rem test 4:
main.exe orig.txt orig_0.8_del.txt ans_orig_0.8_del.txt
rem test 5:
main.exe orig.txt orig_0.8_dis_1.txt ans_orig_0.8_dis_1.txt
rem test 6:
main.exe orig.txt orig_0.8_dis_10.txt ans_orig_0.8_dis_10.txt
rem test 7:
main.exe orig.txt orig_0.8_dis_15.txt ans_orig_0.8_dis_15.txt

pause