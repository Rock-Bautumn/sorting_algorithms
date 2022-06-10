siftDown(arr, start, end) {
   root = start
   while (root * 2 + 1 <= end) {
      lchild = root * 2 + 1            // subscript of left child
      swap = root
      if (arr[swap] < arr[lchild])
         swap = lchild                 // should swap root & left child
      if (lchild + 1 <= end && arr[swap] < arr[lchild+1])
         swap = lchild + 1              // should swap root & right child
      if (swap != root) {              // if one of children is greater
         swap(arr[root],arr[swap])     // swap root & larger child
         root = swap
      }
      else
         return
}


heapify(arr, size) {
    start = size/2 - 1                   // last non leaf
    while (start >= 0) {
        siftdown(arr, start, size-1)
        start = start - 1
    }
}