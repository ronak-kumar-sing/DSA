#include <iostream>
using namespace std;

/**
 * 🎯 QUICKSORT - The "Divide and Conquer" Sorting Algorithm
 *
 * 🧠 Main Idea: Pick a "pivot" element and arrange the array so that:
 * - All smaller elements go to the LEFT of pivot
 * - All larger elements go to the RIGHT of pivot
 * - Then sort left and right parts separately
 *
 * 🏠 Real Life Analogy: Organizing a classroom by height
 * 1. Pick one student as "reference height" (pivot)
 * 2. All shorter students stand on left, taller on right
 * 3. Organize left group and right group separately
 */

// Sample Input
// 8
// 3 7 8 1 2 9 4 6

/**
 * 🔄 STEP 1: PARTITION - Organize elements around pivot
 * This is like separating shorter and taller students
 *
 * @param arr: The array to partition
 * @param low: Start position
 * @param high: End position
 * @return: Final position where pivot ends up
 */
int pivotSort(int arr[], int low, int high)
{
  int pivot = low; // 📍 Choose first element as pivot
  int i = low;     // 👈 Left pointer (finds elements > pivot)
  int j = high;    // 👉 Right pointer (finds elements < pivot)

  cout << "🎯 Pivot chosen: " << arr[pivot] << " (at position " << pivot << ")\n";

  while (i < j)
  {
    // 👈 Move i right until we find element BIGGER than pivot
    while (arr[i] <= arr[pivot] && i <= high)
    {
      i++;
    }

    // 👉 Move j left until we find element SMALLER than pivot
    while (arr[j] > arr[pivot] && j >= low)
    {
      j--;
    }

    // 🔄 If pointers haven't crossed, swap the misplaced elements
    if (i < j)
    {
      cout << "  🔄 Swapping " << arr[i] << " and " << arr[j] << "\n";
      swap(arr[i], arr[j]);
    }
  }

  // 🎯 Put pivot in its correct final position
  cout << "  🎯 Moving pivot " << arr[pivot] << " to position " << j << "\n";
  swap(arr[j], arr[pivot]);

  cout << "  📊 After partition: ";
  for (int k = low; k <= high; k++)
    cout << arr[k] << " ";
  cout << "\n\n";

  return j; // Return pivot's final position
}

/**
 * 🚀 STEP 2: RECURSIVELY SORT - Sort left and right parts
 * Like organizing smaller groups separately
 *
 * @param arr: Array to sort
 * @param low: Start position
 * @param high: End position
 */
void quickSort(int arr[], int low, int high)
{
  // 🛑 Base case: If section has 1 or 0 elements, it's already sorted
  if (low < high)
  {
    cout << "📋 Sorting section [" << low << " to " << high << "]: ";
    for (int k = low; k <= high; k++)
      cout << arr[k] << " ";
    cout << "\n";

    // 🔄 Partition: Organize around pivot
    int pivotPosition = pivotSort(arr, low, high);

    // 🔄 Recursively sort LEFT part (smaller elements)
    cout << "⬅️  Sorting LEFT of pivot (position " << pivotPosition << ")\n";
    quickSort(arr, low, pivotPosition - 1);

    // 🔄 Recursively sort RIGHT part (larger elements)
    cout << "➡️  Sorting RIGHT of pivot (position " << pivotPosition << ")\n";
    quickSort(arr, pivotPosition + 1, high);
  }
}

int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  int arr[100];
  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << "\n🔢 Original Array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n\n🚀 Starting QuickSort...\n\n";

  quickSort(arr, 0, n - 1); // Sort from index 0 to n-1

  cout << "✅ Final Sorted Array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

/*
🎭 Visual Example : For input : [ 3, 7, 8, 1, 2, 9, 4, 6 ]

🎯 Step 1 : Choose Pivot(3)

    Array : [ 3, 7, 8, 1, 2, 9, 4, 6 ] Pivot : 3(first element)
    Goal : Put all numbers < 3 on left,
    all numbers > 3 on right

👉 Step 2 : Use Two Pointers

        [3, 7, 8, 1, 2, 9, 4, 6]
        P  i                 j

i moves right looking for number > 3
j moves left looking for number < 3

i finds 7 (> 3), j finds 6 (> 3), j continues...
j finds 4 (> 3), j continues...
j finds 2 (< 3) ✓

Swap 7 and 2: [3, 2, 8, 1, 7, 9, 4, 6]

🔄 Step 3: Continue Until Pointers Meet

After several swaps: [3, 2, 1, 8, 7, 9, 4, 6]
                      P     i        j

When i and j cross, swap pivot with j:
[1, 2, 3, 8, 7, 9, 4, 6]
       ↑
   Pivot in correct position!

🔄 Step 4: Recursively Sort Left and Right

Left part:  [1, 2]     → Already sorted!
Right part: [8, 7, 9, 4, 6] → Apply QuickSort again

Final result: [1, 2, 3, 4, 6, 7, 8, 9]
*/
