#include <filesystem>

#include <sourcepp/FS.h>
#include <vcryptpp/vcryptpp.h>

using namespace sourcepp;
using namespace vcryptpp;

int main(const int argc, const char* const argv[]) {
	for (int i = 1; i < argc; i++) {
		std::filesystem::path path{argv[i]};

		if (const auto ext = path.extension().string(); ext == ".ttf") {
			fs::writeFileBuffer(path.replace_extension(".vfont").string(), VFONT::encrypt(fs::readFileBuffer(argv[i])));
		} else if (ext == ".vfont") {
			fs::writeFileBuffer(path.replace_extension(".ttf").string(), VFONT::decrypt(fs::readFileBuffer(argv[i])));
		}
	}
	return 0;
}
