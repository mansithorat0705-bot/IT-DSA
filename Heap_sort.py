n = int(input("Enter number of elements :"))

arr = []
for i in range(n):
    val=int(input(f"Enter element {i+1}:"))
    arr.append(val)
print("\n Original array:",arr) 
   
size=len(arr)
for i in range(size // 2,1,-1):
    j=i
    while True:
        largest =j
        left=2*j+1
        right=2*j+2
        
        if left < size and arr[left] > arr[largest]:
            largest=left
        if right < size and arr[right] >arr[largest]:
            largest=right
        
        if largest != j:
            arr[j],arr[largest]=arr[largest],arr[j]
            j=largest
        else:
            break
        
for i in range(size -1,0,-1):
    arr[0],arr[i]=arr[i],arr[0]
    
    j=0
    while True:
        largest=j
        left=2*j+1
        right=2*j+2
        
        if left < i and arr[left] > arr[largest]:
            largest=left
        if right < i and arr[right] > arr[largest]:
            largest=right
            
        if largest !=j:
            arr[j],arr[largest] = arr[largest],arr[j]
            j=largest
        else:
            break
        
print("Sorted array:", arr)







