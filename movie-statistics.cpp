//
// Name: Emily Puth
// ID: 28239807
//

#include "movie-statistics.hpp"


void sortArray(int *arr, int size) {
	for (int i=0; i<size; i++)
		for (int p=i+1; p<size; p++)
			if (arr[i] > arr[p]) {
				int temp = arr[i];
				arr[i] = arr[p];
				arr[p] = temp;
			}
}

float calculateAverage(int *arr, int size) {
	float total = 0;
	for (int i=0; i<size; i++)
		total += arr[i];
	return total/size;
}

float calculateMedian(int *arr, int size) {
	float median = 0;
	if ((size % 2) == 0) 
		median = float(arr[size/2] + arr[size/2-1])/2;
	else
		median = arr[size/2];
	return median;
}

int calculateMode(int *arr, int size) {
	int mode; // value that is present the most amount of times
	int maxCount = 0; // current max number of times a value is present
	for (int i=0; i<size; i++) {
		int count = 1; // used to count how many times a value is present
		for (int j=i+1; j<size; j--) {
			if (arr[i] == arr[j])
				count++;
			else break;
		}
		if (count > maxCount) {
			maxCount = count;
			mode = arr[i];
		}
	}
	return mode;
}

void gatherData() {
	int surveyed; // number of students surveyed
	std::cout << "How many students were surveyed? ";
	std::cin >> surveyed;
	if (surveyed > 0) {
		int *arr = new int[surveyed];
		for (int i=0; i<surveyed; i++) {
			std::cout << "How many movies has Student " << i+1 << " seen? ";
			std::cin >> arr[i];
		}
	
		// Calculate the statistics
		sortArray(arr, surveyed); 
		float average = calculateAverage(arr, surveyed);
		float median = calculateMedian(arr, surveyed);
		int mode = calculateMode(arr, surveyed);
		
		// Write the statistics to a file named movieStats.txt
		std::ofstream myfile("movieStats.txt");
		myfile << "Average: " << average << std::endl;
		myfile << "Median: " << median << std::endl;
		myfile << "Mode: " << mode << std::endl;
		myfile.close();
	}
	else {
		std::cout << "Error: please enter a value greater than 0." << std::endl;
		gatherData();
	}
}


int main() {
	gatherData();
}
