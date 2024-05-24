#include <iostream> // For input and output operations
#include <vector>  //Used to create and manage dynamic arrays (vectors).
#include <algorithm> //Provides a collection of algorithms (e.g., sort).
#include <cmath>  //Includes mathematical functions (e.g., pow, ceil).

using namespace std;

// Function to calculate the value of k such that 2^k > n
int calculateK(int n) {
    int k = 0;
    while (pow(2, k) <= n) {
        k++;
    }
    return k;
}

// Function to calculate and display the range of the data
void calculateRange(const vector<int>& numbers) {
    int min_num = numbers[0];
    int max_num = numbers[numbers.size() - 1];
    int range = max_num - min_num;
    cout << "Minimum Number = " << min_num << endl;
    cout << "Maximum Number = " << max_num << endl;
    cout << "Range = " << range << endl;
}

// Function to calculate the width of each class interval
int calculateWidth(int range, int k) {
    return ceil(static_cast<double>(range) / k);  //The ceil() approximate the fraction to a greater value
}

int main() {
    int size;
    cout << "Enter the number of elements: " << endl; //The number of n
    cin >> size;
    vector<int> numbers(size);

    // Inputting the data elements
    for (int i = 0; i < size; i++) {
        cout << "Please enter Number " << "(" << i + 1 << ")" << ": " << endl;
        cin >> numbers[i];
    }
    cout << endl;

    system("cls");

    // Sorting the data for easier calculations
    sort(numbers.begin(), numbers.end());

    // Calculating the value of k
    int k = calculateK(size);
    cout << "The value of k = " << k << endl;

    // Displaying the range of the data
    calculateRange(numbers);

    // Calculating the width of each class interval
    int width = calculateWidth(numbers[numbers.size() - 1] - numbers[0], k);
    cout << "Width = " << width << endl << endl;

    // Displaying the table headers
    cout << "Class limit\t" << "    Frequency\t\t" << "   R.F\t\t" << "C.F\t\t" << "Mid point" << endl << endl;

    int lower_limit = numbers[0];
    int total_frequency = 0;
    double total_relative_frequency = 0.0;
    int cumulative_frequency = 0;

    //class limit
    for (int i = 0; i < k; i++) {
        int upper_limit = lower_limit + width;
        cout << lower_limit << " - " << upper_limit << "\t\t\t";

        // Calculating frequency for each class interval
        int frequency = 0;
        for (int j = 0; j < size; j++) {
            if (numbers[j] >= lower_limit && numbers[j] < upper_limit) {
                frequency++;
            }
        }
        cumulative_frequency += frequency;
        total_frequency += frequency;

        // Calculating relative frequency
        double relative_frequency = static_cast<double>(frequency) / size;
        total_relative_frequency += relative_frequency;

        // Calculating midpoint of each class interval
        double mid_point = (lower_limit + upper_limit) / 2.0;
        cout << frequency << "\t\t   " << relative_frequency << "\t\t " << cumulative_frequency << "\t\t    " << mid_point << "\t\t";

        cout << endl;
        lower_limit = upper_limit;
    }
    cout << endl << endl;
    cout << "Total" << "\t\t  Frequency = " << total_frequency << "\t     R.F = " << total_relative_frequency << endl << endl;

    return 0;
}