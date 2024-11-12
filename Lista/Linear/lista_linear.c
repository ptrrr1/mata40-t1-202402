#include <stdio.h>

// Complexity of O(n)
// It searches through all n of them in worst case
int search_unordered(int arr[], int cur_size, int target) {
  int i = 0;
  while (arr[i] != target && i < cur_size) {
    i++;
  }
  return i < cur_size ? i : -1;
}

void include_unordered(int arr[], int max, int *cur_size, int target) {
  if (*cur_size < max) {
    if (search_unordered(arr, *cur_size, target) == -1) {
      arr[*cur_size] = target;
      *cur_size += 1;
    } else {
      printf("Already Exists\n");
    }
  } else {
    printf("Full list\n");
  }
}

void remove_unordered(int arr[], int max, int *cur_size, int target) {
  if (*cur_size > 0) {
    int idx = search_unordered(arr, *cur_size, target);
    if (idx != -1) {
      for (int i = idx; i < *cur_size; i++) {
        arr[i] = arr[i + 1];
      }
      *cur_size -= 1;
    } else {
      printf("Doesn't exist\n");
    }
  } else {
    printf("Empty list\n");
  }
}

/* ------------------------------------------------------------ */

// Complexity of O(log n)
// Becauses it uses divide and conquer, so it doesn't go through
// all elements, in worst case it's log n elements
int binary_search(int arr[], int cur_size, int target) {
  int idx = -1;
  int left = 0;
  int right = cur_size - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
      left = right + 1;
      idx = mid;
    } else if (arr[mid] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return idx;
}

void include_ordered(int arr[], int max, int *cur_size, int target) {
  if (*cur_size < max) {
    int idx = binary_search(arr, *cur_size, target);
    if (idx == -1) {
      idx = *cur_size;
      while (idx >= 0 && target < arr[idx]) {
        arr[idx] = arr[idx - 1];
        idx--;
      }
      arr[idx + 1] = target;
      *cur_size += 1;
    } else {
      printf("Already exists\n");
    }
  } else {
    printf("Full List\n");
  }
}

void remove_ordered(int arr[], int max, int *cur_size, int target) {
  if (*cur_size > 0) {
    int idx = binary_search(arr, *cur_size, target);
    if (idx != -1) {
      for (int i = idx; i < *cur_size; i++) {
        arr[i] = arr[i + 1];
      }
      *cur_size -= 1;
    } else {
      printf("Doesn't exist\n");
    }
  } else {
    printf("Empty list\n");
  }
}

/* ------------------------------------------------------------ */

int main(int argc, char const *argv[]) {
  int n;   // cur size
  int max; // max size
  int arr[max];

  return 0;
}