#include <iostream>
using namespace std;
void printArray(const int a[], int n) {

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << "\n";
}
void bubbleSort(int a[], int n,
    int& comparisons, int& swaps,
    bool ascending = true) {

    comparisons = 0;
    swaps = 0;

    for (int pass = 0; pass < n - 1; pass++) {

        bool swapped = false;

        for (int j = 0; j < n - pass - 1; j++) {

            comparisons++;

            bool wrongOrder;

            if (ascending)
                wrongOrder = a[j] > a[j + 1];
            else
                wrongOrder = a[j] < a[j + 1];

            if (wrongOrder) {

                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                swaps++;
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}
void selectionSort(int a[], int n,
    int& comparisons, int& swaps,
    bool ascending = true) {

    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < n - 1; i++) {

        int selected = i;

        for (int j = i + 1; j < n; j++) {

            comparisons++;

            bool better;

            if (ascending)
                better = a[j] < a[selected];
            else
                better = a[j] > a[selected];

            if (better)
                selected = j;
        }
        if (selected != i) {

            int temp = a[i];
            a[i] = a[selected];
            a[selected] = temp;

            swaps++;
        }
    }
}
int binarySearch(const int a[], int n,
    int key, int& checks) {

    int low = 0;
    int high = n - 1;

    checks = 0;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        checks++;

        if (a[mid] == key)
            return mid;

        if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}


int linearSearch(const int a[], int n,
    int key, int& checks) {

    checks = 0;

    for (int i = 0; i < n; i++) {

        checks++;

        if (a[i] == key)
            return i;
    }

    return -1;
}
void runExperiment(const int original[], int n,
    const char name[]) {

    int b[10], s[10];

    int bc, bs, sc, ss;

    for (int i = 0; i < n; i++) {
        b[i] = original[i];
        s[i] = original[i];
    }

    cout << "\n" << name << "\n";

    cout << "Starting array: ";
    printArray(original, n);

    bubbleSort(b, n, bc, bs);
    selectionSort(s, n, sc, ss);

    cout << "Bubble sorted: ";
    printArray(b, n);

    cout << "Bubble comparisons = " << bc
        << ", swaps = " << bs << "\n";

    cout << "Selection sorted: ";
    printArray(s, n);

    cout << "Selection comparisons = " << sc
        << ", swaps = " << ss << "\n";
}

int main() {

    const int N = 10;
    const int R = 89;
    int array1[N] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
    int array2[N] = {
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    };
    int array3[N] = {
        5, 3, 5, 1, 3, 5, 1, 3, 1, 5
    };
    int array4[N];

    for (int i = 0; i < N; i++) {

        array4[i] =
            (R * (i + 1) * 37 + i * i * 13) % 100;
    }

    cout << "PERSONAL VALUE R = " << R << "\n";

    runExperiment(array1, N, "ARRAY 1 - SORTED");

    runExperiment(array2, N, "ARRAY 2 - REVERSED");

    runExperiment(array3, N, "ARRAY 3 - DUPLICATES");

    runExperiment(array4, N, "ARRAY 4 - PERSONAL");
    int descending[N];

    int dc, ds;

    for (int i = 0; i < N; i++)
        descending[i] = array4[i];

    bubbleSort(descending, N, dc, ds, false);

    cout << "\nARRAY 4 IN DESCENDING ORDER:\n";

    printArray(descending, N);

    cout << "Comparisons = " << dc
        << ", swaps = " << ds << "\n";
    int sorted[N];

    for (int i = 0; i < N; i++)
        sorted[i] = array4[i];

    bubbleSort(sorted, N, dc, ds);

    int keys[3] = {
        sorted[0],
        sorted[4],
        101
    };

    const char* labels[3] = {
        "Start key",
        "Middle key",
        "Missing key"
    };

    cout << "\nBINARY SEARCH BONUS\n";

    cout << "Sorted Array 4: ";
    printArray(sorted, N);

    for (int i = 0; i < 3; i++) {

        int binaryChecks, linearChecks;

        int binaryIndex =
            binarySearch(sorted, N, keys[i], binaryChecks);

        int linearIndex =
            linearSearch(sorted, N, keys[i], linearChecks);

        cout << labels[i] << " (" << keys[i] << "): ";

        cout << "Binary index = " << binaryIndex
            << ", checks = " << binaryChecks;

        cout << "; Linear index = " << linearIndex
            << ", checks = " << linearChecks << "\n";
    }

    return 0;
}
