#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
// 1. CORE SORTING ALGORITHMS

// Selection Sort all cases O(N^2)
void selectionSort(vector<uint64_t>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int mn = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[mn]) 
                mn = j;
        }

        swap(arr[i], arr[mn]);
    }
}

// Insertion Sort O(N^2) worst, O(N) best
void insertionSort(vector<uint64_t>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        uint64_t key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Max-Heap Subroutines
void heapify(vector<uint64_t>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(vector<uint64_t>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

uint64_t extractMax(vector<uint64_t>& arr, int& heap_size) {
    if (heap_size <= 0) return 0;
    uint64_t max_val = arr[0];
    arr[0] = arr[heap_size - 1];
    heap_size--;
    heapify(arr, heap_size, 0);
    return max_val;
}

void heapSort(vector<uint64_t>& arr) {
    int n = arr.size();
    buildHeap(arr);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Counting & Radix Sort (32-bit & 64-bit)
void countingSortDigit(vector<uint32_t>& arr, uint32_t exp) {
    int n = arr.size();
    vector<uint32_t> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) 
      count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++) 
      count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(vector<uint32_t>& arr) {
    if (arr.empty()) return;
    uint32_t max_val = *max_element(arr.begin(), arr.end());
    for (uint32_t exp = 1; max_val / exp > 0; exp *= 10) {
        countingSortDigit(arr, exp);
        if (exp > UINT32_MAX / 10) 
        break;
    }
}

void countingSortDigit(vector<uint64_t>& arr, uint64_t exp) {
    int n = arr.size();
    vector<uint64_t> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void radixSort(vector<uint64_t>& arr) {
    if (arr.empty()) return;
    uint64_t max_val = *max_element(arr.begin(), arr.end());
    for (uint64_t exp = 1; max_val / exp > 0; exp *= 10) {
        countingSortDigit(arr, exp);
        if (exp > UINT64_MAX / 10) break;
    }
}

// ==================================================
// 2. DATA GENERATORS & LOGGERS
// ==================================================

vector<uint32_t> generateData32(size_t size, uint32_t max_val = 99999) {
    vector<uint32_t> data(size);
    mt19937 rng(42);
    uniform_int_distribution<uint32_t> dist(0, max_val);
    for (size_t i = 0; i < size; ++i) data[i] = dist(rng);
    return data;
}

vector<uint64_t> generateData64(size_t size, uint64_t max_val = 99999) {
    vector<uint64_t> data(size);
    mt19937_64 rng(42);
    uniform_int_distribution<uint64_t> dist(0, max_val);
    for (size_t i = 0; i < size; ++i) data[i] = dist(rng);
    return data;
}

// Log CSV outputting Microseconds and Milliseconds
void logCSV(const string& phase, const string& exp, size_t n, const string& algo, double us) {
    ofstream csv("benchmark_results.csv", ios::app);
    csv << phase << "," << exp << "," << n << "," << algo << "," 
        << fixed << setprecision(3) << us << "," << (us / 1000.0) << "\n";
    csv.close();
}

// ==================================================
// 3. PHASE EXECUTORS
// ==================================================

void runPhase1() {
    cout << "\n--- Running Phase 1: Micro-Scale Shopping Carts (N=50) ---\n";
    size_t N = 50;

    auto data_rand = generateData64(N);
    auto data_nearly = data_rand;
    radixSort(data_nearly);
    swap(data_nearly[N-2],data_nearly[N-1]);
    
    

    int iterations = 1000; // Warmup & averaging loop over 1000 runs

    // Insertion Sort - Random
    auto start = high_resolution_clock::now();
    for (int i = 0; i < iterations; i++) {
        auto test = data_rand;
        insertionSort(test);
    }
    double us_rand_ins = (double)duration_cast<nanoseconds>(high_resolution_clock::now() - start).count() / (1000.0 * iterations);
    logCSV("Phase1", "Random", N, "InsertionSort", us_rand_ins);

    // Insertion Sort - Nearly Sorted
    start = high_resolution_clock::now();
    for (int i = 0; i < iterations; i++) {
        auto test = data_nearly;
        insertionSort(test);
    }
    double us_near_ins = (double)duration_cast<nanoseconds>(high_resolution_clock::now() - start).count() / (1000.0 * iterations);
    logCSV("Phase1", "NearlySorted", N, "InsertionSort", us_near_ins);

    // Selection Sort - Random
    start = high_resolution_clock::now();
    for (int i = 0; i < iterations; i++) {
        auto test = data_rand;
        selectionSort(test);
    }
    double us_rand_sel = (double)duration_cast<nanoseconds>(high_resolution_clock::now() - start).count() / (1000.0 * iterations);
    logCSV("Phase1", "Random", N, "SelectionSort", us_rand_sel);

    // Selection Sort - Nearly Sorted
    start = high_resolution_clock::now();
    for (int i = 0; i < iterations; i++) {
        auto test = data_nearly;
        selectionSort(test);
    }
    double us_near_sel = (double)duration_cast<nanoseconds>(high_resolution_clock::now() - start).count() / (1000.0 * iterations);
    logCSV("Phase1", "NearlySorted", N, "SelectionSort", us_near_sel);

    cout << "Phase 1 complete. Logged in Microseconds to CSV.\n";
}

void runPhase2() {
    cout << "\n--- Running Phase 2: VIP Order Extraction (N=100,000, K=500) ---\n";
    size_t N = 100000;
    int K = 500;
    auto orders = generateData64(N, 1000000);

    // Full Heap Sort
    auto test_a = orders;
    auto start = high_resolution_clock::now();
    heapSort(test_a);
    double us_a = duration_cast<microseconds>(high_resolution_clock::now() - start).count();
    logCSV("Phase2", "Top500_Extract", N, "FullHeapSort", us_a);

    // Partial Extraction via Build Heap + K Extract Max
    auto test_b = orders;
    start = high_resolution_clock::now();
    buildHeap(test_b);
    int heap_sz = N;
    vector<uint64_t> top_k;
    for (int i = 0; i < K; i++) {
        top_k.push_back(extractMax(test_b, heap_sz));
    }
    double us_b = duration_cast<microseconds>(high_resolution_clock::now() - start).count();
    logCSV("Phase2", "Top500_Extract", N, "BuildHeap_Extract500", us_b);

    cout << "Phase 2 complete. Logged to CSV.\n";
}

void runPhase3() {
    cout << "\n--- Running Phase 3: Macro Logistics Routing (N=1,000,000) ---\n";
    size_t N = 1000000;
    auto postal_codes = generateData64(N, 99999);

    // Heap Sort
    auto test_heap = postal_codes;
    auto start = high_resolution_clock::now();
    heapSort(test_heap);
    double us_heap = duration_cast<microseconds>(high_resolution_clock::now() - start).count();
    logCSV("Phase3", "Logistics_1M", N, "HeapSort", us_heap);

    // Radix Sort
    auto test_radix = postal_codes;
    start = high_resolution_clock::now();
    radixSort(test_radix);
    double us_radix = duration_cast<microseconds>(high_resolution_clock::now() - start).count();
    logCSV("Phase3", "Logistics_1M", N, "RadixSort", us_radix);

    cout << "Phase 3 complete. Logged to CSV.\n";
}

void runBonusChallenge() {
    cout << "\n--- Running Bonus: Memory Bandwidth Bottleneck (N=5,000,000) ---\n";
    size_t N = 5000000;

    // 32-bit Array Test
    auto data32 = generateData32(N, 99999);
    auto start = high_resolution_clock::now();
    radixSort(data32);
    double us32 = duration_cast<microseconds>(high_resolution_clock::now() - start).count();
    logCSV("Bonus", "Bandwidth_5M", N, "RadixSort_32bit", us32);

    // 64-bit Array Test
    auto data64 = generateData64(N, 99999);
    start = high_resolution_clock::now();
    radixSort(data64);
    double us64 = duration_cast<microseconds>(high_resolution_clock::now() - start).count();
    logCSV("Bonus", "Bandwidth_5M", N, "RadixSort_64bit", us64);

    cout << "Bonus Challenge complete. Logged to CSV.\n";
}

// ==================================================
// 4. MAIN INTERACTIVE MENU
// ==================================================

int main() {
    // Write header ONCE at application start
    ofstream csv("benchmark_results.csv");
    csv << "Phase,Experiment,Dataset_Size,Algorithm,Time_Microseconds,Time_Milliseconds\n";
    csv.close();

    int choice = 0;
    while (choice != 6) {
        cout << "\n========================================" << endl;
        cout << "   E-COMMERCE SORTING PIPELINE MENU    " << endl;
        cout << "========================================" << endl;
        cout << "1. Run Phase 1 (Micro-Scale Carts)" << endl;
        cout << "2. Run Phase 2 (VIP Priority Extraction)" << endl;
        cout << "3. Run Phase 3 (Macro Logistics Routing)" << endl;
        cout << "4. Run Bonus Challenge (64-bit Bandwidth)" << endl;
        cout << "5. Run All Pipeline Benchmarks" << endl;
        cout << "6. Exit" << endl;
        cout << "Select an option (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: runPhase1(); break;
            case 2: runPhase2(); break;
            case 3: runPhase3(); break;
            case 4: runBonusChallenge(); break;
            case 5:
                runPhase1();
                runPhase2();
                runPhase3();
                runBonusChallenge();
                break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid option! Try again.\n";
        }
    }
    return 0;
}