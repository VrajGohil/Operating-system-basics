requestSequence = [int(i) for i in input("Enter the sequence :").split()]
headPostion = int(input("Enter the initial head position :"))
requestSequence.sort()
lessThenHead = []
greaterThenHead = []
for i in requestSequence:
    if i < headPostion:
        lessThenHead.append(i)
    else:
        greaterThenHead.append(i)
lessThenHead.reverse()
seekSequence = lessThenHead + greaterThenHead
print("Seek Sequence is :", seekSequence)
totalSeek = headPostion-seekSequence[0]
print(headPostion,'-',seekSequence[0])
for i in range (1,len(seekSequence)):
    if(seekSequence[i] > headPostion):
        print(seekSequence[i],'-',seekSequence[i-1])
        totalSeek += (seekSequence[i]-seekSequence[i-1])
    else:
        print(seekSequence[i-1],'-',seekSequence[i])
        totalSeek += (seekSequence[i-1]-seekSequence[i])

print("Total number of seek operations = ", totalSeek)