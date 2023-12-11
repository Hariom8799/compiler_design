#include<bits/stdc++.h>
using namespace std;


int main() {
    
    string inputText = R"(
        #include <bits/stdc++.h>
        using namespace std;

        void merge(vector<string> &vec, int s, int e) {
            int mid = (s + e) / 2;

            int len1 = mid - s + 1;
            int len2 = e - mid;

            vector<string> vec1(len1);
            vector<string> vec2(len2);

            int ind = s;
            for (int i = 0; i < len1; i++) {
                vec1[i] = vec[ind++];
            }

            ind = mid + 1;
            for (int i = 0; i < len2; i++) {
                vec2[i] = vec[ind++];
            }

            int index1 = 0;
            int index2 = 0;
            ind = s;

            while (index1 < len1 && index2 < len2) {
                if (vec1[index1] > vec2[index2]) {
                    vec[ind++] = vec2[index2++];
                } else {
                    vec[ind++] = vec1[index1++];
                }
            }

            while (index1 < len1) {
                vec[ind++] = vec1[index1++];
            }
            while (index2 < len2) {
                vec[ind++] = vec2[index2++];
            }
        }

        void mergeSort(vector<string> &vec, int s, int e) {
            if (s >= e) {
                return;
            }
            int mid = (s + e) / 2;

            mergeSort(vec, s, mid);
            mergeSort(vec, mid + 1, e);

            merge(vec, s, e);
        }

        int main() {
            vector<string> arr = {"22", "54", "11", "32", "14", "12"};
            mergeSort(arr, 0, 5);

            for (int i = 0; i < 6; i++) {
                cout << arr[i] << " ";
            }

            return 0;
        }
    )";

    // Create a vector to store the tokens
    std::vector<std::string> tokens;

    // Use a stringstream to tokenize the input text
    std::istringstream tokenStream(inputText);
    std::string token;

    while (std::getline(tokenStream, token, ' ')) {
        // Add the token to the vector
        tokens.push_back(token);
    }

    // Print the tokens
    for (const std::string& t : tokens) {
        std::cout << t << std::endl;
    }

    return 0;
}
