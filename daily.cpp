#include<chrono>
#include<vector>
#include<fstream>
using namespace std;
using cl = std::chrono::system_clock;

struct Batch {
	int interval;
	long executed_time_t;
	string command;
} batch;

int main() {
	vector<Batch> v;
	string init_file = getenv("HOME"); init_file += "/.mycron";
	for(ifstream f{init_file}; f >> batch.interval >> batch.executed_time_t;) {
		getline(f, batch.command);
		if(cl::now() - cl::from_time_t(batch.executed_time_t) > batch.interval * 1h) {
			system(batch.command.data());
			batch.executed_time_t = cl::to_time_t(cl::now());
		}
		v.push_back(batch);
	}
	ofstream f{init_file};
	for(auto [i, t, c] : v) f << i << ' ' << t << c << '\n';
}
