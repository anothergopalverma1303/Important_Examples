// C++ program to find the array
// element that appears only once
#include <iostream>
using namespace std;

int findSingle(int ar[], int ar_size)
    {
        // Do XOR of all elements and return
    if(n = 1)
        return (arr[0]);
    else
    {
        int res = ar[0];
        for (int i = 1; i < ar_size; i++)
            res = res ^ ar[i];  
        return res                                    //here the philosophy of usage of ^ is that it act as  a switch ie if same sinal are applied
    }                                                 //then it is gonna be off (0^0 = 0, 1^1 = 0) and if different signals are applied it became on
                                                      // (1^0 = 1, 0^1 = 0). So the repeating signals repeated themselves and closed themselves but the 
                                                      // single integer were not able to switch themself off.
                                                      //* but it can only work when the repeating characters are only twice in number.

        
    }

// Driver code
int main()
    {
        int ar[] = {2, 3, 2};
        int n = sizeof(ar) / sizeof(ar[0]);
        cout << "Element occurring once is "
            << findSingle(ar, n);
        return 0;
    }
