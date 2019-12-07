requestSequence = [int(i) for i in input("Enter the sequence :").split()]
headPostion = int(input("Enter the initial head position :"))
requestSequence.sort()
lessThenHead = [0]
greaterThenHead = []
for i in requestSequence:
    if i < headPostion:
        lessThenHead.append(i)
    else:
        greaterThenHead.append(i)
greaterThenHead.append(199)
seekSequence = greaterThenHead + lessThenHead
print("Seek Sequence is :", seekSequence)
totalSeek = seekSequence[0]-headPostion
print(seekSequence[0],'-',headPostion)
for i in range (1,len(seekSequence)):
    print(seekSequence[i],'-',seekSequence[i-1])
    totalSeek += (seekSequence[i]-seekSequence[i-1])
print("Total number of seek operations = ", totalSeek+199)