#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include<string>
#include <algorithm>
using namespace std;
//descending compare
bool int_compare(int a, int b) { return (a > b); }

int main() {
	int arr[10] = { 0, };
	printf("%d",1[arr]);
	std::string a;
	a = "123";
	a[0] = '2';
	printf("%c", a[0]);
	//initiallize like C array
	//have to determine the vector type in compile time
	int int_array[11] = { 0, };
	std::vector<int> int_vec = { 0, };
	//can reserve the vector memory
	int_vec.reserve(100);

	for (int i = 1; i <= 10; ++i) {
		//add element in vector
		//capacity of vector is changed in runtime
		int_vec.push_back(i);
	}

	for (std::vector<int>::iterator it = int_vec.begin();
		it != int_vec.end(); ++it) {
		/*
		* similar feature like pointer access
		* iterator used in modify the whole vector
		* like std::sort, std::copy
		*/
		std::cout << *it << std::endl;
	}

	for (auto it = int_vec.begin();
		it != int_vec.end(); ++it) {
		std::cout << *it << std::endl;
	}

	for (int i = 0; i < int_vec.size(); ++i) {
		//same access like array
		std::cout << int_vec[i] << std::endl;
	}

	for (int i : int_vec) {
		/*
		* C++11 new feature!!
		* range based for loop
		* loop all element in vector
		* but it's copy operation. you can't change
		* original vector value
		*/
		std::cout << i << std::endl;
	}

	for (int &i : int_vec) {
		//you can change value by adding reference
		i += 1;
	}

	struct myType {
		int a;
		float b;
		std::string c;
	};

	//user defined type can be used the type of vector
	std::vector<myType> myType_vec;

	myType mt;
	mt.a = 3;
	mt.b = 3.0f;
	mt.c = "adsf";

	//push_back is copy operation
	myType_vec.push_back(mt);

	/**
	* it's C++11 new feature!
	* you can call constructor when append the elem
	* it may be faster when append large size type
	**/
	myType_vec.emplace_back(mt);

	std::vector<int> rand_ascend_vec = { 3, 5, 4, 1, 9, 0 };
	/*
	* sort the stl containters.
	* default sort policy is ascending
	* mostly std::sort implementation is Quick Sort
	* it's time complexity is O( N log(N) )
	*/
	std::sort(rand_ascend_vec.begin(), rand_ascend_vec.end());
	std::vector<int> rand_descend_vec = { 3, 5, 4, 1, 9, 0 };
	/*
	* you can use own compare function
	* useful in compare struct or class
	*/
	std::sort(rand_descend_vec.begin(), rand_descend_vec.end(), int_compare);

	std::vector<int> rand_vec = { 3, 5, 4, 1, 9, 0 };
	/*
	* C++11 new feature!!
	* you can use lambda function in compare function
	*/
	std::sort(rand_vec.begin(), rand_vec.end(),
		[](int a, int b) { return (a > b); });

	std::string sample = "kim hyeonseok S2";
	/*
	* STL key value storage
	* std::map implementation is red-black tree
	* you can access element in O( Log N )
	*/
	std::map<char, int> str_table;
	for (char c : sample) {
		//check key is exist
		if (str_table.find(c) == str_table.end()) {
			//if not exist
			str_table.insert(std::make_pair(c, 1));
			//also you can insert like this
			//str_table[c] = 1;
		}
		else {
			//exist increase value
			str_table[c] += 1;
		}
	}

	for (auto it = str_table.begin();
		it != str_table.end(); ++it) {
		/*
		* map return std::pair object
		* it->first is key
		* it->second is value
		*/
		std::cout << it->first << " : "
			<< it->second << std::endl;
	}

	/*
	* STL key value storage
	* std::unordered_map implementation is hash_map
	* lookup time complexity is O( 1 )
	* same uses like map
	*/
	std::unordered_map<char, int> unordered_ex;

	/*
	* STL string container
	* very useful easy to append or changing string
	*/
	char str[] = "Hello! I'm String";
	std::string sstr = str;
	std::string sstr1 = "Heelo";

	//append string
	std::string sum_sstr = sstr1 + sstr;
	std::cout << sum_sstr << std::endl;
	std::cout << sum_sstr.length() << std::endl;

	//compare string
	std::string cs1 = "a";
	std::string cs2 = "ab";
	cs1 += "b";
	if (cs1 == cs2) {
		std::cout << "cs1 and cs2 is same!!" << std::endl;
	}
	while (1);
}

