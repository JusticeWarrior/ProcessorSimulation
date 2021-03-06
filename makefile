all:
	gcc $(flags) $(source) main.c -o PRJ1

flags = -Wall -Wshadow -g
source = FEL.c ListNode.c Event.c Queue.c SimulationData.c Server.c Control.c -lm

test1:
	gcc $(flags) $(source) UnitTestSet1.c -o PRJ1
	PRJ1
test2:
	gcc $(flags) $(source) UnitTestSet2.c -o PRJ1
	PRJ1
test3:
	gcc $(flags) $(source) UnitTestSet3.c -o PRJ1
	PRJ1
test4:
	gcc $(flags) $(source) UnitTestSet4.c -o PRJ1
	PRJ1
test5:
	gcc $(flags) $(source) UnitTestSet5.c -o PRJ1
	PRJ1
test7:
	gcc $(flags) $(source) UnitTestSet7.c -o PRJ1
	PRJ1
