#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h> 

struct rgb {
	int r;
	int g;
	int b;
};

class Sort
{
private:
	//Data
	SDL_Renderer* render = nullptr;
	SDL_Window* window = nullptr;
	//Important Methodes
	void swap(int& x, int& y);
	void draw(int elem, int ind, int option);
	void draw_default(std::vector<int> vec);
	void draw_changed_color(std::vector<int> vec, int from, int to);
	void draw_changed_color_HEAP(std::vector<int> vec, int from, int to);
	//MergeSort Utils 
	void ms(std::vector<int>& vec, int u, int v);
	void merge(std::vector<int>& vec, int u, int m, int v);
	//QuickSort Utils 
	void QuickSort(std::vector<int>& vec, int p, int r);
	int partition(std::vector<int>& vec, int p, int r);
	//HeapSort Utils
	void buildMaxHeap(std::vector<int>& vec);
	void sink(std::vector<int>& vec, int k, int n);
public:
	//Constructor
	Sort(SDL_Renderer* r, SDL_Window* w) : render(r), window(w) {}
	//Data Utils
	int option = 0;
	rgb background = {0,0,0};
	rgb data_column = {255,0,0};
	bool color_has_changed = false;
	//Sorting Main Methodes
	void BubbleSort(std::vector<int> vec);
	void MaxSelectionSort(std::vector<int> vec);
	void MinSelectionSort(std::vector<int> vec);
	void InsertionSort(std::vector<int> vec);
	void MergeSort(std::vector<int> vec);
	void QuickSort(std::vector<int> vec);
	void HeapSort(std::vector<int> vec);
	void ShellSort(std::vector<int> vec);
};
