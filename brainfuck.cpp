#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>

class Brainfuck {
	public:
		char* cpu = NULL;
		int i;
		std::ifstream file;
		std::string str;
		Brainfuck(std::string tmp) {
			cpu = new char[30000];
			i = 0;
			memset(cpu, 0, sizeof(cpu));
			file.open(tmp.c_str());
			if (!file.is_open()) {
				std::cout << "Cannot open file" << std::endl;
				exit(0);
			}
		}
		~Brainfuck() {
			delete[] cpu;
		}
		void compile() {
			while(!file.eof()) {
				getline(file, str);
				unsigned int a = 0;
				int b = 0;
				for (int j = 0; j < str.length(); j++) {
					if (str[j] == '>')
						a++;
					if (str[j] == '<')
						a--;
					if (str[j] == '+')
						cpu[a]++;
					if (str[j] == '-')
						cpu[a]--;
					if (str[j] == '.')
						std::cout << cpu[a];
					if (str[j] == ',')
						std::cin >> cpu[a];
					if (str[j] == '[') {
						if (!cpu[a]) {
							++b;
							while (b) {
								++j;
								if (str[j] == '[')
									++b;
								if (str[j] == ']')
									--b;
							}
						}
						else
							continue;
					}
					else if (str[j] == ']') {
						if (!cpu[a])
							continue;
						else {
							if (str[j] == ']')
								b++;
							while (b) {
								--j;
								if (str[j] == '[')
									b--;
								if (str[j] == ']')
									b++;
							}
							--j;
						}
					}
				}
			}
		}
		void printAll() {
			unsigned int a = 0;
			for (int i = 0; i < 256; i++) {
				std::cout << i << ": " << cpu[a] << std::endl;
				cpu[a]++;	
			}
		}
};

class Compiler {
	public:
		int i = 0;
		char* cpu = NULL;
		std::string str;
		Compiler() {
			std::cout << "Brainfuck compiler by KingleyStudio" << std::endl;
			cpu = new char[30000];
			i = 0;
			memset(cpu, 0, sizeof(cpu));
		}
		~Compiler() {
			delete[] cpu;
		}
		void compile() {
			unsigned int a = 0;
			int b = 0;
			while (true) {
				std::cout << std::endl << ">>> ";
				std::cin >> str;
				for (int j = 0; j < str.length(); j++) {
					if (str[j] == '>')
						a++;
					if (str[j] == '<')
						a--;
					if (str[j] == '+')
						cpu[a]++;
					if (str[j] == '-')
						cpu[a]--;
					if (str[j] == '.')
						std::cout << cpu[a];
					if (str[j] == ',')
						std::cin >> cpu[a];
					if (str[j] == '[') {
						if (!cpu[a]) {
							++b;
							while (b) {
								++j;
								if (str[j] == '[')
									++b;
								if (str[j] == ']')
									--b;
							}
						}
						else
							continue;
					}
					else if (str[j] == ']') {
						if (!cpu[a])
							continue;
						else {
							if (str[j] == ']')
								b++;
							while (b) {
								--j;
								if (str[j] == '[')
									b--;
								if (str[j] == ']')
									b++;
							}
							--j;
						}
					}
				}	
			}
		}
};

int main(int argc, char *argv[]) {
	if (argc == 1) {
		Compiler compiler;
		compiler.compile();
	}
	else {
		Brainfuck bf(argv[1]);
		bf.compile();
	}
	return 0;
}
