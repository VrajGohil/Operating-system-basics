import threading

def thread_run(fib_list, i):
    if i == 0:
        fib_list.append(0)
    elif i == 1 or i == 2:
        fib_list.append(1)
    else:
        fib_list.append(fib_list[i-1] + fib_list[i-2])

def main():
    N = int(input("Enter N : "))
    fib_list = []
    for i in range(0,N): 
        fib_thread = threading.Thread(target=thread_run, args=(fib_list,i))
        fib_thread.start()
        fib_thread.join()
    print(fib_list)
    
if __name__ == "__main__":
    main()
    