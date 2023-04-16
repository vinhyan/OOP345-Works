// Workshop 9 - Multi-Threading, Thread Class
// process_data.cpp
// 2021/1/5 - Jeevan Pant

#include <fstream>
#include <thread>
#include <vector>
#include "process_data.h"

namespace sdds_ws9 {

	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = 0;
		for (int i = 0; i < size; i++) {
			avg += arr[i];
		}
		avg /= divisor;
	}

	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = 0;
		for (int i = 0; i < size; i++) {
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= divisor;
	}
	ProcessData::operator bool() const {
		return total_items > 0 && data && num_threads>0 && averages && variances && p_indices;
	}

	ProcessData::ProcessData(std::string filename, int n_threads) {  
		// TODO: Open the file whose name was received as parameter and read the content
		//         into variables "total_items" and "data". Don't forget to allocate
		//         memory for "data".
		//       The file is binary and has the format described in the specs.
		std::ifstream file(filename, std::ios::binary);

		file.read((char*)&total_items, sizeof(total_items));

		data = new int[total_items];

		for (auto i = 0; i < total_items; i++) {
			file.read((char*)&data[i], sizeof(data[i]));
		}

		file.close();

		std::cout << "Item's count in file '"<< filename << "': " << total_items << std::endl;
		std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
		          << data[total_items - 3] << ", " << data[total_items - 2] << ", "
		          << data[total_items - 1] << "]\n";

		// Following statements initialize the variables added for multi-threaded 
		//   computation
		num_threads = n_threads; 
		averages = new double[num_threads] {};
		variances = new double[num_threads] {};
		p_indices = new int[num_threads+1] {};
		for (int i = 0; i < num_threads+1; i++)
			p_indices[i] = i * (total_items / num_threads);
	}
	ProcessData::~ProcessData() {
		delete[] data;
		delete[] averages;
		delete[] variances;
		delete[] p_indices;
	}

	// TODO Improve operator() function from part-1 for multi-threaded operation. Enhance the  
	//   function logic for the computation of average and variance by running the 
	//   function computeAvgFactor and computeVarFactor in multile threads. 
	// The function divides the data into a number of parts, where the number of parts is 
	//   equal to the number of threads. Use multi-threading to compute average-factor for 
	//   each part of the data by calling the function computeAvgFactor. Add the obtained 
	//   average-factors to compute total average. Use the resulting total average as the 
	//   average value argument for the function computeVarFactor, to compute variance-factors 
	//   for each part of the data. Use multi-threading to compute variance-factor for each 
	//   part of the data. Add computed variance-factors to obtain total variance.
	// Save the data into a file with filename held by the argument fname_target. 
	// Also, read the workshop instruction.

	int ProcessData::operator()(std::string filename, double& avg, double& var) {

		std::vector<std::thread> t;
		//int num_threads = 10;
		int chunk = total_items / num_threads;
		double temp_avg{};
		//averages = new double[num_threads];
		auto compAvg = std::bind(computeAvgFactor, std::placeholders::_1, std::placeholders::_2, total_items, std::placeholders::_3);
		//avg = 0;
		for (auto i = 0; i < num_threads; i++) {
			t.push_back(std::thread(compAvg, data, p_indices[i] + chunk, std::ref(averages[i])));
	
		}

		for (auto& x : t) {
			x.join();
		}

		avg = averages[num_threads - 1];

		std::vector<std::thread> tv;
		double temp_var{};
		auto compVar = std::bind(computeVarFactor, std::placeholders::_1, std::placeholders::_2, total_items, avg, std::placeholders::_3);

		for (auto i = 0; i < num_threads; i++) {
			tv.push_back(std::thread(compVar, data, p_indices[i] + chunk, std::ref(variances[i])));
			//variances[i] = temp_var;
		}

		for (auto& x : tv) {
			x.join();
		}

		var = variances[num_threads - 1];

	


	/*	std::thread t1(computeAvgFactor, first, (total_items/2), total_items, avg1);
		std::thread t2(computeAvgFactor, half, (total_items/2), total_items, avg2);
		t1.join();
		t2.join();

		avg = avg1 + avg2;*/



		std::ofstream file(filename, std::ios::binary);

		file.write((const char*)&total_items, sizeof(total_items));
		for (auto i = 0; i < total_items; i++) {
			file.write((const char*)&data[i], sizeof(data[i]));
		}

		return 0;
	}


}