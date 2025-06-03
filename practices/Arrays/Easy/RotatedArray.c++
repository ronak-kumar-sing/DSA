
/*
 * ===============================================================================
 * 🔄 ARRAY ROTATION - COMPREHENSIVE EDUCATIONAL GUIDE
 * ===============================================================================
 *
 * 🎯 PROBLEM STATEMENT:
 * Given an array and a number k, rotate the array to the right by k positions.
 * Each element moves k positions to the right, wrapping around to the beginning.
 *
 * 📊 DIFFICULTY: Medium (Perfect for learning array manipulation)
 * ⏱️  TIME TO LEARN: 15-20 minutes
 *
 * 🧠 KEY LEARNING CONCEPTS:
 * • Array indexing and modular arithmetic
 * • Trade-offs between time and space complexity
 * • In-place vs auxiliary space algorithms
 * • Mathematical optimization techniques
 *
 * 🏆 INTERVIEW RELEVANCE: ⭐⭐⭐⭐⭐
 * Common in: Google, Amazon, Microsoft, Facebook technical interviews
 */

#include <iostream>
#include <algorithm> // For reverse() function used in optimized method
using namespace std;

/**
 * 🔄 ARRAY ROTATION DEEP DIVE
 *
 * 📚 PROBLEM UNDERSTANDING:
 * Rotate array [1,2,3,4,5] right by 2 positions → [4,5,1,2,3]
 * Notice: Last 2 elements move to front, others shift right
 *
 * 🧠 CORE CONCEPT: Circular shifting
 * Think of the array as a circle where the last position connects to the first.
 * Rotation = shifting the "starting point" of our view of this circle.
 *
 * 🏠 REAL LIFE ANALOGIES:
 * 1. 🎠 Carousel: Seats rotate, but relative positions stay same
 * 2. 🪑 Musical chairs: Everyone moves k seats clockwise
 * 3. 📦 Conveyor belt: Items shift right, end items wrap to beginning
 * 4. 🕐 Clock face: Numbers rotate but maintain spacing
 *
 * 🔢 MATHEMATICAL INSIGHT:
 * For element at position i, new position = (i + k) % n
 * The % operator handles the wrap-around automatically!
 *
 * 📈 COMPLEXITY ANALYSIS:
 * Method 1 (Extra Space): Time O(n), Space O(n) - Beginner friendly
 * Method 2 (Three Reversals): Time O(n), Space O(1) - Interview favorite
 */

// Sample Input
// 6 3
// 2 3 4 5 6 7
// Expected Output: 5 6 7 2 3 4

/**
 * 🔄 METHOD 1: Using Extra Space (Easier to understand)
 * Think: Create a new arrangement, then copy it back
 *
 * @param arr: Array to rotate
 * @param n: Array size
 * @param k: Number of positions to rotate right
 */
void rotatedArray(int arr[], int n, int k)
{
  // 🛡️ Handle cases where k > n (e.g., k=8, n=6 → k=2)
  k = k % n;

  // 📦 Create temporary array to store new arrangement
  int temp[n];

  // 🔄 Place each element in its new rotated position
  for (int i = 0; i < n; i++)
  {
    // Formula: new_position = (current_position + k) % n
    temp[(i + k) % n] = arr[i];
  }

  // 📋 Copy the new arrangement back to original array
  for (int i = 0; i < n; i++)
  {
    arr[i] = temp[i];
  }
}

/**
 * 🔄 METHOD 2: Space Optimized (Advanced technique)
 * Think: Use three reversals to achieve rotation
 *
 * Magic Formula: To rotate right by k:
 * 1. Reverse entire array
 * 2. Reverse first k elements
 * 3. Reverse remaining n-k elements
 *
 * @param arr: Array to rotate
 * @param n: Array size
 * @param k: Number of positions to rotate right
 */
void rotatedArrayOptimized(int arr[], int n, int k)
{
  k = k % n; // Handle k > n

  // Step 1: Reverse entire array
  reverse(arr, arr + n);

  // Step 2: Reverse first k elements
  reverse(arr, arr + k);

  // Step 3: Reverse remaining n-k elements
  reverse(arr + k, arr + n);
}

int main()
{
  int n, k;
  cout << "Enter array size and rotation count: ";
  cin >> n >> k;

  int arr[n];
  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  // Show original array
  cout << "\nOriginal Array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  // Choose one method (comment out the other)
  rotatedArray(arr, n, k); // Method 1: Extra space
  // rotatedArrayOptimized(arr, n, k);  // Method 2: No extra space

  cout << "\nRotated Array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
// * 🔄 Method 2 : Three Reversals
// Original: [2, 3, 4, 5, 6, 7]

// Step 1: Reverse entire array
// [2, 3, 4, 5, 6, 7] → [7, 6, 5, 4, 3, 2]

// Step 2: Reverse first k=3 elements
// [7, 6, 5, 4, 3, 2] → [5, 6, 7, 4, 3, 2]
//  -------              -------
// reverse these         reversed!

// Step 3: Reverse remaining n-k=3 elements
// [5, 6, 7, 4, 3, 2] → [5, 6, 7, 2, 3, 4]
//           -------              -------
//           reverse              reversed!

// Final: [5, 6, 7, 2, 3, 4] ✅

// * 🔄 Method 1 : Using Extra Space
//  Original: [2, 3, 4, 5, 6, 7]
//  Position:  0  1  2  3  4  5

// Step 1: Calculate new positions (shift right by 3)
// arr[0] = 2 → goes to position (0+3)%6 = 3
// arr[1] = 3 → goes to position (1+3)%6 = 4
// arr[2] = 4 → goes to position (2+3)%6 = 5
// arr[3] = 5 → goes to position (3+3)%6 = 0  ← wraps around!
// arr[4] = 6 → goes to position (4+3)%6 = 1  ← wraps around!
// arr[5] = 7 → goes to position (5+3)%6 = 2  ← wraps around!

// Step 2: temp array becomes:
// Position: [0, 1, 2, 3, 4, 5]
// temp:     [5, 6, 7, 2, 3, 4]

// Step 3: Copy back to original
// Result: [5, 6, 7, 2, 3, 4]
/**
 * ⚡ COMPREHENSIVE PERFORMANCE & LEARNING ANALYSIS
 *
 * 📊 METHOD COMPARISON TABLE:
 * ┌─────────────────┬──────────┬─────────┬─────────────┬─────────────────┐
 * │ Method          │ Time     │ Space   │ Difficulty  │ Best Use Case   │
 * ├─────────────────┼──────────┼─────────┼─────────────┼─────────────────┤
 * │ Extra Space     │ O(n)     │ O(n)    │ Easy 😊     │ Learning/Debug  │
 * │ Three Reversals │ O(n)     │ O(1)    │ Medium 🤔   │ Interviews/Prod │
 * └─────────────────┴──────────┴─────────┴─────────────┴─────────────────┘
 *
 * 🎯 WHEN TO USE WHICH METHOD:
 *
 * 📖 Method 1 (Extra Space) - Choose when:
 * ✅ Learning array concepts for the first time
 * ✅ Code readability is more important than memory
 * ✅ Working with small arrays (memory not a concern)
 * ✅ Need to preserve original array for comparison
 * ❌ Avoid when: Memory is limited or array is very large
 *
 * 🚀 Method 2 (Three Reversals) - Choose when:
 * ✅ Memory optimization is crucial
 * ✅ In technical interviews (shows advanced thinking)
 * ✅ Working with large datasets
 * ✅ Need in-place modification
 * ❌ Avoid when: Code simplicity is priority over optimization
 *
 * 🧩 WHY THREE REVERSALS WORK - The Magic Explained:
 * Think backwards! To get last k elements at front:
 * 1. Put entire array backwards → last elements come first
 * 2. Fix order of first k elements → correct front part
 * 3. Fix order of remaining elements → correct back part
 * Result: Perfect rotation achieved with just reversals!
 *
 * 💡 INTERVIEW TIPS:
 * • Always mention both approaches and their trade-offs
 * • Start with Method 1, then optimize to Method 2
 * • Explain the modular arithmetic clearly
 * • Handle edge cases: k=0, k>n, empty array
 * • Test with examples: k=0, k=n, k>n
 *
 * 🔍 COMMON MISTAKES TO AVOID:
 * 1. Forgetting k = k % n (when k > array size)
 * 2. Off-by-one errors in loop boundaries
 * 3. Not handling edge cases (empty array, k=0)
 * 4. Confusing left vs right rotation
 * 5. Integer overflow in large arrays
 *
 * 🎓 RELATED PROBLEMS TO PRACTICE:
 * • Rotate Array Left
 * • Rotate String
 * • Cyclic Array Search
 * • Find Minimum in Rotated Sorted Array
 */