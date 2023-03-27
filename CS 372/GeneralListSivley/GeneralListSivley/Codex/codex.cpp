#ifndef codex
#define codex

void errPrint(const char* payload) {
	cerr << "\x1b[31m" << payload << "\x1b[0m";
	return;
}