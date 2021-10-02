/*
 *  https://blog.naver.com/jinhan814/222400578937
 */

#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/mman.h>
using namespace std;

int main() {
	struct stat st; fstat(0, &st);
	char* p = (char*)mmap(0, st.st_size, PROT_READ, MAP_SHARED, 0, 0);
	auto ReadInt = [&]() {
		int ret = 0;
		for (char c = *p++; c & 16; ret = 10 * ret + (c & 15), c = *p++);
		return ret;
	};
	auto ReadSignedInt = [&]() {
		int ret = 0; char c = *p++, flag = 0;
		if (c == '-') c = *p++, flag = 1;
		for (; c & 16; ret = 10 * ret + (c & 15), c = *p++);
		return flag ? -ret : ret;
	};
}