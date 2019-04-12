# import libraries
import queue

# make an empty set
S = set()
# add 0 to the set
S.add(0)
# check whetner a given object is a member of the set
a = 0
if a in S:
    print(a)

# make an empty stack
stack = queue.LifoQueue()