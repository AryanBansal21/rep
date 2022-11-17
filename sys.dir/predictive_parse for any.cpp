#include<bits/stdc++.h>
using namespace std;

// Symbols
string S = "S";
string A = "A";
string B = "B";
string eps = "";
string a = "a";
string b = "b";

map<string, map<string, vector<string>>> table;


// bas grammar ke according table change kr lena

void fill_table() {
	table[S][a] = {b, A, a, A};
	table[S][b] = {a, B, b, B};

	table[A][a] = {eps};
	table[A][b] = {eps};

	table[B][a] = {eps};
	table[B][b] = {eps};
}

int len = 0;

void print(vector<string> st, vector<string> input, string msg) {
	string st1, inp;
	for (auto el : st) {
		st1 += el;
		st1 += " ";
	}
	for (int i = input.size() - 1; i >= 0; i--) {
		inp += input[i];
	}
	cout << setw(4) << left << " ";
	cout << setw(4 * len) << left << st1;
	cout << setw(len) << right << inp;
	cout << setw(4) << left << " ";
	cout << setw(10) << left << msg;
	cout << endl;
}

string stringify(char c) {
	string s;
	s.push_back(c);
	return s;
}

int main() {

	fill_table();

	cout << "Enter the string to be parsed : ";
	vector<string> input;

	string s;
	cin >> s;

	len = s.size() + 5;

	for (auto i : s) input.push_back(stringify(i));
	input.push_back("$");
	reverse(input.begin(), input.end());

	vector<string> st;

	st.push_back("$");
	st.push_back(S);

	cout << setw(4) << left << " ";
	cout << setw(4 * len) << left << "STACK";
	cout << setw(len) << right << "INPUT";
	cout << setw(4) << left << " ";
	cout << setw(10) << left << "COMMENTS";
	cout << endl;

	string message = "";
	while (input.size() > 0) {

		while (st.back() == eps) st.pop_back();

		vector<string> old_st = st, old_input = input;

		string c_in = input.back();
		string c_st = st.back();

		message = "";

		if (c_in == c_st && c_in == "$") {
			message = "Accepted";
			print(old_st, old_input, message);
			break;
		}

		if (c_in == c_st) {
			st.pop_back();
			input.pop_back();
		} else if (table[c_st][c_in].size() == 0) {
			message = "Error";
			print(old_st, old_input, message);
			break;
		} else {
			st.pop_back();
			for (auto i : table[c_st][c_in]) st.push_back(i);
		}


		print(old_st, old_input, message);
	}

	cout << "\n\n";

	if (message != "Accepted") {
		cout << "Unsuccessful parsing\n";
	} else {
		cout << "Successful parsing\n";
	}

	cout << "\n\n";
}


