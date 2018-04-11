#https://www.geeksforgeeks.org/find-common-elements-three-sorted-arrays/

def common(a, b, c, n1, n2, n3):
    a.sort()
    b.sort()
    c.sort()

    L = []
    
    i, j, k = 0, 0, 0
 
    while(i < n1 and j < n2 and k < n3):

        #print(i,' ', j, ' ', k)
        if(a[i] == b[j] and b[j] == c[k]):
            print(a[i])
            L.append(a[i])
            i += 1
            j += 1
            k += 1

        elif a[i] < b[j]:
            i += 1

        elif b[j] < c[k]:
            j += 1

        else:
            k += 1


    #return sum(L)

ar1 = [1, 5, 10, 20, 40, 80]
ar2 = [6, 7, 20, 80, 100]
ar3 = [3, 4, 15, 20, 30, 70, 80, 120]
n1 = len(ar1)
n2 = len(ar2)
n3 = len(ar3)
common(ar1, ar2, ar3, n1, n2, n3)
