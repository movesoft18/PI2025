#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main()
{
    setlocale(LC_ALL, "");
    auto curr_dir = fs::current_path();
    int files = 0;
    int dirs = 0;
    size_t size = 0;
    for (auto& p : fs::recursive_directory_iterator(curr_dir))
    {
        auto curr_obj = p.path();
        if (fs::is_regular_file(curr_obj))
        {
            files++;
            size += fs::file_size(curr_obj);
        }
        else if (fs::is_directory(curr_obj))
        {
            dirs++;
        }
    }
    cout << "Папок: " << dirs << endl;
    cout << "Файлов: " << files << endl;
    cout << "Суммарный размер файлов: " << size << endl;
}

