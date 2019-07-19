#include<experimental/filesystem>
using namespace std;
namespace fs = experimental::filesystem;

int main()
{
	fs::rename("j.data", "src/j.data");
}

