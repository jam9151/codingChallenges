#testAddList

from ListNode import ListNode
from addList import addLinkedLists
import random

NUM_ADDITIONAL_TESTS = 500


def createLinkedNumber(num):
	startNode = ListNode()
	current = startNode
	num = str(num)

	for i in range(len(num)):
		current.val = int(num[-(i+1)])
		if i < len(num)-1:
			current.next = ListNode()
			current = current.next

	return startNode



def getNumFromLinkedNumber(linkedNum):
	num = ""
	while linkedNum:
		num = num + str(linkedNum.val)
		linkedNum = linkedNum.next

	return int(num[::-1])


#cover the basic tests
testingMaterials = [
	[0, 0],
	[1, 1],
	[24, 33],
	[26, 36],
	[0, 125],
	[117, 0, 117],
	[99999, 18],
	[18, 99999],
	[9, 1],
	[1, 9],
	[98, 45],
	[12, 89],
	[1, 499],
	[10, 10],
	[234729, 125323],
	[723047753, 823489],
	[1000, 1],
	[34578, 97267585]
]

#generate a shit ton of tests
for i in range(NUM_ADDITIONAL_TESTS):
	maxDigits = random.randint(1, 10)
	num1 = random.randint(1, 10**maxDigits)
	num2 = random.randint(1, 10**maxDigits)
	testingMaterials.append([num1, num2])


#now test

numProblems = len(testingMaterials)
numCorrect = 0
for i in range(numProblems):
	prob = testingMaterials[i]
	correctAnswer = prob[0] + prob[1]

	print(f"Problem: {prob[0]} + {prob[1]} = {correctAnswer}\t\t".rjust(60), end="")
	print("Your answer was ", end="")
	try:
		ans = addLinkedLists(createLinkedNumber(prob[0]), createLinkedNumber(prob[1]))
	except:
		print("Your program crashed.")
		continue

	#check to see if answer is correct
	if type(ans) != ListNode:
		print("Type of answer is not a ListNode.")
		continue

	numericAnswer = getNumFromLinkedNumber(ans)

	if numericAnswer != correctAnswer:
		print("in", end="")
	else:
		numCorrect += 1
	print(f"correct: {numericAnswer}")

print(f"You got {numCorrect} correct out of {numProblems}: {100 * numCorrect/numProblems}%")



