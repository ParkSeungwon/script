#include<algorithm>
#include<experimental/filesystem>
using namespace std;
using namespace std::experimental::filesystem;

int main(int ac, char** av)
{
	const char* p = ac < 2 ? "." : av[1];
	vector<directory_entry> v;
	for(auto& a : directory_iterator{p}) v.push_back(a);
	sort(v.begin(), v.end(), [](directory_entry a, directory_entry b) {
			return last_write_time(a) > last_write_time(b); });

	stringstream ss;
	ss << "gvim -p ";
	for(auto& a : v) ss << a << ' ';
	return system(ss.str().data());
}
