from time import time

from csv import reader

UNSORTED_LIST: list[int] = []


def main():
    loadList()

    bubleTime = time()
    bubleAlgorithm(UNSORTED_LIST.copy(), False)
    print(f"Buble algorithm takes {round(time() - bubleTime, 2)} seconds to sort a list of 10 000 elements in Descending order")


    insertionTime = time()
    insertionAlgorithm(UNSORTED_LIST.copy(), False)
    print(f"Buble algorithm takes {round(time() - insertionTime, 2)} seconds to sort a list of 10 000 elements in Descending order")

    # >:) 2 / 10, but we should do this in ubuntu to use java, c and javascript


def loadList():
    with open("list.csv") as f:
        buffer = reader(f)
        a: int = 0

        for i in buffer:
            if a != 0:
                UNSORTED_LIST.append(int(i[0]))
                continue
            a += 1


def bubleAlgorithm(aList:list[int, float], ascending:bool=True) -> list[int, float]:
    """
        bubleAlgorithm is a function that takes a list of int's or float's and 
       boolean, that give us the sort direction (by default ascending). And this function
       returns the same list but sorted.

        This function uses the buble sort algorithm, to see more visit: https://en.wikipedia.org/wiki/Bubble_sort
    """
    # Length of the list
    length = len(aList)

    # Limit of buble sort function O(n^2) and counter
    limit = length ** 2
    iterations = 0
    
    # How many times do we swap values? If > 0 -> isSorted = False
    changes = 0
    isSorted = False


    # Always iterate (we break in two ocations)
    while (not isSorted):
        # First security comprobator the big O notation
        if limit == iterations:
            raise Exception("Iteration number exceded while trying to sort")

        # Iterate throught all parts of the list (except for the last one, index error)
        for index in range(length - 1):
            # If the current element is greater than the next, we should swap them (Ascending)
            # Or, if the current is less than the next, we should swap (Descending)
            if aList[index] > aList[index+1] and ascending:
                # Swaping the current with the next value
                aList[index+1], aList[index] = aList[index] , aList[index+1]

                # The list is not sorted
                changes += 1
            elif aList[index] < aList[index+1] and not ascending:
                # Swaping the current with the next value
                aList[index+1], aList[index] = aList[index] , aList[index+1]
                
                # The list is not sorted
                changes += 1
            
            iterations += 1

        # Check if we can break the loop
        isSorted = (True) if changes == 0 else False
        # And restart the changes count
        changes = 0


    # Return the sorted list
    return aList

def insertionAlgorithm(aList:list[int,float], ascending:bool = True) ->list[int,float]:
    """
        insertionAlgorithm is a sort function that receive a list ('aList') of int's or float's
       and a boolean that let us know the direction of the list (ascending by default) 
       and returns the same list but sorted.

        This function is made with the insertion algorithm see more on: https://en.wikipedia.org/wiki/Insertion_sort
    """
    # We'll store the length of the list in a variable so we don't have to call a function while iterating
    length = len(aList)


    # Here we iterate the list starting in the second element (so we don't have an index error)
    for index in range(1, length):
        # Check if the element is sorted (be awere that we are sorting in the way that the user wanted, ascending or descending)
        if ((aList[index] < aList[index - 1] and ascending) or 
             (aList[index] > aList[index - 1] and not ascending)):

            # Here, we are going to iterate from the current index untill the first element or the closest sorted element
            for secondIndx in range(index, 0, -1):
                # If the current and the previous element are unsorted (looking with the sort way)
                if (ascending and aList[secondIndx] < aList[secondIndx - 1] or
                    not ascending and aList[secondIndx] > aList[secondIndx - 1]):
                    # We'll just swap them
                    aList[secondIndx], aList[secondIndx -1] = aList[secondIndx -1], aList[secondIndx]               

                elif (ascending and aList[secondIndx] >= aList[secondIndx - 1] or 
                    not ascending and aList[secondIndx] <= aList[secondIndx - 1]):
                    # But, if the current element is sorted, we'll exit (resources save)
                    break


    # Finally, we return the modified list
    return aList

if __name__ == "__main__":
    main()