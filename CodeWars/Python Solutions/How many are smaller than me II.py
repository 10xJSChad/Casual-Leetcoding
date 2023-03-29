import numpy as np

def smaller(arr):
    uniques = sorted(set(arr))
    count = np.zeros(len(uniques))  
    indices = {num: i for i, num in enumerate(uniques)}  
    
    for i in range(len(arr)-1, -1, -1):
        count[indices[arr[i]]] += 1
        arr[i] = np.sum(count[0:indices[arr[i]]])      
        
    return arr
