#include<iostream>
#include<fstream>
using namespace std;
const int MAX = 50;
typedef struct ArrayOneDinension {
	int n;
	int list[MAX];
} A1D;
void InPutN(A1D& m) {
	do {
		cout << "\n Enter a number of array: ";
		cin >> m.n;
	} while (m.n<0 || m.n>MAX);
}
void InPutA1D(A1D& arr) {
	for (int i = 0; i < arr.n; i++) {
		cin >> arr.list[i];
	}
}
void OutPutA1D(A1D arr) {
	for (int i = 0; i < arr.n; i++) {
		cout << arr.list[i]<<" ";
	}
}
int &size(A1D& m) {
	return m.n;
}
bool isprime(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
void Join(A1D& m, A1D& m1, A1D& m2) {// gộp 2 mảng thành 1 mảng
	size(m) = 0;
	for (int i = 0; i < m1.n; i++) {
		m.list[size(m)++] = m1.list[i];
	}
	for (int j = 0; j < m2.n; j++) {
		m.list[size(m)++] = m2.list[j];
	}
}
void DeleteDuplicateElements(A1D& m) {// xóa phần tử trùng
	for (int i = 0; i < m.n-1; i++) {
		for (int j = i + 1; j < m.n; j++) {
			if (m.list[i] == m.list[j]) {
					for (int k = j; k < m.n; k++) {
						m.list[k] = m.list[k + 1];
					}
					m.n--;
					j--;
			}
		}
	}
}
void ArrayIncreasing(A1D &m) {// sắp xếp hàm tăng
	for (int i = 1; i < m.n; i++) {
		if (m.list[i] < m.list[i - 1]) {
			int k = m.list[i];
			m.list[i] = m.list[i - 1];
			m.list[i - 1] = k;
		}
	}
}
void SortDescending(A1D &m) {
	for (int i = 0; i <m.n - 1; i++) {
		for (int j = 0; j < m.n - i - 1; j++) {
			if (m.list[j] < m.list[j + 1]) {
				int temp = m.list[j];
				m.list[j] = m.list[j + 1];
				m.list[j + 1] = temp;
			}
		}
	}
}
int BinarySearch(A1D m) {
	int left= 0, right = m.n-1, x;
	cout << "\n Enter x: ";
	cin >> x;
	do {
		int mid = (left + right) / 2;
		if (m.list[mid] == x) {
			return mid;
		}
		else if (m.list[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	} while (left <= right);
	return -1;
}
int max(A1D m) {
	int mx = 0;
	for (int i = 0; i < m.n; i++) {
		if (m.list[i] >mx) {
			mx = m.list[i];
		}
	}
	return mx;
}
int min(A1D m) {
	int min = m.list[0];
	for (int i = 1; i < m.n; i++) {
		if (m.list[i] < min) {
			min = m.list[i];
		}
	}
	return min;
}
void ArrayInversion(A1D& m) {
	int start = 0,end = m.n-1;
	while (start < end) {
		int temp = m.list[start];
		m.list[start] = m.list[end];
		m.list[end] = temp;
		start++;
		end--;
	}
}
void ArrayPrimeNumber(A1D& m, A1D &m1) {
	size(m1) = 0;
	InPutN(m);
	InPutA1D(m);
	for (int i = 0; i < m.n; i++) {
		if (isprime(m.list[i])) {
			m1.list[m1.n++] = m.list[i];
		}
	}
	OutPutA1D(m1);
}
int main() {
	A1D m,m1;
	ofstream outFile("file.txt");
	//size(m) = 0;
	/*InPutN(m);*/
	/*InPutA1D(m);*/
	//DeleteDuplicateElements(m);
	/*SortDescending(m);*/
	/*ArrayInversion(m);*/
	ArrayPrimeNumber(m,m1);
	/*OutPutA1D(m);*/
	return 0;
}