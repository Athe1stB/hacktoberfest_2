#include<bits/stdc++.h>
using namespace std;

// This function generates the key in
// a cyclic manner until it's length isi'nt
// equal to the length of original text
string generateKey(string str, string key) {
	int x = str.size();

	for (int i = 0; ; i++) {
		if (x == i)
			i = 0;

		if (key.size() == str.size())
			break;

		key.push_back(key[i]);
	}

	return key;
}

string cipherText(string str, string key) {
	string cipher_text;

	for (int i = 0; i < str.size(); i++) {
		char x = (str[i] + key[i]) %26;
		x += 'A';
		cipher_text.push_back(x);
	}

	return cipher_text;
}

int main() {
	string str = "cryptographyandnetworksecurity";
	string keyword = "akshatbaranwal";
	string key = generateKey(str, keyword);
	cout<<key<<"\n";
	string cipher_text = cipherText(str, key);
	cout << "Ciphertext : "
	     << cipher_text << "\n";
	return 0;
}