#include "Sort.h"

void Sort::draw_default(std::vector<int> vec) {
	SDL_SetRenderDrawColor(render, background.r, background.g, background.b, 255);
	SDL_Rect table = { 0,100,1000,700 };
	SDL_RenderFillRect(render, &table);

	SDL_SetRenderDrawColor(render, data_column.r, data_column.g, data_column.b, 255);
	for (int i = 0; i < 100; i++) {
		double height = vec[i] / 100.0;
		SDL_Rect line = { 0 + i * 10, (int)(800 - 700 * height), 8, (int)(700 * height) };
		SDL_RenderFillRect(render, &line);
	}
	SDL_RenderPresent(render);
}

void Sort::draw_changed_color(std::vector<int> vec, int from, int to) {
	SDL_SetRenderDrawColor(render, background.r, background.g, background.b, 255);
	for (int i = 0; i < 100; i++) {
		double height = vec[i] / 100.0;
		SDL_Rect table = { 0 + i * 10, 100, 8, (int)(700 - 700 * height) };
		SDL_RenderFillRect(render, &table);
	}

	SDL_SetRenderDrawColor(render, data_column.r, data_column.g, data_column.b, 255);
	for (int i = from; i < to; i++) {
		double height = vec[i] / 100.0;
		SDL_Rect line = { 0 + i * 10, (int)(800 - 700 * height), 8, (int)(700 * height) };
		SDL_RenderFillRect(render, &line);
	}
	SDL_RenderPresent(render);
}

void Sort::draw_changed_color_HEAP(std::vector<int> vec, int from, int to) {
	SDL_SetRenderDrawColor(render, background.r, background.g, background.b, 255);
	for (int i = 1; i <= 100; i++) {
		double height = vec[i] / 100.0;
		SDL_Rect table = { 0 + (i - 1) * 10, 100, 8, (int)(700 - 700 * height) };
		SDL_RenderFillRect(render, &table);
	}

	SDL_SetRenderDrawColor(render, data_column.r, data_column.g, data_column.b, 255);
	for (int i = from; i < to; i++) {
		double height = vec[i] / 100.0;
		SDL_Rect line = { 0 + (i - 1) * 10, (int)(800 - 700 * height), 8, (int)(700 * height) };
		SDL_RenderFillRect(render, &line);
	}
	SDL_RenderPresent(render);
}

void Sort::draw(int elem, int ind, int option) {
	SDL_SetRenderDrawColor(render, background.r, background.g, background.b, 255);
	SDL_Rect line = { ind * 10, 100, 8, 700 };
	SDL_RenderFillRect(render, &line);

	option == 0 ? SDL_SetRenderDrawColor(render, data_column.r, data_column.g, data_column.b, 255) : SDL_SetRenderDrawColor(render, 255, 255, 0, 255);
	double height = elem / 100.0;
	SDL_Rect line2 = { ind * 10, (int)(800 - 700 * height), 8, (int)(700 * height) };
	SDL_RenderFillRect(render, &line2);
}

void Sort::swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

//--------------------------------------------------------------BubbleSort--------------------------------------------------------------//
void Sort::BubbleSort(std::vector<int> vec) {
	draw_default(vec);
	SDL_RenderPresent(render);

	for (int i = (int)vec.size() - 1; i >= 1 && option == 1; i--) {
		for (int j = 0; j <= i - 1 && option == 1; j++) {
			if (color_has_changed) {
				color_has_changed = false;
				draw_changed_color(vec, 0, i + 1);
			}
			if (vec[j] > vec[j + 1]) {
				swap(vec[j], vec[j + 1]);
				draw(vec[j], j, 0);
				draw(vec[j + 1], j + 1, 1);
			}
			else {
				draw(vec[j], j, 0);
				draw(vec[j + 1], j + 1, 1);
			}
			SDL_RenderPresent(render);
		}
	}
}
//--------------------------------------------------------------MaxSelectionSort--------------------------------------------------------------//
void Sort::MaxSelectionSort(std::vector<int> vec) {
	draw_default(vec);
	SDL_RenderPresent(render);

	for (int i = (int)vec.size() - 1; i > 0 && option == 2; i--) {
		int ind = 0;
		for (int j = 1; j <= i && option == 2; j++) {
			if (vec[j] > vec[ind]) {
				ind = j;
			}
			if (color_has_changed) {
				color_has_changed = false;
				draw_changed_color(vec, 0, i);
			}
		}
		if (ind != i) {
			swap(vec[i], vec[ind]);
			draw(vec[i], i, 1);
			draw(vec[ind], ind, 0);
		}
		else {
			draw(vec[i], i, 1);
		}
		SDL_RenderPresent(render);
		SDL_Delay(75);
	}
	if (option == 2) {
		draw(vec[0], 0, 1);
		SDL_RenderPresent(render);
	}
}
//--------------------------------------------------------------MinSelectionSort--------------------------------------------------------------//
void Sort::MinSelectionSort(std::vector<int> vec) {
	draw_default(vec);
	SDL_RenderPresent(render);

	for (int i = 0; i < (int)vec.size() - 1 && option == 3; i++) {
		int ind = vec.size() - 1;
		for (int j = vec.size() - 2; j >= i && option == 3; j--) {
			if (vec[j] < vec[ind]) {
				ind = j;
			}
			if (color_has_changed) {
				color_has_changed = false;
				draw_changed_color(vec, i, (int)vec.size());
			}
		}
		if (ind != i) {
			swap(vec[i], vec[ind]);
			draw(vec[i], i, 1);
			draw(vec[ind], ind, 0);
		}
		else {
			draw(vec[i], i, 1);
		}
		SDL_RenderPresent(render);
		SDL_Delay(75);
	}
	if (option == 3) {
		draw(vec[(int)vec.size() - 1], (int)vec.size() - 1, 1);
		SDL_RenderPresent(render);
	}
}
//--------------------------------------------------------------InsertionSort--------------------------------------------------------------//
void Sort::InsertionSort(std::vector<int> vec) {
	draw_default(vec);
	draw(vec[0], 0, 1);
	SDL_RenderPresent(render);

	for (int i = 1; i < (int)vec.size() && option == 4; i++) {
		if (vec[i - 1] > vec[i]) {
			int x = vec[i];
			vec[i] = vec[i - 1];
			draw(vec[i], i, 1);
			int j = i - 2;
			while (option == 4 && j > -1 && vec[j] > x) {
				vec[j + 1] = vec[j];
				draw(vec[j + 1], j + 1, 1);
				j--;
				if (color_has_changed) {
					color_has_changed = false;
					draw_changed_color(vec, i, vec.size());
				}
			}
			vec[j + 1] = x;
			draw(vec[j + 1], j + 1, 1);
		}
		else {
			draw(vec[i], i, 1);
		}
		SDL_RenderPresent(render);
		SDL_Delay(50);
	}
}
//--------------------------------------------------------------MergeSort--------------------------------------------------------------//
void Sort::MergeSort(std::vector<int> vec) {
	draw_default(vec);
	SDL_RenderPresent(render);
	ms(vec, 0, vec.size());
}

void Sort::ms(std::vector<int>& vec, int u, int v) {
	if (option == 5) {
		if (u < v - 1) {
			int m = (u + v) / 2;
			ms(vec, u, m);
			ms(vec, m, v);
			merge(vec, u, m, v);
		}
		else {
			draw(vec[u], u, 1);
			SDL_RenderPresent(render);
		}
	}
}

void Sort::merge(std::vector<int>& vec, int u, int m, int v) {
	int d = m - u;
	std::vector<int> Z;
	for (int i = 0; i < d && option == 5; i++) {
		Z.push_back(vec[u + i]);
	}
	int k = u;
	int j = 0;
	int i = m;
	while (option == 5 && i < v && j < d) {
		if (vec[i] < Z[j]) {
			vec[k] = vec[i];
			draw(vec[k], k, 1);
			i = i + 1;
		}
		else {
			vec[k] = Z[j];
			draw(vec[k], k, 1);
			j = j + 1;
		}
		if (color_has_changed) {
			color_has_changed = false;
			draw_changed_color(vec, k, vec.size());
		}
		k = k + 1;
		SDL_RenderPresent(render);
	}
	while (option == 5 && j < d) {
		vec[k] = Z[j];
		draw(vec[k], k, 1);
		if (color_has_changed) {
			color_has_changed = false;
			draw_changed_color(vec, k, vec.size());
		}
		SDL_RenderPresent(render);
		j++;
		k++;
	}
}
//--------------------------------------------------------------QuickSort--------------------------------------------------------------//
void Sort::QuickSort(std::vector<int> vec) {
	draw_default(vec);
	SDL_RenderPresent(render);
	QuickSort(vec, 0, vec.size() - 1);
}

void Sort::QuickSort(std::vector<int>& vec, int p, int r) {
	if (option == 6) {
		if (p < r) {
			int q = partition(vec, p, r);
			QuickSort(vec, p, q - 1);
			QuickSort(vec, q + 1, r);
		}
		else if (p >= 0 && p <= 99) {
			draw(vec[p], p, 1);
			SDL_RenderPresent(render);
		}
	}
}

int Sort::partition(std::vector<int>& vec, int p, int r) {
	int i = rand() % (r - p) + p + 1;
	int x = vec[i];
	vec[i] = vec[r];
	draw(vec[i], i, 0);
	SDL_RenderPresent(render);
	i = p;
	while (option == 6 && i < r && vec[i] <= x) {
		i++;
	}
	if (i < r) {
		int j = i + 1;
		while (option == 6 && j < r) {
			if (vec[j] < x) {
				swap(vec[i], vec[j]);
				draw(vec[i], i, 0);
				draw(vec[j], j, 0);
				if (color_has_changed) {
					color_has_changed = false;
					draw_changed_color(vec, p, r);
				}
				SDL_RenderPresent(render);
				i++;
			}
			j++;
		}
		vec[r] = vec[i];
		vec[i] = x;
		draw(vec[r], r, 0);
		draw(vec[i], i, 1);
		SDL_RenderPresent(render);
	}
	else {
		vec[r] = x;
		draw(vec[r], r, 1);
		SDL_RenderPresent(render);
	}
	return i;
}

//--------------------------------------------------------------HeapSort--------------------------------------------------------------//
void Sort::HeapSort(std::vector<int> vec) {
	draw_default(vec);
	SDL_RenderPresent(render);

	std::vector<int> vec_; vec_.push_back(0);
	for (int i = 0; option == 7 && i < (int)vec.size(); i++) {
		vec_.push_back(vec[i]);
	}

	buildMaxHeap(vec_);

	int m = (int)vec_.size() - 1;
	while (option == 7 && m > 1) {
		swap(vec_[1], vec_[m]);
		draw(vec_[1], 0, 0);
		draw(vec_[m], m - 1, 1);
		if (color_has_changed) {
			color_has_changed = false;
			draw_changed_color_HEAP(vec_, 1, m);
		}
		SDL_RenderPresent(render);
		m--;
		sink(vec_, 1, m);
	}
	if (option == 7)
		draw(vec_[1], 0, 1);

}
void Sort::buildMaxHeap(std::vector<int>& vec) {
	int n = (int)vec.size() - 1;
	for (int k = n / 2; option == 7 && k >= 1; k--) {
		if (color_has_changed) {
			color_has_changed = false;
			draw_changed_color_HEAP(vec, 1, vec.size());
		}
		sink(vec, k, n);
	}
}

void Sort::sink(std::vector<int>& vec, int k, int n) {
	int i = k;
	int j = 2 * k;
	bool b = true;
	while (option == 7 && j <= n && b) {
		if (j < n && vec[j + 1] > vec[j]) {
			j++;
		}
		if (vec[i] < vec[j]) {
			swap(vec[i], vec[j]);
			draw(vec[i], i - 1, 0);
			draw(vec[j], j - 1, 0);
			if (color_has_changed && !option) {
				color_has_changed = false;
				draw_changed_color_HEAP(vec, 1, vec.size());
			}
			SDL_RenderPresent(render);
			i = j;
			j = 2 * j;
		}
		else {
			b = false;
		}
	}
}

//--------------------------------------------------------------ShellSort--------------------------------------------------------------//
void Sort::ShellSort(std::vector<int> vec) {
	draw_default(vec);
	SDL_RenderPresent(render);

	int n = vec.size();
	for (int gap = n / 2; option == 8 && gap > 0; gap /= 2)
	{
		for (int i = gap; option == 8 && i < n; i += 1)
		{
			int temp = vec[i];
			if (gap == 1) draw(vec[0], 0, 1);
			int j;
			for (j = i; option == 8 && j >= gap && vec[j - gap] > temp; j -= gap) {
				vec[j] = vec[j - gap];
				if (gap > 1) {
					draw(vec[j], j, 0);
					if (color_has_changed) {
						color_has_changed = false;
						draw_changed_color(vec, 0, vec.size());
					}
				}
				else {
					draw(vec[j], j, 1);
					if (color_has_changed) {
						color_has_changed = false;
						draw_changed_color(vec, j, vec.size());
					}
				}
				SDL_RenderPresent(render);
			}

			vec[j] = temp;
			gap > 1 ? draw(vec[j], j, 0) : draw(vec[j], j, 1);
			SDL_RenderPresent(render);
		}
	}
}