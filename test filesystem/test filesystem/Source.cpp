#include <fstream>
#include <iostream>
#include <filesystem>
using namespace std;
using namespace std::tr2::sys;

int main()
{
	auto pp = std::tr2::sys::current_path<path>();
	cout << pp.file_string() << endl;
	
	create_directories(path("school"));
	std::ofstream f("school/file3.dat");
	f << "some text for school" <<std:: endl;;
	
	/*try
	{
		if (!exists(path("some.txt")))
			copy_file(path("school/file1.txt"), path("some.txt"));
		else
			copy_file(path("school/file1.txt"), path("some1.txt"));
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}*/


	//replace_extension( path("school/file3.dat"), ".txt");// NOT works
	//for (auto& p : recursive_directory_iterator(path("school")))
	//	std::cout << p << '\n';
	//
	////remove_all(path("school"));
	
	for (recursive_directory_iterator next(path(".")), end; next != end; ++next)
	{
		cout << next->path() << endl;
		if (next->path().extension() == ".txt")
			cout << "OK" << endl;
		if (next->path().empty())
			cout << "EMPTY" << endl;
	}
	
}