class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::array<int, 26> freq{0};
        int to_process = 0;
        for(const auto &c:tasks) {
            int idx = c - 'A';
            freq[idx]++;
            to_process++;
        }

        priority_queue<pair<int, char>> pq{};
        for(int i=0;i<26;i++) {
            if(freq[i] > 0) {
                pq.push({freq[i], 'A' + i});
            }
        }

        int cycles = 0;

        queue<pair<pair<char, int>, int>> waiting{};
        std::vector<char> order{};
        while(to_process > 0) {
            
            while(!waiting.empty() and waiting.front().second <= cycles) {
                auto [task, allowed_cycle] = waiting.front();
                waiting.pop();
                pq.push({task.second, task.first}); 
            }

            char curr_to_process = pq.empty() ? '-' : pq.top().second;
            if(curr_to_process != '-') {
                auto [freq, task] = pq.top();
                pq.pop();
                if(freq > 1) {
                    waiting.push({{task, --freq}, cycles+n+1});
                }
                to_process--;
            } 
            // order.push_back(curr_to_process);
            cycles++;
        }

        // for(const auto &c:order) {
        //     std::cout << c << ",";
        // }
        // std::cout << "\n";
        return cycles;

    }
};
