// Problem's Title: Preparing for Xtreme 12.0
// Link: https://csacademy.com/ieeextreme-practice/task/72a7d67e7e18f4f7d033f7f5a5a09bef/

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct book{
    int read_time;
    int bitmask_topics;
};

vector<book> books;
map<string, int> topic_number;
int last_topic_number = 0;
int dp[2][(1<<22)];
int desired;

vector<int> fill_topics(string &s) { // return a vector of integers representing numbers for the topics
    int len = s.length();
    string topic = "";
    vector<int> ans;
    for(int i = 1; i < len; i++)
        if(s[i] == ' ') {
            if (!topic_number[topic])
                topic_number[topic] = ++last_topic_number;
            ans.push_back(topic_number[topic]);
            topic = "";
        }
        else
            topic += s[i];
    if (!topic_number[topic])
        topic_number[topic] = ++last_topic_number;
    ans.push_back(topic_number[topic]);
    return ans;
}

int find_bitmask(vector<int> &v) {
    int ans = 0;
    for(int x:v)
        ans |= (1<<x);
    return ans;
}

int main() {
    string topics;
    int read_time;
    while(cin >> read_time) {
        getline(cin, topics);
        book b;
        b.read_time = read_time;
        vector<int> v = fill_topics(topics);
        b.bitmask_topics = find_bitmask(v);
        books.push_back(b);
    }
    
    desired = (1 << (last_topic_number + 1)) - 2; // 111110 for 5 topics, last bit is not used
    
    // Initialization with 10^9 (infinity)
    for(int i = 0; i < 2; i++)
        for(int bitmask = 0; bitmask <= desired; bitmask++)
            dp[i][bitmask] = 1e9;

    dp[0][0] = 0;                                           // try not to read the first book
    dp[0][books[0].bitmask_topics] = books[0].read_time;    // try to read the first book

    for (int i = 1; i < books.size(); i++) {
        book b = books[i];
        
        // try not to read this book [iterate for all previous bitmasks]
        for(int bitmask = 0; bitmask <= desired; bitmask++)
            dp[i%2][bitmask] = dp[(i-1)%2][bitmask];
        
        // try to read this book [iterate for all previous bitmasks]
        for(int bitmask = 0; bitmask <= desired; bitmask++) {
            int old_answer = dp[i%2][bitmask | b.bitmask_topics]; // bitmask for current book is added
            int new_answer = dp[(i-1)%2][bitmask] + b.read_time;
            if (new_answer < old_answer)
                dp[i%2][bitmask | b.bitmask_topics] = new_answer; // saving best answer for this case
        }
        
    }
    cout << dp[(books.size()-1)%2][desired] << endl;
}
