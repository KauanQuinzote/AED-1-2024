
def ordenando():
    array = [1 , 2 , 27 , 4, 12]
    
    def quicksort(array):
        if len(array) == 1:
            return array[0]
        else:
            m = int(len(array)/2)
            if array[0] < quicksort(array[m:]):
                x = array[0]
                array[0] = m
        
    resultado = quicksort(array)
    print(resultado)
    
ordenando()