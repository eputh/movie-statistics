//
// Name: Emily Puth
// ID: 28239807
//
// Movie statistics is a program that gathers statistical data
// about the number of movies college students see in a month.

#ifndef MOVIE_STATISTICS_HPP_
#define MOVIE_STATISTICS_HPP_

#include <iostream>
#include <fstream>

// sorts the array from smallest value to largest value
void sortArray (int *arr, int size);

// Calculates the average of the values in the dataset
float calculateAverage(int *arr, int size);

// Calculates the median of the values in the dataset
float calculateMedian(int *arr, int size);

// Calculates the mode of the values in the dataset
int calculateMode(int *arr, int size);

// Asks the user how many students were surveyed
// and how many movies each student saw. Calculates
// and writes the statistics to a file.
void gatherData();


#endif /* MOVIE_STATISTICS_HPP_ */
