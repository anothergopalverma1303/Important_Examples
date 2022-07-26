def quickSort(arr, low, high):
    if(low >= high):
        return

    s = low
    e = high
    m = s+(e-s)//2
    p = arr[m]

    while(s<=e):
        while(arr[s]<p):
            s+=1
        while(arr[e]>p):
            e-=1
        if(s<=e):
            tmp = arr[s]
            arr[s] = arr[e]
            arr[e] = tmp
            s+=1
            e-=1

    quickSort(arr, low, e)
    quickSort(arr, s, high)
    
arr = list([5, 4, 3, 2, 1])
quickSort(arr, low = 0, high = len(arr)-1)
print(arr)
