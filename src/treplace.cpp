#include <iostream>
#include <map>
#include <cassert>
#include <string>
#include <streambuf>
#include <string>
#include "transformer.h"


int main(int argc, char** argv){
	std::ios_base::sync_with_stdio(false);
	auto treeregex = treeregex::parse(argv[1]);
	auto treeregex_r = tree::parse_replacement(argv[2]);

	std::string tree_str((std::istreambuf_iterator<char>(std::cin)), std::istreambuf_iterator<char>());
	if(tree_str[tree_str.length()-1] == '\n'){
		tree_str.pop_back();
	}
	auto tree = tree::parse(tree_str);

	Transformer t;
	t.add(treeregex, treeregex_r);
	t(tree)->print(std::cout); std::cout << '\n';
}
