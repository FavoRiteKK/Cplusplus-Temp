/*
 * The Insertion Sort algorithm
 * for each i from 1 to n-1, insert vec[i] to the right place in the prefix
 */
void insertion_sort(vector<int> &vec) {
    int temp, j;
    for (int i=1; i<vec.size(); i++) {
        temp = vec[i];
        j = i-1;
        while (j >= 0 && vec[j] > temp) {
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = temp;
    }
}

/*
 * Binary search
 * check the middle element, search the left or right accordingly
 */
bool binary_search(vector<int> sorted_vec, int key, size_t left, size_t right) {
    while (left <= right) {
        // the following will cause problems if you do
        // mid = (left+right)/2, due to potential integer overflow
        size_t mid = left + (right - left)/2;
        if (key > sorted_vec[mid])
            left = mid+1;
        else if (key < sorted_vec[mid])
            right = mid-1;
        else return true;
    }
    return false;
}

/*
 * The Selection Sort algorithm
 * for each i from 0 to n-2, move the i'th smallest element to its position
 */
void selection_sort(vector<int> &vec) {
    int i, j, k;
    for (i=0; i<vec.size()-1; i++) {
        j=i;
        for (k=i+1; k<vec.size(); k++)
            if (vec[k] < vec[i]) j=k;
        if (j!=i) swap(vec[i], vec[j]);
    }
}

/**
 * -----------------------------------------------------------------------------
 *  merges two halves
 * -----------------------------------------------------------------------------
 */
void merge(vector<int> &target,
           const vector<int> &left,
           const vector<int> &right)
{
    if (target.size() != left.size() + right.size()) return; // sanity check
 
    size_t i=0, j=0, k=0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) // stable, if '<' is used then unstable
            target[k++] = left[i++];
        else
            target[k++] = right[j++];
    }
 
    while (i < left.size()) target[k++] = left[i++];
    while (j < right.size()) target[k++] = right[j++];
}
 
/*
 * The Merge Sort algorithm
 * - create a copy of the left half, and a copy of the right half
 * - recursively sort the left half and the right half
 * - then merge the two halves
 */
void merge_sort(vector<int> &vec) {
    size_t n = vec.size();
    if (n <= 1) return;
    vector<int> left(vec.begin(), vec.begin()+n/2);
    vector<int> right(vec.begin()+n/2, vec.end());
    merge_sort(left);
    merge_sort(right);
    merge(vec, left, right);
}

/*
 * The Quick Sort algorithm
 * - we rearrange the members vec[p...q] so that there will be some r between
 *   p and q such that all vec[i] < vec[r] for p <= i < r and
 *                         vec[r] <= vec[j] for r < j <= q
 * - then sort vec[p..r-1] and vec[r+1..q]
 */
void qs_with_range(vector<int> &vec, int p, int q) {
    if (p >= q) return;
 
    // partition
    int r=p-1;
    for (int j=p; j<q; j++)
        if (vec[j] < vec[q])
            swap(vec[++r], vec[j]);
    swap(vec[++r], vec[q]);
 
    // sort the left & the right parts
    qs_with_range(vec, p, r-1);
    qs_with_range(vec, r+1, q);
}
/*
 * Wrapper to the quick sort algorithm
 */
void quick_sort(vector<int> &vec) {
    qs_with_range(vec, 0, vec.size()-1);
}
/*
 * The Randomized Quick Sort algorithm
 * - pick a random pivot, that's all
 */
void rqs_with_range(vector<int> &vec, int p, int q) {
    if (p >= q) return;
 
    // pick a random pivot
    int m = rand() % (q-p+1);
    swap(vec[q], vec[p+m]);
 
    // partition
    int r=p-1;
    for (int j=p; j<q; j++)
        if (vec[j] < vec[q])
            swap(vec[++r], vec[j]);
    swap(vec[++r], vec[q]);
 
    // sort the left & the right parts
    rqs_with_range(vec, p, r-1);
    rqs_with_range(vec, r+1, q);
}
/*
 * Wrapper to the randomized quick sort algorithm
 */
void randomized_quick_sort(vector<int> &vec) {
    srand(static_cast<unsigned int>(time(0)));
    rqs_with_range(vec, 0, vec.size()-1);
}


/*
 * The Heap Sort algorithm
 * - heapify the array of size n
 * - swap the first and the last
 * - sink the first and recurse
 */
/*
 * "un-spinning" the previous recursive sinking procedure, so now the function
 * is non-recursive and only uses O(1)-extra space, making heap_sort a proper
 * in place sorting algorithm
 */
void sink(vector<int> &vec, size_t i, size_t n) {
    if (n > vec.size()) return;
    size_t left, right, my_pick;
 
    while ((left = 2*i+1) < n) {
        right = left + 1; // note: right might be >= n
        my_pick = right >= n ?  left : vec[right] > vec[left] ? right : left;
        if (vec[i] >= vec[my_pick]) break; // i's subtree is already a heap
        swap(vec[i], vec[my_pick]);
        i = my_pick;
    }
}
/*
 * turn the input vector into a heap
 */
void heapify(vector<int> &vec) {
    for (int i=vec.size()/2; i>=0; i--)
        sink(vec, i, vec.size());
}
void heap_sort(vector<int> &vec) {
    heapify(vec);
    for (int j=vec.size()-1; j>=1; j--) {
        swap(vec[0], vec[j]);
        sink(vec, 0, j);
    }
}
