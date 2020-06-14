#include<iostream>
using namespace std;

void bubble_sort(int* data, int size, bool ascending=true);
void selection_sort(int* data, int size, bool ascending=true);
void insertion_sort(int* data, int size, bool ascending=true);
void merge_sort(int* data, int size, bool ascending=true);
void print_array(int* data, int size);

int main() {
    int data[] = {8, 4, 5, 3, 2, 9, 4, 1};
    // bubble_sort(data, size, true);
    // selection_sort(data, size, true);
    // insertion_sort(data, size, true);
    int size = sizeof(data)/sizeof(data[0]);
    print_array(data, size);
    merge_sort(data, size, true);
    print_array(data, size);
    return 0;
}

void print_array(int data[], int size) {
    for(int i=0; i<size; i++) {
        cout << data[i] << " ";
    }       
    cout << endl;
}

void merge_sorted(int* data, int* left_partition_range, int* right_partition_range) {
    //copy left and right partition data in a temp array 
    int left_partition_size = left_partition_range[1] - left_partition_range[0] + 1;
    int right_partition_size = right_partition_range[1] - right_partition_range[0] + 1;
    int left_partition_temp[left_partition_size] = {};
    int right_partition_temp[right_partition_size] = {};
    for(int i=0; i<left_partition_size; i++) {
        left_partition_temp[i] = data[left_partition_range[0] + i];
    }
    for(int j=0; j<right_partition_size; j++) {
        right_partition_temp[j] = data[right_partition_range[0] + j];
    }
    //perform comparisons on the temp arrays and update the data array
    int i = 0, j = 0, k = left_partition_range[0];
    while(i<left_partition_size && j<right_partition_size) {
        //compare data of left and right partition and place the smaller at index k in data
        if(left_partition_temp[i] < right_partition_temp[j]) {
            data[k] = left_partition_temp[i];
            i++;
        }
        else {
            data[k] = right_partition_temp[j];
            j++;
        }
        k++;
    }
    //place the remaining data of temp array not fully traversed in data
    if(i < left_partition_size) {
        while(i < left_partition_size) {
            data[k] = left_partition_temp[i];
            k++;
            i++;
        }
    }
    else {
        while(j < right_partition_size) {
            data[k] = right_partition_temp[j];
            k++;
            j++;
        }
    }
}

void merge_sort(int* data, int* current_data_range) {
    // base case when the current data range permits 1 element
    int size = current_data_range[1] - current_data_range[0] + 1;
    if(size == 1) {
        return;
    }   
    // split into left and right partition
    int border = (current_data_range[0] + current_data_range[1])/2;
    int left_partition_range[2] = {current_data_range[0], border};
    int right_partition_range[2] = {border+1, current_data_range[1]}; 
    // recurse on left and right partition
    merge_sort(data, left_partition_range);
    merge_sort(data, right_partition_range);
    // merge the left and right partiton
    merge_sorted(data, left_partition_range, right_partition_range);
}

void merge_sort(int* data, int size, bool ascending) {
    int current_data_index_range[] = {0, size-1};
    merge_sort(data, current_data_index_range);
}

void insertion_sort(int* data, int size, bool ascending) {
    for(int i=1; i<size; i++) {
        if(ascending) {
            while(i>0 && data[i] < data[i-1]) {
                int temp = data[i];
                data[i] = data[i-1];
                data[i-1] = temp;
                i-=1;
            }
        }
        else {
            while(i>0 && data[i] > data[i-1]) {
                int temp = data[i];
                data[i] = data[i-1];
                data[i-1] = temp;
                i-=1;
            }
        }
    }
    return;
}

void selection_sort(int* data, int size, bool ascending) {
    for(int i=0; i<size-1; i++) {
        int min = i;
        for (int j=i+1; j<size; j++) {
            if(ascending) {
                if(data[min] > data[j]) {
                    min = j;
                }
            }
            else {
                if(data[min] < data[j]) {
                    min = j;
                }
            }
        }
        if(min != i) {
            int temp = data[i];
            data[i] = data[min];
            data[min] = temp;
        }
    }
    return;
}

void bubble_sort(int* data, int size, bool ascending) {
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if (ascending) {
                if(data[i] > data[j]) {
                    int temp = data[j];
                    data[j] = data[i];
                    data[i] = temp; 
                }
            }
            else {
                if(data[i] < data[j]) {
                    int temp = data[j];
                    data[j] = data[i];
                    data[i] = temp; 
                }
            }
        }
    }
    return;
}