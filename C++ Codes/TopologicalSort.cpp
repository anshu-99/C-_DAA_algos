#include<iostream>
using namespace std;

void find_indegree(int adj_matrix[100][100], int indegree[100], int n) {
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += adj_matrix[i][j];
        indegree[j] = sum;
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    int adj_matrix[100][100], indegree[100], s[100], top = -1, res[100];
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> adj_matrix[i][j];
    }
    find_indegree(adj_matrix, indegree, n);
    cout << "Indegree: ";
    for (int i = 0; i < n; i++)
        cout << indegree[i] << " ";

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            s[++top] = i;
    }

    int curr, j, k = 0;
    while (top != -1) {
        curr = s[top--];
        res[k++] = curr;
        for (j = 0; j < n; j++) {
            if (adj_matrix[curr][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0)
                    s[++top] = j;
            }
        }
    }

    cout << "\nTopological sorting: ";
    for (int i = 0; i <n; i++){
    	cout << res[i] << " ";
	}
    return 0;
}

